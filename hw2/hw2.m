raw = imread('raw.tiff');

% Write data about tiff to file
handle = fopen('hw1_473sp19.txt','w');
fprintf(handle, 'width: %d\n', size(raw, 2));
fprintf(handle, 'height: %d\n', size(raw, 1));
fprintf(handle, 'type: %s\n', class(raw(1,1)));
fprintf(handle, 'minimum pixel: %d\n', min(raw(:)));
fprintf(handle, 'maximum pixel: %d\n', max(raw(:)));
fclose(handle);

% Display raw image, then cast to double
title('raw image');
imshow(raw);
raw = double(raw);

