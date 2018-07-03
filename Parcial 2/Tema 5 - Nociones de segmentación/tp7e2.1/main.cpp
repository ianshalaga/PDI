#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
//#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

// Todos estos metodos son sencibles al ruido

int main(int argc, char** argv) {
	
	Mat imagen = imread("subs2.png",CV_LOAD_IMAGE_GRAYSCALE);
	
	
	namedWindow("Imagen original",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen original",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
