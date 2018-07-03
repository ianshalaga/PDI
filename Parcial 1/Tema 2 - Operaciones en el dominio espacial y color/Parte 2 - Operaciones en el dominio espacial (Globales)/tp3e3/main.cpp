#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int main(int argc, char** argv) {
	
	Mat imagen = imread("huang2.jpg",CV_LOAD_IMAGE_GRAYSCALE);

	Mat suma1 = filtro_pa(3,3,1);
	Mat suma0 = filtro_pa(3,3,0);
	
	Mat resultado1 = convolve(imagen,suma1);
	Mat resultado2 = convolve(imagen,suma0);
	
//	Ventanas
	namedWindow("Imagen",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen

	namedWindow("Suma 1",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Suma 1",resultado1); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Suma 0",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Suma 0",resultado2); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
