function [N_p] = MATLAB_function_model_DTHe_article(t, par, U)
    %Входной поток
   G = U;

    N_p = zeros(1, length(t));
    N_p(1) = 0;

    t_pDT = par(1);
    t_retentionDT = par(2);
    t_releaseDT = par(3);
    t_ionDT = par(4);
    t_pHe = par(5);
    t_retentionHe = par(6);
    t_releaseHe = par(7);
    t_ionHe = par(8);
    t_syn = par(9);
    t_pump = 1.125;
    N_pDT = 1;
    N_vDT = par(10);
    N_wDT = par(11);
    N_pHe = 1;
    N_vHe = 0;
    N_wHe = 0;
    %Состав объема
    A = N_vDT+N_vHe+1;
    C_DT = N_vDT/A; 
    C_He = N_vHe/A; 

    for i=2:length(t)
        %Расчет производных
        dN_pDT = -N_pDT/t_pDT + N_vDT/t_ionDT - 2*N_pDT/t_syn + N_wDT/t_releaseDT - N_pDT/t_retentionDT;
        dN_pHe = -N_pHe/t_pHe + 0.5*N_pDT/t_syn + N_vHe/t_ionHe + N_wHe/t_releaseHe - N_pHe/t_retentionHe;
        dN_vDT = G(i-1) - N_vDT/t_ionDT + N_pDT/t_pDT - N_vDT*C_DT/t_pump;
        dN_vHe = -N_vHe/t_ionHe + N_pHe/t_pHe - N_vHe*C_He/t_pump;
        dN_wDT = N_pDT/t_retentionDT - N_wDT/t_releaseDT;
        dN_wHe = N_pHe/t_retentionHe - N_wHe/t_releaseHe;
        %Расчет новых значений
        N_pDT = N_pDT + dN_pDT * (t(i) - t(i-1));
        N_pHe = N_pHe + dN_pHe * (t(i) - t(i-1));
        N_vDT = N_vDT + dN_vDT * (t(i) - t(i-1));
        N_vHe = N_vHe + dN_vHe * (t(i) - t(i-1));
        N_wDT = N_wDT + dN_wDT * (t(i) - t(i-1));
        N_wHe = N_wHe + dN_wHe * (t(i) - t(i-1));
        %Состав объема
        A = N_vDT+N_vHe+1;
        C_DT = N_vDT/A; 
        C_He = N_vHe/A; 
        %Количество электронов в плазме
        N_p(i) = N_pDT + 2*N_pHe;
    end

end