#ifndef ACHATAR_V_H
#define ACHATAR_V_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Parte una imagen a la mitad
std::vector<cv::Mat> partir_mitad(const cv::Mat &imagen,const bool &tipo);

// Promedios verticales de intensidades
cv::Mat promedio_intensidad_v(const cv::Mat &imagen);

// Binariza una imagen
cv::Mat umbral(const cv::Mat &imagen,const int &nivel_transicion);

// XOR
cv::Mat or_exclusivo(const cv::Mat &imagen1,const cv::Mat &imagen2);

// Filtro pasa bajo
cv::Mat filtro_pb(const int &filas,const int &columnas);

// Marca los principios y finales de los tramos blancos
std::vector<int> blancos(const cv::Mat &perfil_v);

#endif
