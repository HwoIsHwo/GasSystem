clear;
clc;
addpath('Данные\');


%% Ток соленоида
I_CS = readmatrix('I_CS.txt');
figure;
plot(I_CS(:, 1), I_CS(:, 2), 'LineWidth', 3);
grid on;
hold on;
I_CS = timeseries(I_CS(:, 2), I_CS(:, 1));


%% Длина хорды измерения
L_chord = readmatrix('L_chord4.txt');
figure;
plot(L_chord(:,1), L_chord(:,2), 'LineWidth', 3);
grid on;
hold on;
L_chord = timeseries(L_chord(:,2), L_chord(:,1));


%% Данные с канала mbi
mbi = readmatrix('mbi4.txt');
t = mbi(:,1);
mbi = mbi(:,2);

%без сглаживания
% figure;
% plot(t, mbi);
% grid on;
% hold on;

%сглаженные
w = 500;%величина окна
mbi = smoothdata(mbi, 'movmean', w);
% plot(t, mbi, 'LineWidth', 2);
% legend('Данные без сглаживания', 'Сглаженные данные');
% hold on;

%без постоянного уровня
w = 10000;%количество начальных точек
avg = mean(mbi(1:w));
mbi = mbi - avg;
mbi(mbi < 0) = 0;
figure;
plot(t, mbi, 'LineWidth', 2);
grid on;
hold on;

k = 0.7355e19; %коэффициент для канала 1.02415e19
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

figure;
plot(t_nP, nP, 'LineWidth', 2);
grid on;


%% Доп газонапуск
gas = readmatrix('gas.txt');
t = gas(:,1);
gas = gas(:,2);
gas = gas .* 2;
gas(gas<0) = 0;
figure;
plot(t, gas, 'LineWidth', 2);
grid on;
gas = timeseries(gas, t);


%% Начальное давление в камере
Nv0 = 1.8e-5; %Давление в торр
Nv0 = Nv0 * 2.17; %домножаем на коэффициент для водорода
Nv0 = Nv0 * 133.322; %давление в Па
Nv0 = Nv0 / 300 / 1.3806e-23; %концентрация молекул при 300 К
Nv0 = Nv0 * 13.5; %13.5 - объем ВК, общее кол-во молекул


%% Кол-во частиц на стенке (из расчета обмен между камерой и стенкой = 0)
t_ret = 0.0003; %постоянная времени поглощения стенкой
t_rel = 1.331; %постоянная времени высвобождения
Nw0 = Nv0 / t_ret * t_rel;


%% Настройка параметров модели
a_CS = 5e19; %коэффициент длины свободного пробега (Центральный соленоид)
betta = 9.6883e-7; %параметр бетта (Объем плазмы)
L = 8.4687e-11; %индуктивность плазмы
t_e = 1.1631; %энергетическое время жизни плазмы (Остывание)
k1 = 3.481e7; %коэффициент 1 потерь (Остывание)
k2 = 1.2019e-10; %коэффициент 2 потерь (Остывание)
% чувствительность прибора
a = 0.4;
b = 1e2;

global par0;
par0 = [betta, L, t_e, k1, k2];


%% Либо чтение параметров из файла
global par0;
par0 = readmatrix('par.txt');
par0 = par0(end, :); %выбор набора параметров


%% Подбор параметров
n = 100;
in_file = zeros(n, length(par0));
u = 1;
h = 1e-4;
e = zeros(1, length(par0));
e(1:end) = h;
open_system('ModelBlocks.slx');
err0 = sqrt(sum((nP - model_start()).^2)/length(nP));
for i=1:n
    old_par = par0;
    levenberg(@model_start, nP, {e u});

    if isempty(find(par0<0, 1)) == 0
        e(par0<0) = e(par0<0) / 10;
        par0 = old_par;
        continue;
    end
    % while(1)
    % 
    % 
    %     err = sqrt(sum((nP - model_start()).^2)/length(nP));
    % 
    %     if err > err0
    %         u = u * 10;
    %         par0 = old_par;
    %     else
    %         u = u / 10;
    %         err0 = err;
    %         if isempty(find(e<h, 1)) == 0
    %             e(e<h) = e(e<h) * 10;
    %         end
    %         break;
    %     end
    % end

    in_file(i, :) = par0;
    writematrix(in_file, 'par.txt');

    clc;
    fprintf("Итерация %d\n", i);
end


%% Запуск моделирования
open_system('ModelBlocks.slx');
nP_model = model_start();
plot(t_nP, nP_model, t_nP, nP, 'LineWidth', 2);
legend('Экспериментальные данные', 'Модель');
grid on;