#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Genera un elemento estructurante de 3x3
cv::Mat elemento_estructurante();

// Imagen de prueba
cv::Mat imagen_prueba();

// Concatena imagenes horizontalmente en escala de grises
cv::Mat concatenar_h_gray(std::vector<cv::Mat> imagenes);

#endif
