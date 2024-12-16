clc;
clear all;

bdir = ['mex', filesep, 'bin', filesep, computer('arch'),filesep];
xlib = ['src', filesep, 'WorkXFNew'];%, computer('arch'),filesep
mexsrc = ['mex', filesep, 'mexxfile.cpp'];
ipath = ['-Iinclude', filesep];
imexpath = ['-Imex', filesep];

if ispc
    mex('-outdir', bdir, '-v', '-largeArrayDims', ipath, imexpath, mexsrc, [xlib, '.cpp'])% 
    %copyfile([seplib, '.dll'], bdir);
elseif isunix
    mex('-outdir', bdir, '-v', '-largeArrayDims', 'LDFLAGS=""', ipath, imexpath, mexsrc, [xlib, '.a'])
else
    error('Unsupported computer architecture');
end