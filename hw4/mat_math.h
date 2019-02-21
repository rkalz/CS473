//
// Created by Rofael Aleezada on 2019-02-20.
//

#ifndef HW4_MAT_MATH_H
#define HW4_MAT_MATH_H

#include <cmath>

#include <opencv2/opencv.hpp>

cv::Mat load_image_as_grayscale_float(const std::string& filepath);

float single_filter(const cv::Mat& image, const cv::Mat& filter,
    int row, int col);

#endif //HW4_MAT_MATH_H
