#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

cv::Mat concatenar_v_gray(std::vector<cv::Mat> imagenes);

cv::Mat concatenar_v_color(std::vector<cv::Mat> imagenes);

#endif
