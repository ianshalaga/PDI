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
	
//	Mat imagen = imread("estanbul.tif",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat imagen = imread("huang2.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat imagen = imread("luna.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat imagen = imread("subs1.png",CV_LOAD_IMAGE_GRAYSCALE);
	Mat imagen = imread("subs2.png",CV_LOAD_IMAGE_GRAYSCALE);
	
	Mat kernel_pas0 = filtro_pa(3,3,0);
	Mat pa = umbral(convolve(imagen,kernel_pas0),100);
	
	Mat bordes_roberts = filtro_roberts(imagen,100);
	
	Mat lineas = filtro_pa_sc_l(imagen,3,3,100);
	
//	Ventanas
	
	namedWindow("Imagen original",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen original",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Pasa-altos suma 0",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Pasa-altos suma 0",pa); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Bordes Roberts",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Bordes Roberts",bordes_roberts); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Pasa-altos detector de lineas",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Pasa-altos detector de lineas",lineas); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
