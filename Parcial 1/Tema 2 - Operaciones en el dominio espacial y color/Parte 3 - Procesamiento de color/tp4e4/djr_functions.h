#ifndef ACHATAR_V_H
#define ACHATAR_V_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Dibuja el histograma de una imagen
cv::Mat draw_hist(const cv::Mat &histo);

// Calcula el promedio de intensidad de una imagen de un solo canal
int promedio(cv::Mat imagen);

std::vector<cv::Mat> segmentar(std::vector<cv::Mat> bgr_hsv,std::vector<cv::Mat> mascara);

#endif
