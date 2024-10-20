clear;
clc;

I_CS = readmatrix('I_CS.txt');
I_CS = timeseries(I_CS(:, 2), I_CS(:, 1));