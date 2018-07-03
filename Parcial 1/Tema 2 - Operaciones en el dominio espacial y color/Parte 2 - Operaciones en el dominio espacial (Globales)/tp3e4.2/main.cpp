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
	
//	Mat imagen = imread("huang2.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	Mat imagen = imread("fotograma056.jpg",CV_LOAD_IMAGE_GRAYSCALE);

	Mat kernel1 = filtro_pb(3,3);
	Mat high_boost1 = alta_potencia(imagen,2,kernel1,1);
	Mat kernel2 = filtro_pa(3,3,1);
	Mat high_boost2 = alta_potencia(imagen,3,kernel2,2);
	
	//	Ventanas
	namedWindow("Imagen",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Alta potencia v1",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Alta potencia v1",high_boost1); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Alta potencia v2",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Alta potencia v2",high_boost2); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
