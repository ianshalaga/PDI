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
	
	Mat reunion = imread("reunion.png",CV_LOAD_IMAGE_GRAYSCALE);
	Mat casilla = imread("casilla.png",CV_LOAD_IMAGE_GRAYSCALE);
	
	Mat reunion_eq;
	equalizeHist(reunion,reunion_eq);
	imwrite("reunion_eq.png",reunion_eq);
	
	Mat casilla_eq;
	equalizeHist(casilla,casilla_eq);
	imwrite("casilla_eq.png",casilla_eq);
	
	vector<Mat> imagenes = {reunion,reunion_eq,casilla,casilla_eq};
	Mat mosaico = concatenar_v_gray(imagenes);
	
	namedWindow("Resultados",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Resultados",mosaico); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
