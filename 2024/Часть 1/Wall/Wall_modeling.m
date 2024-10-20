function [out] = Wall_modeling(t, par, U)

    %параметры модели и начальные условия
    t_retention = par(1);
    t_release = par(2);
    t_pump = 1.776;
    N_v0 = 0;
    N_w0 = 0;

    %Входной поток
   G = U;

    N_w = zeros(1, length(t));
    N_v = zeros(1, length(t));
    N_v(1) = N_v0;
    N_w(1) = N_w0;

    for i=2:length(t)
        dN_w = -N_w(i-1)/t_release + N_v(i-1)/t_retention;
        dN_v = G(i-1) - N_v(i-1)*(1/t_retention+1/t_pump) + N_w(i-1)/t_release;
        
        N_v(i) = N_v(i-1) + dN_v * (t(i) - t(i-1));
        if N_v(i) < 0
            N_v(i) = 0;
        end
        N_w(i) = N_w(i-1) + dN_w * (t(i) - t(i-1));
        if N_w(i) < 0
            N_w(i) = 0;
        end
    end

    h = t(2) - t(1);
    out = sum(N_w(end-60/h:end))/(60/h)/t_release;
    % out = N_v;

end
