%% Чтение и преобразование данных
data = readmatrix('mbi.xlsx');

t = data(:,1);
OUT = data(:,2);
bias = min(OUT);
K = 2e+19;
OUT = (OUT-bias)*K;
Valve = data(:,6);


%% Разложение по частотам
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


%% Медианный фильтр
level = 1000;
med_OUT = medfilt1(OUT, level);
figure;
plot(t,med_OUT);
legend('Med');
legend('boxoff');
hold on;
title('Single-Sided Amplitude Spectrum of X(t)');
grid on;

%% Бегущее среднее
level = 1000;
aver_OUT = smoothdata(OUT, 'movmean', level);
figure;
plot(t,aver_OUT);
legend('Aver');
legend('boxoff');
hold on;
title('Single-Sided Amplitude Spectrum of X(t)');
grid on;


%% Фильтр Баттерворта 3
fc = 4;
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