#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "vector"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int main(int argc,char **argv) {
	
//	Carga de imagenes
	Mat imagen = imread("rosa.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat imagen = imread("escaneo3.png",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat imagen = imread("luna.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	
//	cvtColor(imagen,imagen,CV_BGR2HSV);
	
//	Mat imagen_u;
//	int nt = threshold(imagen,imagen_u,0,255,THRESH_OTSU|THRESH_BINARY);
	
	vector<Mat> histo = histogramas(imagen);
	
//	Mat bordes_pal = filtro_pa_sc_l(imagen,3,3);
//	Mat bordes_rob = filtro_roberts(imagen);
//	Mat bordes_pre = filtro_prewitt(imagen);
//	Mat bordes_sob = filtro_sobel(imagen);
//	Mat bordes_ln4 = filtro_laplaciano4(imagen);
//	Mat bordes_ln8 = filtro_laplaciano8(imagen,3,3);
//	Mat bordes_log = filtro_log(imagen);
//	Mat bordes_can;
//	Canny(imagen,bordes_can,nt,nt,3);
	
	info(histo[0]);
	
//	vector<Mat> imagenes1 = {imagen,bordes_pal,bordes_rob,bordes_pre,bordes_sob};
//	Mat resultados1 = concatenar_v_gray(imagenes1);
//	
//	vector<Mat> imagenes2 = {bordes_ln4,bordes_ln8,bordes_log,bordes_can};
//	Mat resultados2 = concatenar_v_gray(imagenes2);
	
	namedWindow("Resultados 1",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Resultados 1",histo[0]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
//	namedWindow("Resultados 2",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("Resultados 2",resultados2); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
