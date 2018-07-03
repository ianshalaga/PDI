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

	Mat imagen = imread("luna.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	Mat mensaje = imread("secreto.tif",CV_LOAD_IMAGE_GRAYSCALE);
	info(imagen);
	info(mensaje);
	
	mensaje = desbinarizar(mensaje,0);
	
//	Ocultado del mensaje
	vector<Mat> planos = planos_bits(imagen);
	planos[0] = mensaje;
	vector<Mat> sumas = suma_planos(planos);
	
//	Recuperado del mensaje
	vector<Mat> planos2 = planos_bits(sumas[7]);
	Mat mensaje_recuperado = umbral(planos2[0],0);
	
	//	Ventanas
	namedWindow("Luna",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Luna",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Mensaje",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Mensaje",mensaje); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Mensaje ocultado",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Mensaje ocultado",sumas[7]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Mensaje reconstruido",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Mensaje reconstruido",mensaje_recuperado); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
