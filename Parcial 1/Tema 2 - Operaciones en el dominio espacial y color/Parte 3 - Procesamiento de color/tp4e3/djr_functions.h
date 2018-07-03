#ifndef ACHATAR_V_H
#define ACHATAR_V_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Dibuja el histograma de una imagen
cv::Mat draw_hist(const cv::Mat &histo);

// Filtro pasa alto
cv::Mat filtro_pa(int filas,int columnas,int suma);

#endif
