//
// Copyright 2019 <Rofael Aleezada>
//

#include "sobel_gradient.h"

cv::Mat sobel_gradient_magnitude(const cv::Mat& input) {
  cv::Mat g_mag(input.rows, input.cols, input.type());

  cv::Mat x_der, y_der;
  cv::Sobel(input, x_der, CV_32F, 1, 0);
  cv::Sobel(input, y_der, CV_32F, 0, 1);

  for (int i = 0; i < input.rows; i++) {
    for (int j = 0; j < input.cols; j++) {
      float gx = x_der.at<float>(i, j);
      float gy = y_der.at<float>(i, j);

      float val = std::sqrtf(gx * gx + gy * gy);
      g_mag.at<float>(i, j) = val;
    }
  }

  cv::normalize(g_mag, g_mag, 0.0f, 1.0f, cv::NORM_MINMAX, CV_32F);
  return g_mag;
}

cv::Mat sobel_gradient_direction(const cv::Mat& input, float direction,
    float threshold) {
  cv::Mat g_dir(input.rows, input.cols, input.type());
  float min = ((direction - threshold) < -PI) ? -PI : direction - threshold;
  float max = ((direction + threshold) > PI) ? PI : direction + threshold;

  cv::Mat x_der, y_der;
  cv::Sobel(input, x_der, CV_32F, 1, 0);
  cv::Sobel(input, y_der, CV_32F, 0, 1);

  for (int i = 0; i < input.rows; i++) {
    for (int j = 0; j < input.cols; j++) {
      float gx = x_der.at<float>(i, j);
      float gy = y_der.at<float>(i, j);

      // imgradient.m:127 - gy is negated
      // lock to [0,1] to fix weird inverse shading
      float val = std::atan2(-gy, gx);
      if (val >= min && val <= max) g_dir.at<float>(i, j) = 1.0f;
      else g_dir.at<float>(i, j) = 0.0f;
    }
  }

  return g_dir;
}

cv::Mat sobel_find_edges(const cv::Mat& image, float threshold) {
  auto g_mag = sobel_gradient_magnitude(image);
  cv::Mat im_edges(g_mag.rows, g_mag.cols, g_mag.type());

  for (int i = 0; i < g_mag.rows; i++) {
    for (int j = 0; j < g_mag.cols; j++) {
      if (g_mag.at<float>(i, j) >= threshold) {
        im_edges.at<float>(i, j) = 1.0f;
      } else {
        im_edges.at<float>(i, j) = 0.0f;
      }
    }
  }

  return im_edges;
}

