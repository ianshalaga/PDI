#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
//#include "bitset"
#include "pdi_functions.h"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int main(int argc, char** argv) {
	
	Mat imagen = imread("earth.bmp",CV_LOAD_IMAGE_GRAYSCALE);
	Mat dimensiones = imread("aliens.bmp",CV_LOAD_IMAGE_GRAYSCALE);
	info(imagen);
	
	Rect ROI(imagen.cols-dimensiones.cols,0,dimensiones.cols,dimensiones.rows);
	
	Mat recuadro = imagen(ROI);
	
	equalizeHist(recuadro,recuadro);
	
//	Ventanas
	namedWindow("Entrada",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Entrada",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("ROI",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("ROI",recuadro); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
