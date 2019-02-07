% HW3 CSx73 Computer Vision, Johnstone 19sp
% hybrid images question
clear; close all; clc

% read the two images
im1 = imread("image_pairs/dog.bmp"); % low pass
im2 = imread("image_pairs/cat.bmp"); % high pass

% convert to double over [0,1] (need to allow negative values in hi-filtered)
im1 = double(im1) / 255.;
im2 = double(im2) / 255.;

viz_freq (im1, im2); % find G1 and G2 interactively

% choose G1 and G2 (and report to hw3_report.txt, you could do that by hand)

% G1 =
% G2 =

% build and visualize the hybrid image
[lo,hi,hybrid] = hybrid_image (im1, im2, G1, G2);

% save the hybrid image (e.g., dog/cat pair in 'dog_cat.jpg')

% repeat for each image pair

% challenge: design a more elegant way to cycle through the image pairs