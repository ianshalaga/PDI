#ifndef ACHATAR_V_H
#define ACHATAR_V_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "vector"

// Achatamiento vertical, cada columna es el promedio de intensidades de dicha columna
cv::Mat achatar_v(cv::Mat imagen);

// Achatamiento horizontal, cada fila es el promedio de intensidades de dicha fila
cv::Mat achatar_h(cv::Mat imagen);

// Binariza la imagen
cv::Mat umbral(cv::Mat imagen,int nivel_transicion);
cv::Mat umbral_negativo(cv::Mat imagen,int nivel_transicion);

// Posiciones de las botellas en la imagen
std::vector<int> botellas(cv::Mat perfil_v);

// Promedio de intensidades de las areas correspondientes a las botellas
std::vector<int> promedio_intensidad(cv::Mat imagen,std::vector<int> botellas);

// Posiciones de las botellas vacias en la imagen
std::vector<int> no_llenas(std::vector<int> botellas,std::vector<int> promedios);

// Determina el porcentaje de llenado de las botellas no llenas
std::vector<int> porcentaje_llenado(cv::Mat imagen,std::vector<int> no_llenas);

// Cuanta los pixeles blancos (255) en un rango de columnas
int contar_blancos(cv::Mat imagen,int inicio,int fin);

// Calcula los porcentajes de llenado de las botellas vacias
std::vector<int> porcentaje_llenado(cv::Mat imagen_llenas,std::vector<int> no_llenas);
#endif
