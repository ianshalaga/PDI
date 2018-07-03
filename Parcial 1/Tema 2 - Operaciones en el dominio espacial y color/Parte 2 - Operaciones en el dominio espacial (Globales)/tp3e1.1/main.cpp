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
	info(imagen);
	
	Mat histograma1 = draw_hist(histogram(imagen,256));
	Mat analisis1 = mosaic(imagen,histograma1,false);
	
	Mat ecualizada;
	equalizeHist(imagen,ecualizada);
	Mat histograma2 = draw_hist(histogram(ecualizada,256));
	Mat analisis2 = mosaic(ecualizada,histograma2,false);
	
//	Ventanas
	namedWindow("Analisis original",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Analisis original",analisis1); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Analisis ecualizada",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Analisis ecualizada",analisis2); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
