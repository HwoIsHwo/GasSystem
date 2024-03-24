%Массив значений времени (экспер. данные соответс. моментам времени из массива)
t = 0:0.001:1.8;
%Массив шагов для каждого из параметров (кол-во значений = кол-во парметров)
h = [0.0001, 0.0001, 0.0001, 0.0001, 1e+17];
%Матрица ограничений для каждого из параметров (мин и макс значения)
%(кол-во значений = кол-во парметров)
limit = [0, 5;
             0, 5;
             0, 5;
             0, 5;
             0, 1e+23];

%Количество итераций
iter = 10000;

%Целевая функция (экспериментальные данные)
y = Yexp3.';

% Начальные параметры

% Для DT модели
% t_pDT = 0.0304;
% t_retentionDT = 0.0516;
% t_releaseDT = 0.1998;
% t_ionDT = 0.071;
% t_pHe = 0.0045;
% t_retentionHe = 0.0023;
% t_releaseHe = 0.001;
% t_ionHe = 0.001;
% t_syn = 0.8034;
% N_vDT = 2.6565e+19;
% N_wDT = 0;
% A = 0.1547;
% par = [t_pDT, t_retentionDT, t_releaseDT, t_ionDT, t_pHe, t_retentionHe, t_releaseHe, t_ionHe, t_syn, N_vDT, N_wDT, A];

%Для других моделей (не DT)
t_p = 0.0054;
t_retention = 0.0029;
t_release = 0.0297;
t_ion = 0.0574;
N_w0 = 2.511e21;
par = [t_p, t_retention, t_release, t_ion, N_w0];

%% Расчет (массив времени, параметры, ограничения параметров, входные переменные, 
% ИМЯ функции, целевая функция (массив данных), коли-во итераций, массив шагов)
%par = MATLAB_min_seek(par, G.', y, t, @scetch);
%par = [t_p, t_retention, t_release, t_ion, N_v0, N_w0];
par = minimal_seeking_function(t, par, limit, G.', @MATLAB_function_model_new, y, iter, h, 0);

%% Вывод графиков
figure;
plot(t, y, 'DisplayName', 'Экспериментальные данные');
hold on;
plot(t, MATLAB_function_model_new(t, par, G.'), 'DisplayName', 'Модель');
xlabel('Время');
ylabel('Кол-во частиц плазмы');
legend('show');
title('Сравнение экспериментальных данных и модели');
grid on;
hold off;

% plot(t, scetch(t, par, G.'));
% hold on;
% plot(t, y);
% grid on;
% legend('Y_{mod}', 'Y_{exp}');
% hold off;
