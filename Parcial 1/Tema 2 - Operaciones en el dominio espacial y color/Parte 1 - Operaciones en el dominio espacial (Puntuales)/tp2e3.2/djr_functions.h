#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Reduce el ruido haciendo el promedio de imagenes borrosas
cv::Mat reduccion_ruido(std::vector<cv::Mat> ruidosas);

// Genera imagenes con ruido gaussiano
std::vector<cv::Mat> imagenes_ruidosas(cv::Mat imagen,int cantidad,float media,float stdev);

#endif
