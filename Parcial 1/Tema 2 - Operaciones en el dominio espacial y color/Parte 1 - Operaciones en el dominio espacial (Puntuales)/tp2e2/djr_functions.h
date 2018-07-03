#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Acota los valores al rango que va entre 0 y 255
int ajuste(int intensidad);

// Transformacion logaritmica
cv::Mat transformacion_logaritmica(cv::Mat lut_table,float c);

// Transformacion de potencia
cv::Mat transformacion_potencia(cv::Mat lut_table,float c,float gamma);

#endif
