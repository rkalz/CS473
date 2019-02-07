function [im1_lo, im2_hi, im_hybrid] = hybrid_image (im1, im2, G1, G2)

% after computing the 3 output images, display all the iamges:
% in a 3x2 grid, display the 2 original images (first row),
% low-pass-filtered and high-pass filtered images (second row),
% and hybrid image (3rd row)