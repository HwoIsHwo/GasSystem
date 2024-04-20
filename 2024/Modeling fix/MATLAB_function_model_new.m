function [N_p] = MATLAB_function_model_new(t, par, U)

    %параметры модели и начальные условия
    t_p = par(1);
    t_retention = par(2);
    t_release = par(3);
    t_ion = par(4); 
    t_pump = 1.776;
    N_p0 = 0;
    N_v0 = 2.1738e+19;
    N_w0 = par(5);

    %Входной поток
   G = U;

    N_p = zeros(1, length(t));
    N_p(1) = N_p0;
    N_v = N_v0;
    N_w = N_w0;

    for i=2:length(t)
        dN_p = -N_p(i-1)/t_p + 2*N_v/t_ion;
        dN_w = -N_w/t_release + N_v/t_retention;
        dN_v = G(i-1) - N_v*(1/t_retention+1/t_pump+1/t_ion) + 0.5*N_p(i-1)/t_p + N_w/t_release;
        N_p(i) = N_p(i-1) + dN_p * (t(i) - t(i-1));
        N_v = N_v + dN_v * (t(i) - t(i-1));
        N_w = N_w + dN_w * (t(i) - t(i-1));
    end

end

