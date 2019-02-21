//
// Created by Rofael Aleezada on 2019-02-20.
//

#include "sobel_gradient.h"

float sobel_x_filter_data[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
float sobel_y_filter_data[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
cv::Mat sobel_x_filter(3, 3, CV_32F, sobel_x_filter_data);
cv::Mat sobel_y_filter(3, 3, CV_32F, sobel_y_filter_data);

cv::Mat sobel_gradient_magnitude(const cv::Mat& input) {
  cv::Mat g_mag(input.rows, input.cols, input.type());

  for (int i = 0; i < input.rows; i++) {
    for (int j = 0; j < input.cols; j++) {
      // TODO: Multithreading
      auto gx = single_filter(input, sobel_x_filter, i, j);
      auto gy = single_filter(input, sobel_y_filter, i, j);

      float val = sqrtf(gx * gx + gy * gy);
      g_mag.at<float>(i, j) = val;
    }
  }

  return g_mag;
}

cv::Mat sobel_gradient_direction(const cv::Mat& input) {
  cv::Mat g_dir(input.rows, input.cols, input.type());

  for (int i = 0; i < input.rows; i++) {
    for (int j = 0; j < input.cols; j++) {
      auto gx = single_filter(input, sobel_x_filter, i, j);
      auto gy = single_filter(input, sobel_y_filter, i, j);

      // imgradient.m:127 - gy is negated
      float val = (atan2(-gy, gx) + PI) / (2 * PI);
      g_dir.at<float>(i, j) = val;
    }
  }

  return g_dir;
}

