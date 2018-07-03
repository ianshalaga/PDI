#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Kernel pasa-altos suma uno o cero
cv::Mat filtro_pa(const int &filas,const int &columnas,const int &suma);

// Binariza una imagen
cv::Mat umbral(const cv::Mat &imagen,const int &nivel_transicion);

// Interseccion de mascaras binarias
cv::Mat and_mascaras(const std::vector<cv::Mat> &mascaras);

// Union de mascaras
cv::Mat or_mascaras(const std::vector<cv::Mat> &mascaras);

// Detector de bordes Prewitt (distribucion horizontal)
cv::Mat prewitt_h();

// Detector de bordes Prewitt (distribucion vertical)
cv::Mat prewitt_v();

// Detector de bordes Prewitt (distribucion diagonal)
cv::Mat prewitt_d();

// Detector de bordes Prewitt (distribucion diagonal invertida)
cv::Mat prewitt_di();

// Detector de bordes Prewitt
cv::Mat filtro_prewitt(const cv::Mat &imagen,const int &nt);

// Kernel Sobel horizontal
cv::Mat sobel_h();

// Kernel Sobel vertical
cv::Mat sobel_v();

// Kernel Sobel diagonal
cv::Mat sobel_d();

// Kernel Sobel diagonal invertida
cv::Mat sobel_di();

// Detector de bordes Sobel
cv::Mat filtro_sobel(const cv::Mat &imagen,const int &nt);

// Detector de bordes Laplaciano en cruz
cv::Mat laplaciano_n4();

// Detector de bordes Laplaciano completo
cv::Mat laplaciano_n8();

// Kernel gaussiano cuadrado
cv::Mat gauss_kernel(const int &dimension,const float &stdev);

// Kernel laplaciano del gaussiano 5x5
cv::Mat lap_of_gauss();

#endif
