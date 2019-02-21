//
// Copyright 2019 <Rofael Aleezada>
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

  auto image_paths = {"/brick_wall.jpg", "/federal_center.jpg"};

  for (auto& path : image_paths) {
    auto image = load_image_as_grayscale_float(project_dir + path);

    auto gmag = sobel_gradient_magnitude(image);
    auto gdir = sobel_gradient_direction(image);

    cv::namedWindow("Gradient Magnitude", cv::WINDOW_NORMAL);
    cv::imshow("Gradient Magnitude", gmag);

    cv::namedWindow("Gradient Direction", cv::WINDOW_NORMAL);
    cv::imshow("Gradient Direction", gdir);

    cv::waitKey(0);
  }

  return 0;
}

