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
	
	Mat imagen = imread("huang2.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	
	Mat kernel1 = gauss_kernel(3,0.5);
	Mat kernel2 = filtro_pb(3,3);
	
	Mat kernel3 = gauss_kernel(5,0.5);
	Mat kernel4 = filtro_pb(5,5);
	
	Mat comp1 = mosaic(imagen,mosaic(convolve(imagen,kernel1),convolve(imagen,kernel2),false),false);
	Mat comp2 = mosaic(imagen,mosaic(convolve(imagen,kernel3),convolve(imagen,kernel4),false),false);
	
	//	Ventanas
	namedWindow("Imagen",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Comparativa 3x3",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Comparativa 3x3",comp1); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Comparativa 5x5",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Comparativa 5x5",comp2); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
