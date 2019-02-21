//
// Copyright 2019 <Rofael Aleezada>
//

#ifndef HW4_MAT_MATH_H_
#define HW4_MAT_MATH_H_

#include <cmath>
#include <string>

#include <opencv2/opencv.hpp>

cv::Mat load_image_as_grayscale_float(const std::string& filepath);

float single_filter(const cv::Mat& image, const cv::Mat& filter,
    int row, int col);

#endif  // HW4_MAT_MATH_H_
