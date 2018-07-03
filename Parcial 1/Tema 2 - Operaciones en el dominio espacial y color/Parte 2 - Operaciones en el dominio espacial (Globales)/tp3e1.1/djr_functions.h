#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Planos de bits de 0 a 7
std::vector<cv::Mat> planos_bits(cv::Mat imagen);

// Binariza los planos de bits
std::vector<cv::Mat> planos_bits_bin(std::vector<cv::Mat> planos);

// Suma los planos de bits
std::vector<cv::Mat> suma_planos(std::vector<cv::Mat> planos);

// Dibuja el histograma de la imagen
cv::Mat draw_hist(const cv::Mat &histo);

// Desbinariza una imagen
cv::Mat desbinarizar(const cv::Mat &imagen,const int &bit);

// Binariza una imagen
cv::Mat umbral(cv::Mat imagen,int nivel_transicion);

#endif
