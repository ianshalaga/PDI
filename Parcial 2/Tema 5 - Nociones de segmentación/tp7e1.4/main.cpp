#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

// Todos estos metodos son sencibles al ruido

int main(int argc, char** argv) {
	
	Mat imagen = imread("subs2.png",CV_LOAD_IMAGE_GRAYSCALE);
	Mat norm01;
	normalize(imagen,norm01,0,1,CV_MINMAX,CV_64F);
	
	vector<Mat> ruidosa = imagenes_ruidosas(norm01,1,0,0.2);
	normalize(ruidosa[0],ruidosa[0],0,255,CV_MINMAX,CV_8UC(1));
	
	Mat kernel = filtro_pa_sc_lh(3,3);
//	normalize(kernel,kernel,0,1,CV_MINMAX,CV_64F);
	Mat bordes = convolve(ruidosa[0],kernel);
	
	namedWindow("Imagen original",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen original",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Ruido gaussiano",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Ruido gaussiano",ruidosa[0]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Bordes",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Bordes",bordes); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
