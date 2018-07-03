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
	
	Mat kernel_pb1 = filtro_pb(3,3);
	print(kernel_pb1,cout);
	
	Mat kernel_pb2 = filtro_pb(5,5);
	print(kernel_pb2,cout);
	
	Mat borroneada1 = convolve(imagen,kernel_pb1);
	Mat borroneada2 = convolve(imagen,kernel_pb2);
	
//	Ventanas
	namedWindow("Imagen",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Kernel 3x3",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Kernel 3x3",borroneada1); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Kernel 5x5",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Kernel 5x5",borroneada2); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
