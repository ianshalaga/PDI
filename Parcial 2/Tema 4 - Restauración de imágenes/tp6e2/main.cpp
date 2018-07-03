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
	
	Mat imagen = imread("sangre.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat imagen = imread("patron.tif",CV_LOAD_IMAGE_GRAYSCALE);
	
	Mat imagen_ruido = ruido_impulsivo(imagen,0,255);
	
	Mat filtro_ma = media_aritmetica(imagen_ruido,5,5);
	Mat filtro_mg = media_geometrica(imagen_ruido,5,5);
	Mat filtro_mar = media_armonica(imagen_ruido,5,5);
	
	float error = ecm(filtro_ma,filtro_mar);
	cout<<error<<"\n";
	
//	Presentacion de resultados
	vector<Mat> imagenes = {imagen,filtro_ma,filtro_mg,filtro_mar};
	Mat mosaico = concatenar_v_gray(imagenes);
	
	//	Ventanas
	namedWindow("Resultados",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Resultados",mosaico); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
