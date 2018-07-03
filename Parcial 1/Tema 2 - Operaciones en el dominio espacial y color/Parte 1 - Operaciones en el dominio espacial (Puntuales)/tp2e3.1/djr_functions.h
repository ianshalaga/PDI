#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Ajusta los valores de intensidad al rango 0 - 255
int ajuste(int intensidad);

// Promedio de dos imagenes
cv::Mat suma(cv::Mat imagen1,cv::Mat imagen2,float alfa);

// Diferencia (resta) entre dos imagenes
cv::Mat resta(cv::Mat imagen1,cv::Mat imagen2);

// Producto entre dos imagenes (la segunda es una mascara binaria)
cv::Mat multiplicacion(cv::Mat imagen1,cv::Mat imagen2);

// Producto de una imagen por el reciproco de la otra
cv::Mat division(cv::Mat imagen1,cv::Mat imagen2);

// Dibuja un circulo en el centro de la imagen
cv::Mat circulo(cv::Mat imagen,int radio);

// Dibuja un cuadrilatero en el centro de la imagen
cv::Mat cuadrilatero(cv::Mat imagen,int prop_x,int prop_y);

#endif
