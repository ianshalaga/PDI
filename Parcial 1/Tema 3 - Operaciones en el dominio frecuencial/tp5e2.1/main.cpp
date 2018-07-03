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
	
	Mat imagen = imread("huang2.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	Mat imagen_f;
	imagen.convertTo(imagen_f,CV_32F);
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	Mat negro(imagen.size(),CV_32F,Scalar(0));
	
	Mat circ = circulo(negro,20);
	circ = fft_shift(circ);
//	circ = spectrum(circ);
	info(circ);
	
	Mat ideal = filter_ideal(filas,columnas,0.5);
//	ideal = spectrum(ideal);
	info(ideal);
	
	// imagen_f debe ser CV_32F
	// el filtro debe estar desentrado
	Mat filtrada = filter(imagen_f,ideal);
	
	namedWindow("imagen",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("imagen",circ); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("filt",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("filt",ideal); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("filtrada",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("filtrada",filtrada); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
