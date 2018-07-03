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
	//carga una imagen en escala de grises	
	Mat imagen=imread("rosas.jpg");
//	Mat imagen=imread("patron.tif");
	Mat imagenHSV; // Para trabajar
	Mat imagenBGR; // Para mostrar el resultado final
	
	//Muestra información la imagen
	info(imagen);
	
//	BGR
	
	vector<Mat> bgr_vector;
	split(imagen,bgr_vector);
	
	negativo_bgr(bgr_vector);
	
	merge(bgr_vector,imagenBGR);
	
//	imwrite("negativo_bgr.jpg",imagenBGR);
	
//	HSV
	
	cvtColor(imagen,imagenHSV,CV_BGR2HSV);
	vector<Mat> hsv_vector;
	split(imagenHSV,hsv_vector);
	
	vector<Mat> neg_hsv = negativo_hsv(hsv_vector);
	
//	double minimo,maximo;
//	minMaxLoc(hsv_vector[0],&minimo,&maximo); //saca el minimo y el maximo de una matriz
//	hsv_vector[0] = matiz_opuesta(hsv_vector[0]); //matices de azul a rojo
//	hsv_vector[0] = maximo-hsv_vector[0]; //matices de azul a rojo
//	hsv_vector[1] = 255; 
//	hsv_vector[2] = 255-hsv_vector[2];
	
	merge(neg_hsv,imagenHSV);
	cvtColor(imagenHSV,imagenHSV,CV_HSV2BGR);
	
	namedWindow("Imagen",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
//	
	namedWindow("Negativo BGR",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Negativo BGR",imagenBGR); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
//	
	namedWindow("Negativo HSV",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Negativo HSV",imagenHSV); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
//	
//	namedWindow("Red",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("Red",bgr[2]); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
//	namedWindow("H",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("H",hsv_vector[0]); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
//	
//	namedWindow("S",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("S",hsv_vector[1]); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
//	
//	namedWindow("V",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("V",hsv_vector[2]); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
