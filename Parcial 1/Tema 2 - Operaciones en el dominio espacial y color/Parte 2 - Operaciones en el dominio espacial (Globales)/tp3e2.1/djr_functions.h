#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Suma de los elementos del kernel
int suma_kernel(const cv::Mat &kernel);

// Kernel de promediado todos uno
cv::Mat filtro_pb(const int &filas,const int &columnas);

#endif
