% function gui_tau_pump()
clear;
clc;
data = importdata('start_params.txt');


fig = uifigure('Name', 'Графический интерфейс');
fig.Position = [100 300 600 450];
fig.CloseRequestFcn = @(src,event)closereq(src, txt_P0,txt_F, txt_tau_p, txt_tau_retention, txt_tau_ion, txt_tau_release, txt_Np0, txt_Nw0, lbl_Nv0, lbl_pump);

uilabel(fig, 'Position', [15 420 400 22], 'Text', 'Введите параметры для рассчета tau_pump:', 'FontSize', 14);

uilabel(fig, 'Position', [25 395 200 22], 'Text', 'Начальное давление:', 'FontSize', 14);
txt_P0 = uieditfield(fig,'Position',[25 375 200 22],'Value', num2str(data(1)));

uilabel(fig, 'Position', [25 350 200 22], 'Text', 'Производительность насосв:', 'FontSize', 14);
txt_F = uieditfield(fig, 'Position',[25 330 200 22], 'Value', num2str(data(2)));

uilabel(fig, 'Position', [380 395 400 22], 'Text', 'Рассчитанное tau_pump:', 'FontSize', 14);
lbl_pump = uilabel(fig, 'Position', [380 375 200 22], 'Text', num2str(data(10)), 'FontSize', 14);
uilabel(fig, 'Position', [380 350 400 22], 'Text', 'Рассчитанное Nv(0):', 'FontSize', 14);
lbl_Nv0 = uilabel(fig, 'Position', [380 330 200 22], 'Text', num2str(data(9)), 'FontSize', 14);
button1 = uibutton(fig, 'Position', [15 295 100 30], 'Text', 'Рассчитать', 'ButtonPushedFcn', @(btn,event)tau_pump(txt_P0, txt_F,lbl_pump, lbl_Nv0));
% 
uilabel(fig, 'Position', [365 265 400 22], 'Text', 'Введите начальные условия:', 'FontSize', 14);

uilabel(fig, 'Position', [380 240 400 22], 'Text', 'Np(0):', 'FontSize', 14);
txt_Np0 = uieditfield(fig, 'Position', [380 220 200 22], 'Value', num2str(data(7)));
uilabel(fig, 'Position', [380 195 400 22], 'Text', 'Nw(0):', 'FontSize', 14);
txt_Nw0 = uieditfield(fig, 'Position', [380 175 200 22], 'Value', num2str(data(8)));

% [15 445 400 22]
uilabel(fig, 'Position', [15 265 400 22], 'Text', 'Введите параметры плазмы:', 'FontSize', 14);

uilabel(fig, 'Position', [25 240 200 22], 'Text', 'tau_p:', 'FontSize', 14);
txt_tau_p = uieditfield(fig, 'Position',[25 220 200 22], 'Value', num2str(data(3)));

uilabel(fig, 'Position', [25 195 200 22], 'Text', 'tau_retention:', 'FontSize', 14);
txt_tau_retention = uieditfield(fig, 'Position',[25 175 200 22], 'Value', num2str(data(4)));

uilabel(fig, 'Position', [25 150 200 22], 'Text', 'tau_ion:', 'FontSize', 14);
txt_tau_ion = uieditfield(fig, 'Position',[25 130 200 22], 'Value', num2str(data(5)));

uilabel(fig, 'Position', [25 105 200 22], 'Text', 'tau_release:', 'FontSize', 14);
txt_tau_release = uieditfield(fig, 'Position',[25 85 200 22], 'Value', num2str(data(6)));

fig.CloseRequestFcn = @(src,event)closereq(src, txt_P0,txt_F, txt_tau_p, txt_tau_retention, txt_tau_ion, txt_tau_release, txt_Np0, txt_Nw0, lbl_Nv0, lbl_pump);
button2 = uibutton(fig, 'Position', [250 20 100 40], 'Text', 'Применить', 'ButtonPushedFcn',...
    @(btn,event)update_params(txt_P0, lbl_Nv0, lbl_pump, txt_tau_p, txt_tau_retention, txt_tau_ion, txt_tau_release));

% Доделать апдейт параметров
function update_params(txt_P0, lbl_Nv, lbl_pump, txt_tau_p, txt_tau_retention, txt_tau_ion, txt_tau_release)
    to_workspace = str2double(txt_P0.Value);
    assignin("base","P0", to_workspace)
    to_workspace = str2double(lbl_Nv.Text);
    assignin("base","Nv0", to_workspace);
    t_pump = str2double(lbl_pump.Text);
    assignin("base","tau_pump", to_workspace);
    t_p = str2double(txt_tau_p.Value);
    assignin("base","tau_p", to_workspace);
    t_retention = str2double(txt_tau_retention.Value);
    assignin("base","tau_retention", to_workspace);
    t_ion = str2double(txt_tau_ion.Value);
    assignin("base","tau_ion", to_workspace);
    t_release = str2double(txt_tau_release.Value);
    assignin("base","tau_release", to_workspace);
    B = [0;0;1];
    C = [1,0,0; 0, 0, 1];
    D = [0; 0];assignin("base","B", B);
    A = [-1*(1/t_p+1/t_retention), 1/t_release,2/t_ion; 1/t_retention, -1/t_release, 0; 1/(2*t_p), 0, -1*(1/t_pump+1/t_ion)];
    assignin("base","A", A);assignin("base","B", B);assignin("base","C", C);assignin("base","D", D);
end

% Проверить запись в файл, сделать нормальное чтение и заполнение
function closereq(fig, txt_P0,txt_F, txt_tau_p, txt_tau_retention, txt_tau_ion, txt_tau_release, txt_Np0, txt_Nw0, lbl_Nv0, lbl_pump)
    selection = uiconfirm(fig,'Save values?','Confirmation');
    switch selection
        case 'OK'
            to_file = [str2double(txt_P0.Value), str2double(txt_F.Value), str2double(txt_tau_p.Value), str2double(txt_tau_retention.Value), str2double(txt_tau_ion.Value), str2double(txt_tau_release.Value), str2double(txt_Np0.Value), str2double(txt_Nw0.Value), str2double(lbl_Nv0.Text), str2double(lbl_pump.Text)];
            
            fid = fopen('start_params.txt', 'w');
            fprintf(fid, '%f\n', to_file);
            fclose(fid);
            delete(fig);
        case 'Cancel'
            delete(fig);
    end
end
% end
