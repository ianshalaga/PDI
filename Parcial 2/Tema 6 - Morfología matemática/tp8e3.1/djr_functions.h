#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Genera un elemento estructurante de 3x3
cv::Mat elemento_estructurante();

// Concatena imagenes verticalmente en escala de grises
cv::Mat concatenar_v_gray(std::vector<cv::Mat> imagenes);

// Binariza una imagen
cv::Mat umbral(cv::Mat imagen,int nivel_transicion);

// Binariza una imagen
cv::Mat umbral_negativo(cv::Mat imagen,int nivel_transicion);

// Suma los elementos de un kernel
int suma_kernel(const cv::Mat &kernel);

// Kernel pasa bajo
cv::Mat filtro_pb(const int &filas,const int &columnas);

// Aplica una mascara a una imagen
cv::Mat multiplicacion(cv::Mat imagen1,cv::Mat imagen2);

#endif
