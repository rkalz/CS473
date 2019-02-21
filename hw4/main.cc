//
// Created by Rofael Aleezada on 2019-02-20.
//

#include <string>

#include <opencv2/opencv.hpp>

#include "mat_math.h"
#include "sobel_gradient.h"

#ifndef PROJECT_DIR
#define PROJECT_DIR ".."
#endif

int main() {
  std::string path_to_image = PROJECT_DIR;
  path_to_image += "/brick_wall.jpg";
  auto image = load_image_as_grayscale_float(path_to_image);

  auto gmag = sobel_gradient_magnitude(image);

  cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
  cv::imshow("Display Image", gmag);
  cv::waitKey(0);

  return 0;
}

