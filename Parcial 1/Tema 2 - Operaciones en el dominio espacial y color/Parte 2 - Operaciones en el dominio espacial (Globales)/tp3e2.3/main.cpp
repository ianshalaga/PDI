#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "bitset"
#include "pdi_functions.h"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int main(int argc, char** argv) {
	
	Mat imagen = imread("hubble.tif",CV_LOAD_IMAGE_GRAYSCALE);
	
	Mat kernel = filtro_pb(7,7);
	
	Mat borrosa = convolve(imagen,kernel);
	
	Mat borrosa_b = umbral(borrosa,50);
	
	Mat comp = mosaic(imagen,borrosa,false);
	
	Mat resultado = multiplicacion(imagen,borrosa_b);
	
//	Ventanas
	namedWindow("Imagen",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Comparativa",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Comparativa",comp); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Mascara",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Mascara",borrosa_b); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("resultado",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("resultado",resultado); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
