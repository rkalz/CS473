raw = imread('raw.tiff');

handle = fopen('hw1_473sp19.txt','w');
fprintf(handle, '%d\n', size(raw, 1));
fprintf(handle, '%d\n', size(raw, 2));
fprintf(handle, '%s\n', class(raw(1,1)));
fprintf(handle, '%d\n', min(raw));
fprintf(handle, '%d\n', max(raw));
fclose(handle);
