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

int main() {
  std::string project_dir = PROJECT_DIR;

  // Get magnitude and directon on custom image
  cv::Mat image = load_image_as_grayscale_float(project_dir + "/einstein.jpg");

  cv::Mat g_mag = sobel_gradient_magnitude(image);
  cv::Mat g_dir = sobel_gradient_direction(image);

  // cv::namedWindow("Gradient Magnitude", cv::WINDOW_NORMAL);
  // cv::imshow("Gradient Magnitude", g_mag);

  // cv::namedWindow("Gradient Direction", cv::WINDOW_NORMAL);
  // cv::imshow("Gradient Direction", g_dir);

  // cv::waitKey(0);

  write_cv_32f_image(project_dir + "/einstein_gmag.jpg", g_mag);
  write_cv_32f_image(project_dir + "/einstein_gdir.jpg", g_dir);

  // Find edges for provided images
  const char* image_names[] = {"/brick_wall", "/federal_center"};
  float image_thresh[] = {0.275f, 0.1f};

  for (int i = 0; i < 2; i++) {
    image =
        load_image_as_grayscale_float(project_dir + image_names[i] + ".jpg");

    cv::Mat im_edges = sobel_find_edges(image, image_thresh[i]);

    // cv::namedWindow("Gradient Edges", cv::WINDOW_NORMAL);
    // cv::imshow("Gradient Edges", im_edges);
    // cv::waitKey(0);

    write_cv_32f_image(project_dir + image_names[i] + "_edges.jpg", im_edges);
  }

  std::cout << "Program ran successfully. ";
  std::cout << "Files written to executable directory." << std::endl;
  cv::destroyAllWindows();

  return 0;
}

