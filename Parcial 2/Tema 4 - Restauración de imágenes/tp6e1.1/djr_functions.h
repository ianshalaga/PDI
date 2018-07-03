#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Agrega ruido gaussiano a una imagen
cv::Mat ruido_gaussiano(const cv::Mat &imagen,const float &media,const float &stdev);

// Agrega ruido impulsivo a una imagen
cv::Mat ruido_impulsivo(const cv::Mat &imagen,const int &bajo,const int &alto);

// Dibuja el histograma de una imagen
cv::Mat draw_hist(const cv::Mat &histo);

// Concatena imagenes verticalmente en escala de grises
cv::Mat concatenar_v_gray(std::vector<cv::Mat> imagenes);

// Concatena imagenes horizontalmente en escala de grises
cv::Mat concatenar_h_gray(std::vector<cv::Mat> imagenes);

// Concatena imagenes verticalmente en color
cv::Mat concatenar_v_color(std::vector<cv::Mat> imagenes);

// Concatena imagenes horizontalmente en color
cv::Mat concatenar_h_color(std::vector<cv::Mat> imagenes);

// Binariza una imagen
cv::Mat umbral(const cv::Mat &imagen,const int &nivel_transicion);

// Binariza una imagen
cv::Mat umbral_negativo(cv::Mat imagen,int nivel_transicion);

// Suma los elementos de un kernel
int suma_kernel(const cv::Mat &kernel);

// Kernel pasa bajo
cv::Mat filtro_pb(const int &filas,const int &columnas);

// Aplica una mascara a una imagen
cv::Mat multiplicacion(cv::Mat imagen1,cv::Mat imagen2);

// Aplica una mascara a una imagen
cv::Mat multiplicacion(cv::Mat imagen1,cv::Mat imagen2);

// Interseccion de mascaras binarias
cv::Mat and_mascaras(const std::vector<cv::Mat> &mascaras);

cv::Mat objetos_borde(const cv::Mat &mascara);

cv::Mat rellenar(cv::Mat mascara);

#endif
