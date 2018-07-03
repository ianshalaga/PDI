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
	
	Mat imagen = imread("cuadros.tif",CV_LOAD_IMAGE_GRAYSCALE);
	
	Mat cuadros_bin = umbral_negativo(imagen,30);
	Mat resto_bin = umbral(imagen,30);
	
	Mat cuadros;
	equalizeHist(multiplicacion(imagen,cuadros_bin),cuadros);
	Mat resto =	multiplicacion(imagen,resto_bin);
	
	Mat detalles = 2*suma(cuadros,resto,0.5);
	
//	Ventanas	
	namedWindow("Detalles ocultos",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Detalles ocultos",detalles); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
