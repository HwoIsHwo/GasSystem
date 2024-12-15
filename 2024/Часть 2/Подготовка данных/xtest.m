clc;
clear;

%% Выбор файла
addpath('libxfile\mex\bin\win64\')
xf = xfile;

[f,p] = uigetfile('*.xxx');

fopen(xf, [p,f], 'r');

[d, t] = get(xf, 'Data');

fclose(xf);

%% График
%ток центрального соленоида CCC diagram канал 29
%ток плазмы PLC diagram канал 7
%mbi каналы 3 и 4
%доп напуск EMD_PS канал 13
chanel = 4; %канал данных
figure;
plot(t, d(:, chanel), 'Color', 'r');
grid on;

%% Запись в txt
DATA = zeros(length(t), 2);
DATA(:,1) = t;
DATA(:,2) = d(:, chanel);

writematrix(DATA, 'mdi4.txt');