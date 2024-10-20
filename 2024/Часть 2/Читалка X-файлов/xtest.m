clc;
clear;
addpath('libxfile\mex\bin\win64\')
xf = xfile;

[f,p] = uigetfile('*.xxx');

fopen(xf, [p,f], 'r');

[d,t] = get(xf, 'Data');

fclose(xf);

%%
figure;
plot(t, d(:,29), 'Color', 'r');
grid on;

%%
DATA = zeros(length(t), 2);
DATA(:,1) = t;
DATA(:,2) = d(:,29);

writematrix(DATA, 'I_CS.txt');