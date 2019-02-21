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
  std::string project_dir = PROJECT_DIR;
  auto image = load_image_as_grayscale_float(project_dir + "/brick_wall.jpg");

  auto gmag = sobel_gradient_magnitude(image);
  auto gdir = sobel_gradient_direction(image);

  cv::namedWindow("Gradient Magnitude", cv::WINDOW_AUTOSIZE);
  cv::namedWindow("Gradient Direction", cv::WINDOW_AUTOSIZE);
  cv::imshow("Gradient Magnitude", gmag);
  cv::imshow("Gradient Direction", gdir);
  cv::waitKey(0);

  return 0;
}

