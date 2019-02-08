function viz_freq (img_lo, img_hi)

% precompute the gaussian filters
filters = zeros(31, 31, 9);
for sig = 1:9
    filters(:, :, sig) = fspecial('gaussian', [31 31], sig);
end

% display a 3x3 grid of the first image at progressively larger sigma
% which can be used to choose sigma
figure;
for sig = 1:9
    % low pass - blurring 
    img = imfilter(img_lo, filters(:, :, sig));
    
    subplot(3,3,sig)
    imshow(img)
    title("sigma = " + sig)
end

% display a 3x3 grid of various high-pass filtered images;
% remember to shift them by .5 for viewing
figure;
for sig = 1:9
    % high pass - subtract low pass from image
    low_pass = imfilter(img_hi, filters(:, :, sig));
    img = (img_hi - low_pass) + 0.5;
    
    subplot(3,3,sig)
    imshow(img)
    title("sigma = " + sig)
end

fprintf('Program paused. Press enter to continue.\n');
pause;