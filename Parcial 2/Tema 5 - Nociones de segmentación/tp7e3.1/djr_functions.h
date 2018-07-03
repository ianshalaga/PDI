#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Binariza una imagen
cv::Mat umbral(const cv::Mat &imagen,const int &nivel_transicion);

// Concatena horizontalmente varias imagenes
cv::Mat concatenar_h(std::vector<cv::Mat> imagenes);

// Concatena verticalmente varias imagenes
cv::Mat concatenar_v(std::vector<cv::Mat> imagenes);

#endif
