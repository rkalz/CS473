//
// Created by Rofael Aleezada on 2019-02-20.
//

#include "mat_math.h"

#include <iostream>

cv::Mat load_image_as_grayscale_float(const std::string& filepath) {
  cv::Mat uchar_gs_image = cv::imread(filepath, cv::IMREAD_GRAYSCALE);

  cv::Mat float_gs_image;
  uchar_gs_image.convertTo(float_gs_image, CV_32F, 1.0f/256.0f, 0);

  return float_gs_image;
}

float single_filter(const cv::Mat& image, const cv::Mat& filter,
                         int row, int col) {
  float result = 0.0f;
  const int mid_i = filter.rows / 2;
  const int mid_j = filter.cols / 2;

  for (int i = 0; i < filter.rows; i++) {
    int img_i = row + (i - mid_i);

    // imgradientxy.m:78 - Uses 'replicate' internally
    if (img_i < 0) img_i = 0;
    if (img_i >= image.rows) img_i = image.rows - 1;

    for (int j = 0; j < filter.cols; j++) {
      int img_j = col + (j - mid_j);
      
      if (img_j < 0) img_j = 0;
      if (img_j >= image.cols) img_j = image.cols - 1;

      result += image.at<float>(img_i, img_j) *
          filter.at<float>(i, j);
    }
  }

  return result;
}

