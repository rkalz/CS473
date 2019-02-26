//
// Copyright 2019 <Rofael Aleezada>
//

#include "mat_file.h"

cv::Mat load_image_as_grayscale_float(const std::string& filepath) {
  cv::Mat image = cv::imread(filepath, cv::IMREAD_GRAYSCALE);
  image.convertTo(image, CV_32F, 1.0f/255.0f, 0);

  return image;
}

void write_cv_32f_image(const std::string& filepath, const cv::Mat& image) {
  cv::Mat image_to_write(image.rows, image.cols, image.type());
  image.convertTo(image_to_write, CV_8U, 255, 0);

  cv::imwrite(filepath, image_to_write);
}
