//
// Copyright 2019 <Rofael Aleezada>
//

#ifndef HW4_MAT_FILE_H_
#define HW4_MAT_FILE_H_

#include <string>
using std::string;

#include <opencv2/opencv.hpp>
using cv::Mat;
using cv::imread;
using cv::imwrite;

cv::Mat load_image_as_grayscale_float(const std::string& filepath);

void write_cv_32f_image(const std::string& filepath, cv::Mat& image);

#endif //HW4_MAT_FILE_H_
