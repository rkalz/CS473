//
// Created by Rofael Aleezada on 2019-02-20.
//

#ifndef HW4_SOBEL_GRADIENT_H
#define HW4_SOBEL_GRADIENT_H

#include <opencv2/opencv.hpp>

#include "mat_math.h"
#include <iostream>

#define PI 3.141592653f

cv::Mat sobel_gradient_magnitude(const cv::Mat& input);
cv::Mat sobel_gradient_direction(const cv::Mat& input);

#endif //HW4_SOBEL_GRADIENT_H
