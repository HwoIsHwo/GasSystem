%% Чтение и преобразование данных
data = readmatrix('mbi.xlsx');

t = data(:,1);
OUT = data(:,2);
K = 2e+19;
OUT = OUT .* K;
% bias = min(OUT);
bias = 6.8e18;
OUT = OUT - bias;
OUT(OUT<0) = 0;
Valve = data(:,6);

plot(t, OUT);

%% Разложение по частотам (-)
fft_OUT = fft(OUT);
L = length(t);
P2 = abs(fft_OUT/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);
f = 0:(L/2);

figure;
plot(f,P1);
hold on;
title('Single-Sided Amplitude Spectrum of X(t)');
xlabel('f (Hz)');
ylabel('|P1(f)|');
grid on;


%% Медианный фильтр (+-)
level = 1000; %Размер окна - чем больше, тем больше сглаживает
med_OUT = medfilt1(OUT, level);
figure;
plot(t,med_OUT);
legend('Med');
legend('boxoff');
hold on;
grid on;

%% Бегущее среднее (+-)
level = 1000;   %Размер окна - чем больше, тем больше сглаживает
aver_OUT = smoothdata(OUT, 'movmean', level);
figure;
plot(t, aver_OUT);
legend('Aver');
legend('boxoff');
hold on;
grid on;


%% Фильтр Баттерворта (+-)
fc = 4; %Для смены частоты среза, чем меньше, тем больше шумов срезает
fs = 10000;
[b, a] = butter(5, fc/(fs/2));
but_OUT = filter(b, a, OUT);
    
figure;
plot(t, but_OUT);
hold on;
legend('Butter');
legend('boxoff');
xlabel('Время, с');
ylabel('Кол-во частиц');
legend('show');
grid on;


%% Аппроксимация полиномом (+-)
n = 200;  %Порядок полинома
p = polyfit(t, aver_OUT, n); %Вместо OUT (изначальные данные) можно попробовать подставлять 
% уже отфильтрованные каким-нибудь фильтром
poly_OUT = polyval(p, t);
figure;
plot(t, poly_OUT);
hold on;
legend('Poly');
legend('boxoff');
xlabel('Время, с');
ylabel('Кол-во частиц');
legend('show');
grid on;


%% Аппроксимация экспонентой (--)
X = [ones(size(t)) exp(-t) t.*exp(-t) (t.^2).*exp(-t) (t.^3).*exp(-t) (t.^4).*exp(-t) (t.^5).*exp(-t) (t.^6).*exp(-t)];
a = X\OUT;
exp_OUT = [ones(size(t)) exp(-t) t.*exp(-t) (t.^2).*exp(-t) (t.^3).*exp(-t) (t.^4).*exp(-t) (t.^5).*exp(-t) (t.^6).*exp(-t)]*a;
figure;
plot(t, exp_OUT);
hold on;
legend('Exp');
legend('boxoff');
xlabel('Время, с');
ylabel('Кол-во частиц');
legend('show');
grid on;

%% Графики
figure;
plot(t, OUT, 'DisplayName', 'Экспериментальные данные');
hold on;
xlabel('Время, с');
ylabel('Кол-во частиц');
legend('show');
grid on;

figure;
plot(t, Valve, 'DisplayName', 'Напряжение на клапане');
hold on;
xlabel('Время, с');
ylabel('Напряжение, В');
legend('show');
grid on;


%% Определение постоянной времени (задний фронт)
a = 146000; % Выбираем точки, с которых по которым строи график
b = 168757;
T = t(a:b)-t(a);
Y = aver_OUT(a:b)-min(aver_OUT(a:b));

fun1 = @(x, xdata) x(1)*exp(x(2)*xdata); % Эспоненциальная функция для апроксимации

par = [1.6e+19, -1];
new_par = lsqcurvefit(fun1, par, T, Y);
t_p = -1/new_par(2);

figure;
plot(T, Y, T, fun1(new_par, T));
legend('Data','Fitted exponential');
hold on;
grid on;


%% Определение постоянной времени (передний фронт, используется часть модели)
a = 47500; % Выбираем точки, с которых по которым строим график
b = 110000;
T = t(a:b)-t(a);
Y = aver_OUT(a:b)-0.4e+19;

fun2 = @(x, xdata) 2*t_p*0.6e19/x-(4.728e17/x)*exp(-xdata/t_p);

par = 1;
new_par = lsqcurvefit(fun2, par, T, Y);
t_ion = new_par;

figure;
plot(T, Y, T, fun2(new_par, T));
legend('Data','Fitted exponential');
hold on;
grid on;

%% Передний фронт (просто экспонента)
a = 44000; % Выбираем точки, с которых по которым строим график
b = 120000;
T = t(a:b)-t(a);
Y = aver_OUT(a:b)-0.4e+19;

fun3 = @(x, xdata) x(1)*(1-exp(x(2)*xdata)); % Эспоненциальная функция для апроксимации

par = [1.6e+19, -1];
new_par = lsqcurvefit(fun3, par, T, Y);
t_ion = -1/new_par(2);

figure;
plot(T, Y, T, fun3(new_par, T));
legend('Data','Fitted exponential');
hold on;
grid on;


%% Запись отфильтрованных данных в файл
writematrix([t, aver_OUT], 'Filtered_DATA.xlsx');