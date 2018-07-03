#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int main(int argc, char** argv) {

//	filter_ideal(M,N,frec_corte);
//	filter(imagen,filtro);
	
	int potencia = 10;
	int dimension = pow(2,potencia);
	
	Mat imagen(dimension,dimension,CV_64F,Scalar(0));
	
	info(imagen);
	
	Mat linea_horizontal = linea_h(imagen);
	Mat linea_vertical = linea_v(imagen);
	Mat cuad = cuadrilatero(imagen,1,2);
	Mat circ = circulo(imagen,1);
	
	Mat fourier = spectrum(circ);
	
	namedWindow("Lienzo negro",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Lienzo negro",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Linea Horizontal",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Linea Horizontal",linea_horizontal); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Linea Vertical",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Linea Vertical",linea_vertical); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Cuadrado",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Cuadrado",cuad); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Circulo",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Circulo",circ); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Fourier",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Fourier",fourier); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
