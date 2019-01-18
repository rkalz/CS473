raw = imread('raw.tiff');

% Write data about tiff to file
handle = fopen('hw1_473sp19.txt','w');
fprintf(handle, 'width:  %d\n', size(raw, 2));
fprintf(handle, 'height: %d\n', size(raw, 1));
fprintf(handle, 'type:   %s\n', class(raw(1,1)));
fprintf(handle, 'minimum pixel: %d\n', min(raw(:)));
fprintf(handle, 'maximum pixel: %d\n', max(raw(:)));
fclose(handle);

% Display raw image, then cast to double
% imshow(raw);
% title('raw image');
raw = double(raw);

fprintf('Program paused. Press enter to continue.\n');
% pause;

% linearization
black_level = 2047;
sat_level = 13584;

im_linear = raw;
im_linear(im_linear <= black_level) = 0;
im_linear(im_linear >= sat_level) = 1;
im_linear(im_linear > 1) = ...
    im_linear(im_linear > 1) / (black_level + sat_level);

% imshow(im_linear); 
% title('linearized image');
imwrite(im_linear, 'linearized.jpg');

fprintf('Program paused. Press enter to continue.\n');
% pause;

% bayer mosaic
im_zoom = im_linear(1000:1099, 901:1000);
im_zoom = im_zoom * 5;
im_zoom(im_zoom > 1) = 1;

imshow(im_zoom, 'InitialMagnification', 500);
title('bayer mosaic');
imwrite(im_zoom, 'zoomed.jpg')

fprintf('Program paused. Press enter to continue.\n');
% pause;

% extract bayer data
top_left = im_linear(1:end/2, 1:end/2);
top_right = im_linear(1:end/2, end/2:end);
bottom_left = im_linear(end/2:end, 1:end/2);
bottom_right = im_linear(end/2:end, end/2:end);

fprintf('Program paused. Press enter to continue.\n');
% pause;

