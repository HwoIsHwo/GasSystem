%Массив значений времени (экспер. данные соответс. моментам времени из массива)
t = 0:0.001:1.8;
%Массив шагов для каждого из параметров (кол-во значений = кол-во парметров)
h = [0.0001, 0.0001, 0.0001, 0.0001, 1e+16];
%Матрица ограничений для каждого из параметров (мин и макс значения)
%(кол-во значений = кол-во парметров)
limit = [0.234, 0.234;
             0, 5;
             0, 5;
             0.0432, 0.0432;
             0, 1e+23];

%Количество итераций
iter = 250000;

%Целевая функция (экспериментальные данные)
%y = Yexp.';
G = readmatrix('G.xlsx');
G = G(:, 2);
G = G.';
y = MATLAB_function_model_article(t, [0.234 0.001 0.233 0.0432 1.4344e+20], G);

%Запись в файлы
% writematrix([t' Yexp], 'EXP1.xlsx');
% writematrix([t' Yexp2], 'EXP2.xlsx');
% writematrix([t' Yexp3], 'EXP3.xlsx');
% writematrix([t' G], 'G.xlsx');

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
t_p = 0.234;
t_retention = 0.5;
t_release = 0.5;
t_ion = 0.0432;
N_w0 = 1e+19;
par = [t_p, t_retention, t_release, t_ion, N_w0];

%% Расчет (массив времени, параметры, ограничения параметров, входные переменные, 
% ИМЯ функции, целевая функция (массив данных), коли-во итераций, массив шагов)
%par = MATLAB_min_seek(par, G.', y, t, @scetch);
%par = [t_p, t_retention, t_release, t_ion, N_v0, N_w0];
par = minimal_seeking_function(t, par, limit, G, @MATLAB_function_model_article, y, iter, h, 1);

%% Вывод графиков
y_mod = MATLAB_function_model_article(t, par, G);
figure;
plot(t, y, 'DisplayName', 'Экспериментальные данные');
hold on;
plot(t, y_mod, 'DisplayName', 'Модель');
xlabel('Время');
ylabel('Кол-во частиц плазмы');
legend('show');
title('Сравнение экспериментальных данных и модели');
grid on;

clc;
I = sum(abs(y-y_mod));
disp(I);
Aver = I / length(t);
disp(Aver);
Norm = Aver / max(y);
disp(Norm);

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


%% Наброски
% P = 0:1e+19:3e+20;
% I = zeros(1, length(P));
% 
% for i=1:length(P)
%     I(i) = sum((y-MATLAB_function_model_article(t, [0.234, 0.001, 0.233, 0.0432, P(i)], G)).^2);
% end
% 
% figure;
% plot(P, I);
% grid on;
% hold on;