clear; clc;

% Test script to make sure we're doing C++ stuff right

im_brick_wall = imread("brick_wall.jpg");
im_brick_wall = double(rgb2gray(im_brick_wall)) / 255.;
im_fed_center = imread("federal_center.jpg");
im_fed_center = double(rgb2gray(im_fed_center)) / 255.;
im_einstein = imread("einstein.jpg");
im_einstein = double(rgb2gray(im_einstein)) / 255.;

[ein_mag, ein_dir] = imgradient(im_einstein);

norm_bw = im_brick_wall - min(im_brick_wall(:));
norm_bw = norm_bw / max(im_brick_wall(:));
bw_edge = edge(norm_bw);

norm_fc = im_fed_center - min(im_fed_center(:));
norm_fc = norm_fc / max(im_fed_center(:));
fc_edge = edge(norm_fc);

figure;
subplot(2,2,1);
imshow(ein_mag);
subplot(2,2,2);
imshow(ein_dir);
subplot(2,2,3);
imshow(bw_edge);
subplot(2,2,4);
imshow(fc_edge);