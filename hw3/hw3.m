% HW3 CSx73 Computer Vision, Johnstone 19sp
% hybrid images question
clear; close all; clc

% This program reads the images from the subdirectory 'image_pairs'
% And writes the combinatuons to the subdirectory 'output'
low_pass  = ["dog", "motorcycle", "marilyn", "submarine", "plane"];
g1_vals   = [8    , 4           , 3        , 4          , 7      ];
high_pass = ["cat", "bicycle"   , "albert",  "fish"     , "bird" ];
g2_vals   = [8    , 3           , 4        , 5          , 4      ];

for i = 1:5
    low_pass_name = low_pass(i);
    high_pass_name = high_pass(i);
    
    % read the two images
    im1 = imread("image_pairs/" + low_pass_name + ".bmp"); % low pass
    im2 = imread("image_pairs/" + high_pass_name + ".bmp"); % high pass

    % convert to double over [0,1] (need to allow negative values in hi-filtered)
    im1 = double(rgb2gray(im1)) / 255.;
    im2 = double(rgb2gray(im2)) / 255.;

    viz_freq (im1, im2); % find G1 and G2 interactively
    % choose G1 and G2 (and report to hw3_report.txt, you could do that by hand)
    G1 = g1_vals(i);
    G2 = g2_vals(i);

    % build and visualize the hybrid image
    [lo,hi,hybrid] = hybrid_image (im1, im2, G1, G2);

    % save the hybrid image (e.g., dog/cat pair in 'dog_cat.jpg')
    imwrite(hybrid, 'output/' + low_pass_name + '_' + high_pass_name + ...
        '.jpeg');

    % repeat for each image pair
end

% challenge: design a more elegant way to cycle through the image pairs