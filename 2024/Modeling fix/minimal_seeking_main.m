%% Чтение данных
DATA = readmatrix('../Filtered_DATA.xlsx'); %чтение данных
t = DATA(:,1); %запись в массив времени
Y_exp = DATA(:,2);%запись в массив эксперементальных данных
G = readmatrix('G.xlsx');
G = G(:, 2);
Dis = zeros(length(G), 1);
Dis(52495:150000) = 1;
%37502:150000


%% "Обрезка" данных (каждый 10й элемент)
t = t(1:10:end);
Y_exp = Y_exp(1:10:end);
G = G(1:10:end);
Dis = Dis(1:10:end);

U = [G, Dis];

%%
%Матрица ограничений для каждого из параметров (мин и макс значения)
%(кол-во значений = кол-во парметров)
limit = [0.0003, 0.0003;
             1.331, 1.331;
             0.0001, 50;
             0.0001, 1e+25;
             0.0001, 5];

%Количество итераций
iter = 100;

% Начальные параметры
t_retention = 0.0003;
t_release = 1.331;
t_ion = 0.0254;
N_w0 = 2.0908e22;
t_p = 0.0316;
par = [t_retention, t_release, t_ion, N_w0, t_p];

%Массив шагов для каждого из параметров (кол-во значений = кол-во параметров)
h = [0.0001, 0.0001, 0.0001, 1e+16, 0.0001];

%% Расчет (массив времени, параметры, ограничения параметров, входные переменные, 
% ИМЯ функции, целевая функция (массив данных), коли-во итераций, массив шагов)
%par = MATLAB_min_seek(par, G.', y, t, @scetch);
%par = [t_p, t_retention, t_release, t_ion, N_v0, N_w0];
par = minimal_seeking_function(t, par, limit, U, @MATLAB_function_model_new_disch, Y_exp, iter, h, 0);

%% Вывод графиков
y_mod = MATLAB_function_model_new_disch(t, par, U);
figure;
plot(t, Y_exp, 'DisplayName', 'Экспериментальные данные');
hold on;
plot(t, y_mod, 'DisplayName', 'Модель');
%plot(t, G, 'DisplayName', 'Газонапуск');
xlabel('Время');
ylabel('Кол-во частиц плазмы');
legend('show');
title('Сравнение экспериментальных данных и модели');
grid on;

% clc;
% I = sum(abs(y-y_mod));
% disp(I);
% Aver = I / length(t);
% disp(Aver);
% Norm = Aver / max(y);
% disp(Norm);

% figure;
% plot(t, G, 'DisplayName', 'Газонапуск');
% xlabel('Время');
% ylabel('Кол-во частиц плазмы');
% legend('show');
% grid on;
% hold on;

% plot(t, scetch(t, par, G.'));
% hold on;
% plot(t, y);
% grid on;
% legend('Y_{mod}', 'Y_{exp}');
% hold off;