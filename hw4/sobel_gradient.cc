//
// Created by Rofael Aleezada on 2019-02-20.
//

#include "sobel_gradient.h"

cv::Mat sobel_gradient_magnitude(const cv::Mat& input) {
  cv::Mat g_mag(input.rows, input.cols, input.type());

  float sobel_x_kernel_data[9] = {-1, 0, 1, 2, 0, 2, -1, 0, 1};
  float sobel_y_kernel_data[9] = {-1, 2, 1, 0, 0, 0, 1, 2, 1};
  cv::Mat x_kernel(3, 3, CV_32F, sobel_x_kernel_data);
  cv::Mat y_kernel(3, 3, CV_32F, sobel_y_kernel_data);

  for (int i = 0; i < input.rows; i++) {
    for (int j = 0; j < input.cols; j++) {
      auto gx = single_convolution(input, x_kernel, i, j);
      auto gy = single_convolution(input, y_kernel, i, j);

      float val = sqrtf(gx * gx + gy * gy);
      g_mag.at<float>(i, j) = val;
    }
  }

  return g_mag;
}

cv::Mat sobel_gradient_direction(const cv::Mat& input) {
  cv::Mat g_dir(input.rows, input.cols, input.type());

  float sobel_x_kernel_data[9] = {-1, 0, 1, 2, 0, 2, -1, 0, 1};
  float sobel_y_kernel_data[9] = {-1, 2, 1, 0, 0, 0, 1, 2, 1};
  cv::Mat x_kernel(3, 3, CV_32F, (void*)sobel_x_kernel_data);
  cv::Mat y_kernel(3, 3, CV_32F, (void*)sobel_y_kernel_data);

  return g_dir;
}

