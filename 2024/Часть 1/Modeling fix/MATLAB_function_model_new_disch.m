function [N_out] = MATLAB_function_model_new_disch(t, par, U)

    %параметры модели и начальные условия
    t_retention = 0.0003;
    t_release = 1.331;
    t_ion = par(1); 
    t_pump = 1.776;
    N_p0 = 0;
    N_v0 = par(2);
    N_w0 = par(3);
    t_p = par(4);

    %Входной поток
   G = U(:, 1);
   Discharge = U(:, 2);

    N_out = zeros(length(t), 1);
    N_out(1) = N_p0;
    N_p = N_p0;
    N_v = N_v0;
    N_w = N_w0;

    for i=2:length(t)
        if Discharge(i) > 0
            dN_p = -N_p/t_p + 2*N_v/t_ion;
            dN_w = -N_w/t_release + N_v/t_retention;
            dN_v = G(i-1) - N_v*(1/t_retention+1/t_pump+1/t_ion) + 0.5*N_p/t_p + N_w/t_release;
        else
            if N_p > 0
                dN_p = -N_p/t_p;
                dN_w = -N_w/t_release + N_v/t_retention;
                dN_v = G(i-1) - N_v*(1/t_retention+1/t_pump) + N_w/t_release + 0.5*N_p/t_p;
            else
                dN_p = 0;
                dN_w = -N_w/t_release + N_v/t_retention;
                dN_v = G(i-1) - N_v*(1/t_retention+1/t_pump) + N_w/t_release;
            end
        end

        N_p = N_p + dN_p * (t(i) - t(i-1));
        N_v = N_v + dN_v * (t(i) - t(i-1));
        N_w = N_w + dN_w * (t(i) - t(i-1));

        N_out(i) = N_p;
    end

end

