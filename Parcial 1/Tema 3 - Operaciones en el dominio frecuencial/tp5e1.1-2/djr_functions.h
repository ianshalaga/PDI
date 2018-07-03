#ifndef ACHATAR_V_H
#define ACHATAR_V_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Dibuja una linea horizontal en el centro de la imagen
cv::Mat linea_h(cv::Mat imagen);

// Dibuja una linea horizontal en el centro de la imagen
cv::Mat linea_v(cv::Mat imagen);

// Dibuja un cuadrilatero en el centro de la imagen
cv::Mat cuadrilatero(cv::Mat imagen,int prop_x,int prop_y);

// Dibuja un circulo en el centro de la imagen
cv::Mat circulo(cv::Mat imagen,int radio);

#endif
