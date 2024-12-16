clc;
clear;

%% Выбор файла
[f, p] = uigetfile('*.xlsx');
data = readmatrix([p, f], 'Sheet', 'sep');

%% График границ плазмы
t = data(:, 1);
r = data(:, 2:102);
z = data(:, 103:203);
% figure;
% plot3(t, r, z);
% grid on;
% hold on;

%% Определение длины хорды
z_ism = 0.3; %положение хорды измерения %0.415
r_ism = zeros(length(t), 2); %координаты R на высоте измерения
er0 = 0.0001;

for i=1:length(t)
    z_max = find(z(i,:) == max(z(i,:))); %максимальное значение
    z_min = find(z(i,:) == min(z(i,:))); %минимальное значение
    if z_max < z_min
        s = z_max;
        e = z_min;
    else
        s = z_min;
        e = z_max;
    end
    
    a = 0;
    er = er0;
    while 1
        a = find(abs(z(i, s:e) - z_ism) < er, 1);
        if isempty(a)
            er = er + 0.0001;
        else
            break;
        end
    end
    a = s - 1 + a;
    r_ism(i, 1) = r(i, a);
    z(i, s:e) = 0;
    
    a = 0;
    er = er0;
    while 1
        a = find(abs(z(i, :) - z_ism) < er, 1);
        if isempty(a)
            er = er + 0.0001;
        else
            break;
        end
    end
    r_ism(i, 2) = r(i, a);
end

%% Длина хорды
l = abs(r_ism(:,1) - r_ism(:,2));
l2 = zeros(length(t), 1);
for i=1:length(t)
    l2(i) = max(r(i, :)) - min(r(i, :));
end
figure;
plot(t, l, t, l2);
grid on;

%% Запись в файл
writematrix([t, l], 'L_chord');