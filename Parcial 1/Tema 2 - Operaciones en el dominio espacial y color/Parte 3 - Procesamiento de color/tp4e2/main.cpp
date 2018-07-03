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
	//carga una imagen
	Mat imagen=imread("rio.jpg");
	
	//Muestra información la imagen
	info(imagen);
	
	Mat imagenHSV; // Para trabajar
	cvtColor(imagen,imagenHSV,CV_BGR2HSV);
	vector<Mat> hsv_vector;
	split(imagenHSV,hsv_vector);
	
	Mat histograma = draw_hist(histogram(imagen,256));
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	Mat mascara(filas,columnas,CV_8UC(1));
	inRange(hsv_vector[2],Scalar(0),Scalar(25),mascara);
	
	colorea(hsv_vector,mascara,30,255,255);
	
	Mat imagenBGR; // Para mostrar el resultado final
	merge(hsv_vector,imagenHSV);
	cvtColor(imagenHSV,imagenBGR,CV_HSV2BGR);
	
	namedWindow("Imagen original",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen original",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("histograma",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("histograma",histograma); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Imagen BGR",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen BGR",imagenBGR); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("H",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("H",hsv_vector[0]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("S",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("S",hsv_vector[1]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("V",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("V",hsv_vector[2]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
