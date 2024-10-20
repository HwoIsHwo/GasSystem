%% Параметры для расчета
t = 6 * 60 * 60;
h = 0.0001;
t = 0:h:t;
G = zeros(1, length(t));
t1 = 5;
t2 = 600;

for i=1:1:length(G)
    if mod(t(i), t2) == 0
        if(i+t1/h+1) <= length(t)
            G(i:i+t1/h+1) = 5e18;
        else
            break;
        end
    end
end

U = G;

Y_exp = 8e19;

% plot(t, G);

%%
%Матрица ограничений для каждого из параметров (мин и макс значения)
%(кол-во значений = кол-во парметров)
limit = [0.0001, 10;
             0.0001, 100000];

%Количество итераций
iter = 50;

% Начальные параметры
t_retention = 0.0009;
t_release = 2.496;
par = [t_retention, t_release];

%Массив шагов для каждого из параметров (кол-во значений = кол-во параметров)
h = [0.0001, 0.0001];

%% Расчет (массив времени, параметры, ограничения параметров, входные переменные, 
% ИМЯ функции, целевая функция (массив данных), коли-во итераций, массив шагов)
%par = MATLAB_min_seek(par, G.', y, t, @scetch);
%par = [t_p, t_retention, t_release, t_ion, N_v0, N_w0];
par = minimal_seeking_function(t, par, limit, U, @Wall_modeling, Y_exp, iter, h, 0);

%%
Q = Wall_modeling(t, par, U);

%% Вывод графиков
y_mod = Wall_modeling(t, par, U);
figure;
% plot(t, Y_exp, 'DisplayName', 'Экспериментальные данные');
% hold on;
plot(t, y_mod, 'DisplayName', 'Модель');
%plot(t, G, 'DisplayName', 'Газонапуск');
xlabel('Время');
ylabel('Кол-во частиц в стенке');
legend('show');
title('Сравнение экспериментальных данных и модели');
grid on;
