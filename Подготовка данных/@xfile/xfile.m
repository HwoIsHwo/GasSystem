classdef xfile < handle
%XFILE MATLAB I/O class for experimental or simulated data stored in
% X-files
%     properties (Access = private)
%         
%     end
    
    methods
        fopen(obj, filename, flag);
        fclose(obj, filename, flag);
        
        varargout = get(obj, pname);
        obj  = set(obj, pname, pval, varargin);
        flag = status(obj);
    end
    methods (Access = private)
        delete(obj);
    end
end