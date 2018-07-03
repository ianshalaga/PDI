#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Concatena horizontalmente varias imagenes
cv::Mat concatenar_h(std::vector<cv::Mat> imagenes);

// Concatena verticalmente varias imagenes
cv::Mat concatenar_v(std::vector<cv::Mat> imagenes);

cv::Mat lineas_hough(const cv::Mat &bordes,const std::vector<cv::Vec2f> &rho_tita);

cv::Mat lineas_houghP(const cv::Mat &bordes,const std::vector<cv::Vec4i> &ini_fin);

#endif
