clear; clc;

% Test script to make sure we're doing C++ stuff right

im_brick_wall = imread("brick_wall.jpg");
im_brick_wall = double(rgb2gray(im_brick_wall)) / 255.;
im_fed_center = imread("federal_center.jpg");
im_fed_center = double(rgb2gray(im_fed_center)) / 255.;

[bw_mag, bw_dir] = imgradient(im_brick_wall);
figure;
imshow(bw_dir);