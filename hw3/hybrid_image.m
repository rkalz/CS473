function [im1_lo, im2_hi, im_hybrid] = hybrid_image (im1, im2, G1, G2)

% after computing the 3 output images, display all the iamges:
% in a 3x2 grid, display the 2 original images (first row),
% low-pass-filtered and high-pass filtered images (second row),
% and hybrid image (3rd row)
filter = fspecial('gaussian', 31, G1);
im1_lo = imfilter(im1, filter);

if G1 ~= G2
    % Compute other Gaussian filter only if sigmas are different
    filter = fspecial('gaussian', 31, G2);
end

im2_hi = im2 - imfilter(im2, filter);
im_hybrid = im1_lo + im2_hi;

subplot(3,2,1);
imshow(im1);

subplot(3,2,2);
imshow(im2);

subplot(3,2,3);
imshow(im1_lo);
title('Low Pass');

subplot(3,2,4);
imshow(im2_hi + 0.5);
title('High Pass (Brightened)');

subplot(3,2,5);
imshow(im_hybrid);
title('Hybrid');

figure;
imshow(im_hybrid);

fprintf('Program paused. Press enter to continue.\n');
pause;

return