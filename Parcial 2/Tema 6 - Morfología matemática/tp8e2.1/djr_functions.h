#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Genera un elemento estructurante de 3x3
cv::Mat elemento_estructurante();

// Concatena imagenes horizontalmente en escala de grises
cv::Mat concatenar_h_gray(std::vector<cv::Mat> imagenes);

// Concatena imagenes verticalmente en escala de grises
cv::Mat concatenar_v_gray(std::vector<cv::Mat> imagenes);

// Apertura
cv::Mat apertura(const cv::Mat &imagen,const cv::Mat &elem_estruc);

// Cierre
cv::Mat cierre(const cv::Mat &imagen,const cv::Mat &elem_estruc);

#endif
