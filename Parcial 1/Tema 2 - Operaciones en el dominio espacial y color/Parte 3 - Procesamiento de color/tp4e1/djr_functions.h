#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Negativo del sistema de color HSV
std::vector<cv::Mat> negativo_hsv(std::vector<cv::Mat> hsv_vector);

// Negativo del sistema de color BGR
std::vector<cv::Mat> negativo_bgr(std::vector<cv::Mat> bgr_vector);

#endif
