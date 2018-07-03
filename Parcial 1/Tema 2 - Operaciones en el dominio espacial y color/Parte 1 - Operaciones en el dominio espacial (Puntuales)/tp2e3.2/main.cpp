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
	
	Mat imagen = imread("luna.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	
//	Normalizar la imagen al rango 0 - 1
	Mat normalizada;
	normalize(imagen,normalizada,0,1,CV_MINMAX,CV_64F);
	
	vector<Mat> ruidosas = imagenes_ruidosas(normalizada,50,0,0.05);
	
	Mat sin_ruido = reduccion_ruido(ruidosas);
	
	
//	Ventanas
	namedWindow("Entrada",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Entrada",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Normalizada",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Normalizada",normalizada); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Muestra ruidosa",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Muestra ruidosa",ruidosas[25]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Reduccion de ruido",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Reduccion de ruido",sin_ruido); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
