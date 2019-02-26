//
// Copyright 2019 <Rofael Aleezada>
//

#include <string>
using std::string;

#include <opencv2/opencv.hpp>
using cv::Mat;
using cv::namedWindow;
using cv::imshow;
using cv::waitKey;
using cv::destroyAllWindows;

#include "mat_file.h"
#include "sobel_gradient.h"

#ifndef PROJECT_DIR
#define PROJECT_DIR ".."
#endif

int main() {
  std::string project_dir = PROJECT_DIR;

  // Get magnitude and directon on custom image
  cv::Mat image = load_image_as_grayscale_float(project_dir + "/einstein.jpg");

  cv::Mat gmag = sobel_gradient_magnitude(image);
  cv::Mat gdir = sobel_gradient_direction(image);

  //cv::namedWindow("Gradient Magnitude", cv::WINDOW_NORMAL);
  //cv::imshow("Gradient Magnitude", gmag);

  //cv::namedWindow("Gradient Direction", cv::WINDOW_NORMAL);
  //cv::imshow("Gradient Direction", gdir);

  //cv::waitKey(0);

  write_cv_32f_image(project_dir + "/einstein_gmag.jpg", gmag);
  write_cv_32f_image(project_dir + "/einstein_gdir.jpg", gdir);

  // Find edges for provided images
  auto image_names = {"brick_wall", "federal_center"};
  for (auto& name : image_names) {
    image = load_image_as_grayscale_float(project_dir + "/" + name + ".jpg");

    cv::Mat edges = sobel_find_edges(image, 0.5f);

    cv::namedWindow("Gradient Edges", cv::WINDOW_NORMAL);
    cv::imshow("Gradient Edges", edges);
    cv::waitKey(0);

    write_cv_32f_image(project_dir + "/" + name + "_edges.jpg", edges);
  }

  cv::destroyAllWindows();

  return 0;
}

