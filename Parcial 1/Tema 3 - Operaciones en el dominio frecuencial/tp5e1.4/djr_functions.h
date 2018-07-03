#ifndef DJR_FUNCTIONS_H
#define DJR_FUNCTIONS_H
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

// Binariza una imagen
cv::Mat umbral(cv::Mat imagen,int nivel_transicion);

//double n_t = threshold(imagen_gris,imagen_u,0,255,THRESH_OTSU|THRESH_BINARY_INV);
//cout<<n_t<<"\n";

// Binariza una imagen
cv::Mat umbral_negativo(const cv::Mat &imagen,const int &nivel_transicion);

// Cuenta pixeles blancos
int contar_blancos(const cv::Mat &imagen,const int &ini_f,const int &fin_f,const int &ini_c,const int &fin_c);

// Ajusta el rango de valores entre 0 y 255
int ajuste(int intensidad);

// Transformacion rectilinea
cv::Mat transformacion_rectilinea(cv::Mat lut_table,float a,float c);

// Transformacion rectilinea por tramos
cv::Mat transformacion_tramos(cv::Mat lut_table,std::vector<float> r,std::vector<float> s);

// Transformacion logaritmica
cv::Mat transformacion_logaritmica(cv::Mat lut_table,float c);

// Transformacion de potencia
cv::Mat transformacion_potencia(cv::Mat lut_table,float c,float gamma);

// Promedio de dos imagenes
cv::Mat suma(cv::Mat imagen1,cv::Mat imagen2,float alfa);

// Resta imagen2 a imagen1
cv::Mat resta(cv::Mat imagen1,cv::Mat imagen2);

// Aplica las mascara imagen2 a imagen1
cv::Mat multiplicacion(cv::Mat imagen1,cv::Mat imagen2);

// Divide dos imagenes
cv::Mat division(cv::Mat imagen1,cv::Mat imagen2);

// Genera copias de la imagen con ruido gaussiano
std::vector<cv::Mat> imagenes_ruidosas(cv::Mat imagen,int cantidad,float media,float stdev);

// Elimina ruido gaussiano por promediado de imagenes ruidosas
cv::Mat reduccion_ruido(std::vector<cv::Mat> ruidosas);

// Interseccion de mascaras (AND)
cv::Mat and_mascaras(const std::vector<cv::Mat> &mascaras);

// Obtiene los planos de bits de una imagen
std::vector<cv::Mat> planos_bits(cv::Mat imagen);

// Binariza los planos de bits para su visualizacion
std::vector<cv::Mat> planos_bits_bin(std::vector<cv::Mat> planos);

// Obtiene la imagen a partir de los planos de bits
std::vector<cv::Mat> suma_planos(std::vector<cv::Mat> planos);

// Dibuja el histograma bidimensional de una imagen
cv::Mat draw_hist(const cv::Mat &histo);

// Promedios horizontales de intensidad
cv::Mat promedio_intensidad_h(const cv::Mat &imagen);

// Promedios verticales de intensidad
cv::Mat promedio_intensidad_v(const cv::Mat &imagen);

// Promedio de intensidad de una imagen
int promedio_intensidad(const cv::Mat &imagen);

// Posiciones de inicio y fin de los tramos blancos en un vector de promedios de intensidad umbralizado
std::vector<int> blancos(const cv::Mat &perfil_v);

// XOR entre dos imagenes
cv::Mat or_exclusivo(const cv::Mat &imagen1,const cv::Mat &imagen2);

// Parte una imagen a la mitad
std::vector<cv::Mat> partir_mitad(const cv::Mat &imagen,const bool &tipo);

// Transforma una imagen binaria a una imagen del plano de bit cero
cv::Mat desbinarizar(const cv::Mat &imagen,const int &bit);

// Suma los elementos de un kernel
int suma_kernel(const cv::Mat &kernel);

// Kernel pasa-bajos (promediado)
cv::Mat filtro_pb(const int &filas,const int &columnas);

// Kernel pasa-bajos gaussiano
cv::Mat gauss_kernel(const int &dimension,const float &stdev);

// Kernel pasa-altos suma cero o uno (cuadrado completo)
cv::Mat filtro_pa(int filas,int columnas,int suma);

// Filtro de mascara difusa (espacial)
cv::Mat mascara_difusa(const cv::Mat &imagen,const cv::Mat &kernel_pb);

// Filtro de alta potencia
cv::Mat alta_potencia(const cv::Mat imagen,const float A,const cv::Mat kernel,const int version);

// Negativo BGR
std::vector<cv::Mat> negativo_bgr(std::vector<cv::Mat> bgr_vector);

// Colorea una imagen HSV en la zona enmascarada
std::vector<cv::Mat> colorea(std::vector<cv::Mat> hsv_vector,cv::Mat mascara,int H,int S,int V);

// Agrega ruido gaussiano a una imagen
cv::Mat ruido_gaussiano(const cv::Mat &imagen,const float &media,const float &stdev);

// Agrega ruido impulsivo (sal y pimienta) a una imagen
cv::Mat ruido_impulsivo(const cv::Mat &imagen,const int &bajo,const int &alto);

// Filtro de media aritmetica
cv::Mat media_aritmetica(const cv::Mat &imagen,const int kf,const int kc);

// Filtro de media geometrica
cv::Mat media_geometrica(const cv::Mat &imagen,const int kf,const int kc);

// Error cuadratico medio
float ecm(const cv::Mat &imagen1,const cv::Mat &imagen2);

// Union de mascaras (OR)
cv::Mat or_mascaras(const std::vector<cv::Mat> &mascaras);

// Detector de lineas pasa-altos suma cero
cv::Mat filtro_pa_sc_l(const cv::Mat &imagen,const int &filas,const int &columnas);

// Detector de bordes Roberts
cv::Mat filtro_roberts(const cv::Mat &imagen);

// Detector de bordes Prewitt
cv::Mat filtro_prewitt(const cv::Mat &imagen);

// Detector de bordes Sobel
cv::Mat filtro_sobel(const cv::Mat &imagen);

// Detector de bordes Laplaciano en cruz
cv::Mat filtro_laplaciano4(const cv::Mat &imagen);

// Detector de bordes Laplaciano cuadrado
cv::Mat filtro_laplaciano8(const cv::Mat &imagen,const int &filas,const int &columnas);

// Kernel laplaciano del gaussiano 5x5
cv::Mat filtro_log(const cv::Mat &imagen);

// Concatena imagenes horizontalmente en escala de grises
cv::Mat concatenar_h_gray(std::vector<cv::Mat> imagenes);

// Concatena imagenes verticalmente en escala de grises
cv::Mat concatenar_v_gray(std::vector<cv::Mat> imagenes);

// Concatena imagenes horizontalmente en color
cv::Mat concatenar_h_color(std::vector<cv::Mat> imagenes);

// Concatena imagenes verticalmente en color
cv::Mat concatenar_v_color(std::vector<cv::Mat> imagenes);

// Dibuja lineas de Hough
cv::Mat lineas_hough(const cv::Mat &bordes,const std::vector<cv::Vec2f> &rho_tita);

// Dibuja lineas de Hough
cv::Mat lineas_houghP(const cv::Mat &bordes,const std::vector<cv::Vec4i> &ini_fin);

// Dibuja circulos en la posicion de los centroides
cv::Mat dibujar_circulos(const cv::Mat &imagen,const cv::Mat &centroides,const int &radio);

// Transformacion potencia-raiz
cv::Mat pot_raiz(cv::Mat lut_table,const float &gamma_pot,const float &gamma_raiz,const float &n_t);

// Genera un elemento estructurante de 3x3
cv::Mat elemento_estructurante();

// Extrea los objetos conectados al borde
cv::Mat objetos_borde(const cv::Mat &mascara);

// Rellena los elementos de una mascara
cv::Mat rellenar(cv::Mat mascara);

// Acomoda verticalmente una imagen
cv::Mat rotar(const cv::Mat &imagen,const std::vector<cv::Vec2f> &rho_tita);

#endif
