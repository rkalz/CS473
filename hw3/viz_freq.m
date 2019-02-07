function viz_freq (img_lo, img_hi)
% display a 3x3 grid of the first image at progressively larger sigma
% which can be used to choose sigma
figure;
for sig = 1:9
    % low pass - blurring 
    filter = fspecial('gaussian', [31 31], sig);
    img = imfilter(img_lo, filter);
    
    subplot(3,3,sig)
    imshow(img)
    title("sigma = " + sig)
end

% display a 3x3 grid of various high-pass filtered images;
% remember to shift them by .5 for viewing
figure;
for sig = 1:9
    % high pass - subtract low pass from image
    filter = fspecial('gaussian', [31 31], sig);
    low_pass = imfilter(img_hi, filter);
    img = img_hi - low_pass;
    img = img + 0.5;
    
    subplot(3,3,sig)
    imshow(img)
    title("sigma = " + sig)
end

fprintf('Program paused. Press enter to continue.\n');
pause;