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
	
	Mat imagen = imread("huang3_movida.tif",CV_LOAD_IMAGE_GRAYSCALE);	
	
//	Mat imagen_rg = ruido_gaussiano(imagen,0,0.05);
//	Mat imagen_rg_sp = ruido_impulsivo(imagen_rg,0,255);
//	
//	Mat imagen_pm = punto_medio(imagen_rg_sp,3,3);
//	Mat imagen_ar = media_alfarecortado(imagen_rg_sp,5,5,2);
//	
	//	Presentacion de resultados
	vector<Mat> imagenes = {imagen};
	Mat mosaico = concatenar_v_gray(imagenes);
	
	//	Ventanas
	namedWindow("Resultados",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Resultados",mosaico); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
