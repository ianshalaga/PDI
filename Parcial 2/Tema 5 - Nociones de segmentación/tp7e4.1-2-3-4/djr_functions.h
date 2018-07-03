#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Binariza una imagen
cv::Mat umbral(const cv::Mat &imagen,const int &nivel_transicion);

// Concatena horizontalmente varias imagenes
cv::Mat concatenar_h(std::vector<cv::Mat> imagenes);

// Concatena verticalmente varias imagenes
cv::Mat concatenar_v(std::vector<cv::Mat> imagenes);

// Genera el histograma de una imagen
cv::Mat draw_hist(const cv::Mat &histo);

// Promedios horizontales de intensidad
cv::Mat promedio_intensidad_h(const cv::Mat &imagen);

// Promedios verticales de intensidad
cv::Mat promedio_intensidad_v(const cv::Mat &imagen);

// Promedio de intensidad total
int promedio_intensidad(const cv::Mat &imagen);

// Interseccion de mascaras
cv::Mat and_mascaras(const std::vector<cv::Mat> &mascaras);

// Aplica la mascara imagen2 a la imagen1
cv::Mat multiplicacion(const cv::Mat &imagen1,const cv::Mat &imagen2);

// Concatena imagenes horizontalmente resultando en un canal
cv::Mat concatenar_h_gray(std::vector<cv::Mat> imagenes);

// Concatena imagenes verticalmente resultando en un canal
cv::Mat concatenar_v_gray(std::vector<cv::Mat> imagenes);

// Concatena imagenes horizontalmente resultando en tres canales
cv::Mat concatenar_h_color(std::vector<cv::Mat> imagenes);

// Concatena imagenes verticalmente resultando en tres canales
cv::Mat concatenar_v_color(std::vector<cv::Mat> imagenes);

// Binariza una imagen
cv::Mat umbral(const cv::Mat &imagen,const int &nivel_transicion);

// Kernel gaussiano cuadrado
cv::Mat gauss_kernel(const int &dimension,const float &stdev);

// Dibuja circulos en la posicion de los centroides
cv::Mat dibujar_circulos(const cv::Mat &imagen,const cv::Mat &centroides,const int &radio);

// Promedio de dos imagenes
cv::Mat suma(const cv::Mat &imagen1,const cv::Mat &imagen2,const float &alfa);

#endif
