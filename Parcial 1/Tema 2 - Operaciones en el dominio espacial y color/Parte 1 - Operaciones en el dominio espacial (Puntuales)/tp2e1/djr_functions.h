#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Acota los valores al rango que va entre 0 y 255
int ajuste(int intensidad);

// Ecuacion general de las transformaciones rectilineas
cv::Mat transformacion_rectilinea(cv::Mat lut_table,float a,float c);

// Tranformaciones rectilineas por tramos
cv::Mat transformacion_tramos(cv::Mat lut_table,std::vector<float> r,std::vector<float> s);

#endif
