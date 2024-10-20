% Функция обработки нажатия кнопки
function tau_pump(txt_P0, txt_F, lbl_pump, lbl_Nv)
    % Чтение введенного числа из текстового объекта
    P0 = str2double(txt_P0.Value);
    % обьем выкачки 3ех насосов 2000л/c, перевод в м^3/c
    F = str2double(txt_F.Value)/1000;
    % создание массивов для построения экспоненты. t2 - конечное время, 
    % n -кол-во разбиений
    t2 = 40; n = 4000;
    t = linspace(0,t2,n);
    Nv = zeros(1,n);
    P_torr = zeros(1,n);
    dt = t2/n;
    % % рассчет начального значения Nv
    V = 13.5; 
    T=300; 
    P = 133.32*P0; %p торр, переводится в Па 
    Nv(1) = P*V*6.022e23/8.31/T;
    Nv0save = Nv(1);
    lbl_Nv.Text = num2str(Nv0save);
    assignin("base","Nv0", Nv0save);

    P(1) = P/133.32;
    
    % рассчет точек экспоненты, физ. объяснение в док файле
    for i = 2:n
    Nv_otcachannoe = P*F/8.31/T* 6.022e23*dt;
    Nv(i) = Nv(i-1)-Nv_otcachannoe;
    P = (Nv(i)*8.31*T)/(6.022e23*V);
    P_torr(i) = P/133.32;
    end
    %построение графиков Nv и P(torr)
    figure(2);  tiledlayout(2,1);   nexttile; plot(t,Nv); title('Nv');
    nexttile;  plot(t,P_torr);  title('P');
    

    %----------рассчет tau_pump--------------------------------------------
    % Начальные значения параметров a и b
    initialGuess = [Nv(1) 0];
    % Определение функции, которую нужно получить (y=a*exp(bx)
    fitFunc = @(params, xdata) params(1) * exp(params(2) * xdata);
    % fitting the function
    paramsFit = lsqcurvefit(fitFunc, initialGuess, t, Nv);
    
    % Извлекаем значения параметров a и b
    aFit = paramsFit(1);
    bFit = paramsFit(2);

    lbl_pump.Text = num2str(abs(bFit));
    assignin("base","tau_pump", abs(bFit));

    % Построение графиков для сравнения
    figure(3); plot(t, Nv, 'o');  hold on;
    xfit = linspace(min(t), max(t), 100);
    yfit = aFit * exp(bFit * xfit);
    plot(xfit, yfit);legend('Исходные данные', 'Подобранное уравнение');
    title('Подобранное уравнениe к данным');
    xlabel('x');
    ylabel('y');
end
