function [] = levenberg(Function, data, par)

global par0;

h = par(1); % шаг определения производной
u = par(2); %величина прибавки

out_exp = data;

out = Function();

r = out_exp -  out; %Массив отклонений в значениях функции и "экспериментальных"

J = zeros(length(r), length(par0)); %якобиан r(данные) строк, p(параметры) столбцов

for i=1:length(par0) %цикл по всем параметрам
    p_old = par0(i);
    step = h * par0(i);
    par0(i) = par0(i) + step; %меняем параметр

    out = Function();

    r_new = out_exp - out; %значения ошибок при новых параметрах
    drdp = (r_new - r) / step; %производная от  ошибок по параметру
    par0(i) = p_old; %возвращаем значение параметра
    J(:, i) = drdp; %записываем в якобиан производные по этому параметру
end

%расчет изменений параметров
Jt = J.';
A = (Jt * J);
A = A + u * eye(length(par0));
A = A^(-1);
A = A * Jt;
A = A * r;
par0 = (par0.') - A;
par0 = par0.';
    
end