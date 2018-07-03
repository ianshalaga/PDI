#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Binariza una imagen
cv::Mat umbral(const cv::Mat &imagen,const int &nivel_transicion);

// Interseccion de mascaras binarias
cv::Mat and_mascaras(const std::vector<cv::Mat> &mascaras);

// Union de mascaras
cv::Mat or_mascaras(const std::vector<cv::Mat> &mascaras);

// Kernel pasa-alto suma uno o cero
cv::Mat filtro_pa(const int &filas,const int &columnas,const int &suma);

// Kernel pasa-altos suma cero para detectar lineas horizontales
cv::Mat filtro_pa_sc_lh(const int &filas,const int &columnas);

// Kernel pasa-altos suma cero para detectar lineas verticales
cv::Mat filtro_pa_sc_lv(const int &filas,const int &columnas);

// Kernel pasa-altos suma cero para detectar lineas diagonales (matriz)
cv::Mat filtro_pa_sc_ld(const int &filas,const int &columnas);

// Kernel pasa-altos suma cero para detectar lineas diagonales invertidas (matriz)
cv::Mat filtro_pa_sc_ldi(const int &filas,const int &columnas);

// Detector de lineas pasa-altos suma cero
cv::Mat filtro_pa_sc_l(const cv::Mat &imagen,const int &filas,const int &columnas,const int &nt);

// Kernel Roberts diagonal
cv::Mat roberts_d();

// Kernel Roberts diagonal invertida
cv::Mat roberts_di();

// Detector de bordes Roberts
cv::Mat filtro_roberts(const cv::Mat &imagen,const int &nt);

#endif
