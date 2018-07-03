#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Crea un kernel gaussiano cuadrado
cv::Mat gauss_kernel(const int &dimension,const float &stdev);

// Suma los elementos de un kernel
int suma_kernel(const cv::Mat &kernel);

// Crea un filtro pasa bajo todos uno
cv::Mat filtro_pb(const int &filas,const int &columnas);

#endif
