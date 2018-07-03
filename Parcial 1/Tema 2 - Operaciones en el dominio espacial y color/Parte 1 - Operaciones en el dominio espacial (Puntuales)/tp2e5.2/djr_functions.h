#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Promedios verticales de intensidad
cv::Mat promedio_intensidad_v(const cv::Mat &imagen);

// Promedios horizontales de intensidad
cv::Mat promedio_intensidad_h(const cv::Mat &imagen);

// Promedio de intensidad total de la imagen
int promedio_intensidad(const cv::Mat &imagen);

#endif
