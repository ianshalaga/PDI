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
	
	int potencia = 9;
	int dimension = pow(2,potencia);
	Mat imagen(dimension,dimension,CV_64F,Scalar(0));
	info(imagen);

//	imwrite("vertical.png",imagen);
	
	imagen = rotate(linea_v(imagen),20);
	
	Mat rotada1 = imread("rotada1.png",CV_LOAD_IMAGE_GRAYSCALE);
	rotada1.convertTo(rotada1,CV_64F);
	Mat vertical = imread("vertical.png",CV_LOAD_IMAGE_GRAYSCALE);
	vertical.convertTo(vertical,CV_64F);
	info(rotada1);
	
	rotada1 = spectrum(rotada1);
	vertical = spectrum(vertical);
	
	namedWindow("rotada1",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("rotada1",rotada1); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
//	
	namedWindow("vertical",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("vertical",vertical); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
