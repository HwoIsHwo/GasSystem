clear;
clc;


%% Ток соленоида
I_CS = readmatrix('I_CS.txt');
I_CS = timeseries(I_CS(:, 2), I_CS(:, 1));


%% Длина хорды измерения
L = readmatrix('L_chord.txt');
L = timeseries(L(:,2), L(:,1));


%% Данные с канала mbi
mbi = readmatrix('mbi.txt');
t = mbi(:,1);
mbi = mbi(:,2);

%без сглаживания
% figure;
% plot(t, mbi);
% grid on;
% hold on;

%сглаженные
w = 3000;%величина окна
mbi = smoothdata(mbi, 'movmean', w);
% plot(t, mbi, 'LineWidth', 2);
% legend('Данные без сглаживания', 'Сглаженные данные');
% hold on;

%без постоянного уровня
w = 30000;%количество начальных точек
avg = mean(mbi(1:w));
mbi = mbi - avg;
mbi(mbi < 0) = 0;
% figure;
% plot(t, mbi);
% grid on;
% hold on;

k = 1.02415e19; %коэффициент для канала
mbi = mbi * k;
mbi = timeseries(mbi, t);


%% Пересчет в плотность плазмы
open_system('add.slx');
sim('add.slx');
close_system('add.slx');

t_nP = ans.nP.Time;
nP = ans.nP.Data;
nP(isnan(nP)) = 0;
nP(isinf(nP)) = 0;
w = 64;%величина окна
nP = smoothdata(nP, 'movmedian', w);

% figure;
% plot(t_nP, nP);
% grid on;


%% Доп газонапуск
gas = readmatrix('gas.txt');
t = gas(:,1);
gas = gas(:,2);
gas = gas .* 2;
gas(gas<0) = 0;
gas = timeseries(gas, t);


%% Настройка параметров модели
a_CS = 1e18; %параметр для блока CS
b = 0.1; %параметр бетта
L = 1e-6; %индуктивность плазмы
t = 0.1; %энергетическое время жизни плазмы
trold = 1e14; %порог измерения плотности
Nw0 = 1e22; %начальное количество частиц на стенке
Nv0 = 2.25e18; %начальное количество частиц в ВК
t_e = 1e13; %коэффициент теплообмена
global par0;
par0 = [a_CS, b, L, t, trold, Nw0, Nv0, t_e];


%% Подбор параметров
n = 10;
in_file = zeros(n, length(par0));
err = sum(nP.^2);
u = 1;
open_system('ModelBlocks.slx');
for i=1:10
    old = par0;
    levenberg(@model_start, nP, [1e-10 u]);
    nP_model = model_start();
    err_new = sum((nP - nP_model).^2);

    if err_new <= err
        u = u/10;
        err = err_new;
    else
        u = u*10;
        par0 = old;
    end

    in_file(i, :) = par0;

    if mod(i, 10) == 0
        writematrix(in_file, 'par.txt');
    end
end
close_system('ModelBlocks.slx');


%% Запуск моделирования
open_system('ModelBlocks.slx');
nP_model = model_start();
close_system('ModelBlocks.slx');
figure;
plot(t_nP, nP_model, t_nP, nP);
grid on;