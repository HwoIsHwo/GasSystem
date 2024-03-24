%% MatLab функция
function [optimized_params] = MATLAB_min_seek(parameters, input_data, experimental_data, time_points, model)
    % Функция для подбора параметров модели
    
    % Начальные значения параметров
    initial_params = parameters; 
    
    % Оптимизация параметров с использованием метода наименьших квадратов
    options = optimset('Display', 'iter', 'MaxFunEvals', 100000, 'MaxIter', 10000); % настройки опции оптимизатора
    optimized_params = fminsearch(@(params) cost_function(params, time_points, input_data, experimental_data, model), initial_params, options);
    
    % Рассчитываем значения модели с оптимизированными параметрами
    model_output = model(time_points, optimized_params, input_data);
    
    % Отобразить результаты
    plot_results(time_points, experimental_data, model_output);
end

function cost = cost_function(params, time_points, input_data, experimental_data, model)
    % Функция стоимости для оптимизации
    model_output = model(time_points, params, input_data);
    cost = sum((experimental_data - model_output).^2);
end

function plot_results(time_points, experimental_data, model_output)
    % Функция для отображения результатов
    figure;
    plot(time_points, experimental_data, 'DisplayName', 'Экспериментальные данные');
    hold on;
    plot(time_points, model_output, 'DisplayName', 'Модель');
    xlabel('Время');
    ylabel('Кол-во частиц плазмы');
    legend('show');
    title('Сравнение экспериментальных данных и модели');
    grid on;
    hold off;
end

