%% Медленный
function [new_par] = minimal_seeking_function(t, par, limit, U, model, y_exp, iter, h, flag)

    if flag == 0
        new_par = par;
    
        for i=1:iter
            for j=1:length(new_par)
                while (1)
                    y_mod = model(t, new_par, U);
                    I0 = sum((y_exp-y_mod).^2);
                    Old = new_par(j);
                    new_par(j) = new_par(j) + h(j);
                    y_mod = model(t, new_par, U);
                    I = sum((y_exp-y_mod).^2);
                    if I > I0
                        new_par(j) = Old;
                        break;
                    end
                    if new_par(j)>limit(j,2)
                        new_par(j) = limit(j, 2);
                        break;
                    end
                end
                while (1)
                    y_mod = model(t, new_par, U);
                    I0 = sum((y_exp-y_mod).^2);
                    Old = new_par(j);
                    new_par(j) = new_par(j) - h(j);
                    y_mod = model(t, new_par, U);
                    I = sum((y_exp-y_mod).^2);
                    if I > I0
                        new_par(j) = Old;
                        break;
                    end
                    if new_par(j)<limit(j,1)
                        new_par(j) = limit(j, 1);
                        break;
                    end
                end
                clc;
                disp([i, j]);
            end
        end
    end
% 


%% Быстрый
    if flag == 1
        new_par = par;
        a = 1;
        L = length(new_par);
    
        for i=1:iter
            for j=1:L
                while (1)
                    y_mod = model(t, new_par, U);
                    I0 = sum((y_exp - y_mod).^2);
                    A = rand();
                    j1 = round(A * L + 1 - A);
                    Old = new_par(j1);
                    new_par(j1) = new_par(j1) + a * h(j1) * (10 / i + 0.1);
                    y_mod = model(t, new_par, U);
                    I = sum((y_exp-y_mod).^2);
                    if (I > I0) || isinf(I) || isnan(I)
                        new_par(j1) = Old;
                        if a == 1
                            a = -1;
                        elseif a == -1
                            break;
                        end
                    end
                    if new_par(j1) > limit(j1,2)
                        new_par(j1) = limit(j1, 2);
                        break;
                    end
                    if new_par(j1) < limit(j1,1)
                        new_par(j1) = limit(j1, 1);
                        break;
                    end
                end
                if mod(i, 100) == 0
                    clc;
                    disp([i, j]);
                end
            end
        end
    end
end