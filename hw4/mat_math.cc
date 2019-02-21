//
// Created by Rofael Aleezada on 2019-02-20.
//

#include "mat_math.h"

cv::Mat load_image_as_grayscale_float(const std::string& filepath) {
  cv::Mat uchar_gs_image = cv::imread(filepath, cv::IMREAD_GRAYSCALE);

  cv::Mat float_gs_image;
  uchar_gs_image.convertTo(float_gs_image, CV_32F, 1.0f/255.0f, 0);

  return float_gs_image;
}

float single_convolution(const cv::Mat& input, const cv::Mat& kernel,
                         int row, int col) {
  float result = 0.0f;

  const int mid_of_kernel_x = (int)floor(kernel.rows / 2);
  const int mid_of_kernel_y = (int)floor(kernel.cols / 2);

  for (int i = 0; i < kernel.rows; i++) {
    int kern_i = kernel.rows - 1 - i;

    for (int j = 0; j < kernel.cols; j++) {
      int kern_j = kernel.cols - 1 - j;

      int input_i = row + (mid_of_kernel_y - kern_i);
      int input_j = col + (mid_of_kernel_x - kern_j);

      if (input_i >= 0 && input_i < input.rows
          && input_j >= 0 && input_j < input.cols) {
        result += input.at<float>(input_i, input_j) *
            kernel.at<float>(kern_i, kern_j);
      }
    }
  }

  return result;
}

