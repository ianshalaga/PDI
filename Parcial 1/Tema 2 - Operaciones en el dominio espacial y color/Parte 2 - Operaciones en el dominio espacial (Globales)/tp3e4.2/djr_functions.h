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

// Crea un kernel pasa alto suma cero o uno
cv::Mat filtro_pa(int filas,int columnas,int suma);

// Suma dos imagenes
cv::Mat suma(cv::Mat imagen1,cv::Mat imagen2,float alfa);

// Resta imagen2 a imagen1
cv::Mat resta(cv::Mat imagen1,cv::Mat imagen2);

// Filtrado de alta potencia
cv::Mat alta_potencia(const cv::Mat imagen,const float A,const cv::Mat kernel,const int version);

#endif
