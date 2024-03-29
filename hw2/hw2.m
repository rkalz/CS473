clear; clc;

raw = imread('raw.tiff');

% Write data about tiff to file
handle = fopen('hw2_473sp19.txt','w');
fprintf(handle, 'width:  %d\n', size(raw, 2));
fprintf(handle, 'height: %d\n', size(raw, 1));
fprintf(handle, 'type:   %s\n', class(raw(1,1)));
fprintf(handle, 'minimum pixel: %d\n', min(raw(:)));
fprintf(handle, 'maximum pixel: %d\n', max(raw(:)));

% Display raw image, then cast to double
imshow(raw);
title('raw image');
raw = double(raw);
fprintf('Program paused. Press enter to continue.\n');
pause;

% linearization
black_level = 2047;
sat_level = 13584;

im_linear = raw;
im_linear(im_linear <= black_level) = 0;
im_linear(im_linear >= sat_level) = 1;
im_linear(im_linear > 1) = ...
    im_linear(im_linear > 1) / (black_level + sat_level);

imshow(im_linear); 
title('linearized image');
imwrite(im_linear, 'linearized.jpg');
fprintf('Program paused. Press enter to continue.\n');
pause;

% bayer mosaic
im_zoom = im_linear(1000:1099, 901:1000);
im_zoom = im_zoom * 5;
im_zoom(im_zoom > 1) = 1;

imshow(im_zoom, 'InitialMagnification', 500);
title('bayer mosaic');
imwrite(im_zoom, 'zoomed.jpg')
fprintf('Program paused. Press enter to continue.\n');
pause;

% extract bayer data
top_left = im_linear(1:2:end, 1:2:end); 
bot_left = im_linear(2:2:end, 1:2:end); 
top_right = im_linear(1:2:end, 2:2:end);  
bot_right = im_linear(2:2:end, 2:2:end); 

im_rggb = 4 * cat(3, top_left, (top_right + bot_left) / 2, bot_right);
im_bggr = 4 * cat(3, bot_right, (top_right + bot_left) / 2, top_left);
im_grbg = 4 * cat(3, top_right, (top_left + bot_right) / 2, bot_left); 
im_gbrg = 4 * cat(3, bot_left, (top_left + bot_right) / 2, top_right);

subplot(2,2,1);
imshow(im_bggr);
title('BGGR');
subplot(2,2,2);
imshow(im_rggb);
title('RGGB');
subplot(2,2,3);
imshow(im_grbg);
title('GRBG');
subplot(2,2,4);
imshow(im_gbrg);
title('GBRG');
fprintf('Program paused. Press enter to continue.\n');
pause;

imwrite(im_rggb, 'best_bayer.jpg');
imshow(im_rggb);
title('best mosaic - RGGB');
fprintf(handle, 'best bayer mosaic: rggb\n');
fclose(handle);

fprintf('Program paused. Press enter to continue.\n');
pause;

% white balancing
red_channel = top_left;
green_channel = (top_right + bot_left) / 2;
blue_channel = bot_right;

red_avg = mean(red_channel, 'all');
red_max = max(red_channel(:));
green_avg = mean(green_channel, 'all');
green_max = max(green_channel(:));
blue_avg = mean(blue_channel, 'all');
blue_max = max(blue_channel(:));

im_gray_world = im_linear;
im_gray_world(1:2:end, 1:2:end) = ...
    im_gray_world(1:2:end, 1:2:end) * (green_avg / red_avg);
im_gray_world(2:2:end, 2:2:end) = ...
    im_gray_world(2:2:end, 2:2:end) * (green_avg / blue_avg);

im_white_world = im_linear;
im_white_world(1:2:end, 1:2:end) = ...
    im_white_world(1:2:end, 1:2:end) * (green_max / red_max);
im_white_world(2:2:end, 2:2:end) = ...
    im_white_world(2:2:end, 2:2:end) * (green_max / blue_max);

subplot(2,1,1);
imshow(im_gray_world);
title('gray world');
subplot(2,1,2);
imshow(im_white_world);
title('white world');

imwrite(im_gray_world, 'gray_world.jpg')
imwrite(im_white_world, 'white_world.jpg')


