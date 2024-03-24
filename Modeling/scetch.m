function [N_p] = scetch(t, par, U)

    %параметры модели и начальные условия
    t_p = par(1);
    t_retention = par(2);
    t_release = par(3);
    t_ion = par(4);
    N_p0 = 0;
    N_v0 = par(5);
    N_w0 = par(6);
    t_pump = 1.125;

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
        if N_p(i) < 0
            N_p(i) = 0;
        end
        if N_v < 0
            N_v = 0;
        end
        if N_w < 0
            N_w = 0;
        end
    end

end



% function [N_p] = scetch(t, par, U)
%     %Входной поток
%    G = U;
% 
%     N_p = zeros(1, length(t));
%     N_p(1) = 0;
% 
%     t_pDT = par(1);
%     t_retentionDT = par(2);
%     t_releaseDT = par(3);
%     t_ionDT = par(4);
%     t_pHe = par(5);
%     t_retentionHe = par(6);
%     t_releaseHe = par(7);
%     t_ionHe = par(8);
%     t_syn = par(9);
%     N_pDT = 1;
%     N_vDT = par(10);
%     N_wDT = par(11);
%     N_pHe = 1;
%     N_vHe = 0;
%     N_wHe = 0;
%     A = par(12);
% 
%     %Состав объема
%     C = N_vDT+N_vHe+1;
%     C_DT = N_vDT/C; 
%     C_He = N_vHe/C; 
% 
%     for i=2:length(t)
%         t_pump = A * (4.5 * (N_vHe + N_vDT) / (N_vHe + N_vDT + N_pHe + N_pHe + 1)) / 4;
% 
%         %Расчет производных
%         dN_pDT = -N_pDT/t_pDT + N_vDT/t_ionDT - 2*N_pDT/t_syn;
%         dN_pHe = -N_pHe/t_pHe + 0.5*N_pDT/t_syn + N_vHe/t_ionHe;
%         dN_vDT = G(i-1) - N_vDT/t_ionDT + N_pDT/t_pDT - N_vDT*C_DT/t_pump + N_wDT/t_releaseDT - N_vDT/t_retentionDT;
%         dN_vHe = -N_vHe/t_ionHe + N_pHe/t_pHe - N_vHe*C_He/t_pump + N_wHe/t_releaseHe - N_vHe/t_retentionHe;
%         dN_wDT = N_vDT/t_retentionDT - N_wDT/t_releaseDT;
%         dN_wHe = N_vHe/t_retentionHe - N_wHe/t_releaseHe;
%         %Расчет новых значений
%         N_pDT = N_pDT + dN_pDT * (t(i) - t(i-1));
%         N_pHe = N_pHe + dN_pHe * (t(i) - t(i-1));
%         N_vDT = N_vDT + dN_vDT * (t(i) - t(i-1));
%         N_vHe = N_vHe + dN_vHe * (t(i) - t(i-1));
%         N_wDT = N_wDT + dN_wDT * (t(i) - t(i-1));
%         N_wHe = N_wHe + dN_wHe * (t(i) - t(i-1));
%         %Состав объема
%         C = N_vDT+N_vHe+1;
%         C_DT = N_vDT/C; 
%         C_He = N_vHe/C; 
%         %Количество электронов в плазме
%         N_p(i) = N_pDT + 2*N_pHe;
% 
%         if N_pDT < 0
%             N_pDT = 0;
%         end
%         if N_pHe < 0
%             N_pHe = 0;
%         end
%         if N_vDT < 0
%             N_vDT = 0;
%         end
%         if N_vHe < 0
%             N_vHe = 0;
%         end
%         if N_wHe < 0
%             N_wHe = 0;
%         end
%         if N_vDT < 0
%             N_vDT = 0;
%         end
% 
%     end
% 
% end
