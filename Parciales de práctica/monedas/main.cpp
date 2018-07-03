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
//	Mat imagen = imread("01_Monedas.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat imagen = imread("02_Monedas.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	Mat imagen = imread("03_Monedas.jpg",CV_LOAD_IMAGE_GRAYSCALE);

//	Restauracion
	Mat imagen_rest;
	medianBlur(imagen,imagen_rest,7);
	
//	Umbralizacion
	Mat imagen_u;
	int nt = threshold(imagen_rest,imagen_u,0,255,THRESH_BINARY_INV|THRESH_OTSU);
	
//	Cantidad de monedas
	Mat imagen_cc,imagen_est,imagen_cen;
	connectedComponentsWithStats(imagen_u,imagen_cc,imagen_est,imagen_cen);
	imagen_cc.convertTo(imagen_cc,CV_8UC(1));
	
	double min,max;
	minMaxLoc(imagen_cc,&min,&max);
	int cantidad = max;
	cout<<"Cantidad: "<<cantidad<<"\n";
	
//	Analisis
	float suma = 0;
	for(int k=1;k<imagen_est.rows;k++) { 
		suma += determinar_valor(imagen_est.at<int>(k,4));
	}
	
	cout<<"Valor: "<<suma<<"\n";
	
//	Presentacion de resultados
	vector<Mat> imagenes = {imagen,imagen_rest,imagen_u};
	Mat mosaico_ori = concatenar_v_gray(imagenes);
	
	imwrite("resultados3.png",mosaico_ori);
	
//	Ventanas
	namedWindow("Imagenes originales",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagenes originales",mosaico_ori); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
