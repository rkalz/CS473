//
// Copyright 2019 <Rofael Aleezada>
//

#ifndef HW4_SOBEL_GRADIENT_H_
#define HW4_SOBEL_GRADIENT_H_

#include <opencv2/opencv.hpp>
using cv::Mat;
using cv::Sobel;

#define PI 3.141592653f

cv::Mat sobel_gradient_magnitude(const cv::Mat& input);
cv::Mat sobel_gradient_direction(const cv::Mat& input);

#endif  // HW4_SOBEL_GRADIENT_H_
