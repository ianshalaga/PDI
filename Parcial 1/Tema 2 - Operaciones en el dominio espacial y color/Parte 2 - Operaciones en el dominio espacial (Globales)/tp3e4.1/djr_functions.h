#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Suma los elementos de un kernel
int suma_kernel(const cv::Mat &kernel);

// Crea un kernel pasa bajo todos uno
cv::Mat filtro_pb(const int &filas,const int &columnas);

// Resta imagen2 a imagen1
cv::Mat resta(cv::Mat imagen1,cv::Mat imagen2);

// Filtrado de mascara difusa
cv::Mat mascara_difusa(const cv::Mat &imagen,const cv::Mat &kernel_pb);

// Concatena imagenes
cv::Mat concatenar_imagenes(std::vector<cv::Mat> imagenes,const bool &color,const bool &vertical);

#endif
