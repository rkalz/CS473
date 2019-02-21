//
// Copyright 2019 <Rofael Aleezada>
//

#include "sobel_gradient.h"

cv::Mat sobel_gradient_magnitude(const cv::Mat& input) {
  cv::Mat gmag(input.rows, input.cols, input.type());

  cv::Mat x_der, y_der;
  cv::Sobel(input, x_der, CV_32F, 1, 0);
  cv::Sobel(input, y_der, CV_32F, 0, 1);

  for (int i = 0; i < input.rows; i++) {
    for (int j = 0; j < input.cols; j++) {
      float gx = x_der.at<float>(i, j);
      float gy = y_der.at<float>(i, j);

      float val = sqrtf(gx * gx + gy * gy);
      gmag.at<float>(i, j) = val;
    }
  }

  return gmag;
}

cv::Mat sobel_gradient_direction(const cv::Mat& input) {
  cv::Mat gdir(input.rows, input.cols, input.type());

  cv::Mat x_der, y_der;
  cv::Sobel(input, x_der, CV_32F, 1, 0);
  cv::Sobel(input, y_der, CV_32F, 0, 1);

  for (int i = 0; i < input.rows; i++) {
    for (int j = 0; j < input.cols; j++) {
      float gx = x_der.at<float>(i, j);
      float gy = y_der.at<float>(i, j);

      // imgradient.m:127 - gy is negated
      // lock to [0,1] to fix weird inverse shading
      float val = (atan2(-gy, gx) + PI) / (2.0f * PI);
      gdir.at<float>(i, j) = val;
    }
  }

  return gdir;
}

