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

float single_filter(const cv::Mat& input, const cv::Mat& kernel,
                         int row, int col) {
  float result = 0.0f;
  const int mid_i = kernel.rows / 2;
  const int mid_j = kernel.cols / 2;

  for (int i = 0; i < kernel.rows; i++) {
    int input_i = row + (i - mid_i);

    // imgradientxy.m:78 - Uses 'replicate' internally
    if (input_i < 0) input_i = 0;
    if (input_i >= input.rows) input_i = input.rows - 1;

    for (int j = 0; j < kernel.cols; j++) {
      int input_j = col + (j - mid_j);
      if (input_j < 0) input_j = 0;
      if (input_j >= input.cols) input_j = input.cols - 1;

      result += input.at<float>(input_i, input_j) *
          kernel.at<float>(i, j);
    }
  }

  return result;
}

