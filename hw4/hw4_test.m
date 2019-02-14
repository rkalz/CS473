clear; clc;

% Test script to make sure we're doing C++ stuff right

im_brick_wall = imread("brick_wall.jpg");
im_brick_wall = double(rgb2gray(im_brick_wall)) / 255.;
im_fed_center = imread("mies_van_der_rohe_chicago_federal_center.jpg");
im_fed_center = double(rgb2gray(im_fed_center)) / 255.;

[bw_fx, bw_fy] = gradient(im_brick_wall);
[fc_fx, fc_fy] = gradient(im_fed_center);

subplot(2, 2, 1); imshow(im_brick_wall);
subplot(2, 2, 3); imshow(bw_fx);
subplot(2, 2, 4); imshow(bw_fy);

figure;
subplot(2, 2, 1); imshow(im_fed_center);
subplot(2, 2, 3); imshow(fc_fx);
subplot(2, 2, 4); imshow(fc_fy);