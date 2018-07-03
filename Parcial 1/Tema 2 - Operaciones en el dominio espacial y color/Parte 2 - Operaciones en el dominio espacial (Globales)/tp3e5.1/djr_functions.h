#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Binariza una imagen
cv::Mat umbral(cv::Mat imagen,int nivel_transicion);

// Umbral negativo
cv::Mat umbral_negativo(cv::Mat imagen,int nivel_transicion);

// Aplica una mascara a una imagen
cv::Mat multiplicacion(cv::Mat imagen1,cv::Mat imagen2);

// Suma dos imagenes
cv::Mat suma(cv::Mat imagen1,cv::Mat imagen2,float alfa);

#endif
