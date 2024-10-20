function delete(~)
%DELETE Summary of this function goes here
%   Detailed explanation goes here
    if mexxfile('isactive')
        mexxfile('fclose');
        clear mexxfile;
    end
end

