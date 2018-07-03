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

// Aplica las mascaras
std::vector<cv::Mat> segmentar(std::vector<cv::Mat> bgr_hsv,std::vector<cv::Mat> mascara);

// Binariza la imagen
cv::Mat umbral(cv::Mat imagen,int nivel_transicion);
cv::Mat umbral_negativo(cv::Mat imagen,int nivel_transicion);

// Achatamiento vertical, cada columna es el promedio de intensidades de dicha columna
cv::Mat achatar_v(cv::Mat imagen);

// Achatamiento horizontal, cada fila es el promedio de intensidades de dicha fila
cv::Mat achatar_h(cv::Mat imagen);

// Posiciones en x del recuadro
std::vector<int> recuadro_x(cv::Mat perfil_v);

// Posiciones en y del recuadro
std::vector<int> recuadro_y(cv::Mat perfil_h);

// Recorta la porcion de interes de la imagen
cv::Mat recortar(cv::Mat imagen,std::vector<int> recuadro_x,std::vector<int> recuadro_y);

// Filtro pasa alto
cv::Mat filtro_pa(int filas,int columnas,int suma);

// Filtro pasa bajo
cv::Mat filtro_pb(int filas,int columnas);

// Transformacion de potencia
cv::Mat transformacion_potencia(cv::Mat lut_table,float c,float gamma);

// Acota los valores al rango que va entre 0 y 255
int ajuste(int intensidad);

// Calcula la superficie. 1 pixel = 1 m^2 
int superficie(cv::Mat imagen,int referencia);

// Operacion AND entre las mascaras de un vector
cv::Mat and_mascaras(std::vector<cv::Mat> mascaras,int referencia);

#endif
