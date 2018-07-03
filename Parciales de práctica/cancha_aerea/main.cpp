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
	Mat imagen1 = imread("f01.jpg");
	Mat imagen2 = imread("f02.jpg");
	Mat imagen3 = imread("f03.jpg");
	Mat imagen4 = imread("f04.jpg");
	Mat imagen5 = imread("f05.jpg");
	Mat imagen6 = imread("f06.jpg");
	Mat imagen7 = imread("f07.jpg");
	Mat imagen8 = imread("f08.jpg");
	Mat imagen9 = imread("f09.jpg");
	Mat imagen10 = imread("f10.jpg");
	Mat imagen11 = imread("f11.jpg");
	Mat imagen12 = imread("f12.jpg");
	Mat imagen13 = imread("f13.jpg");
	Mat imagen14 = imread("f14.jpg");
	Mat imagen15 = imread("f15.jpg");
	Mat imagen16 = imread("f16.jpg");
	Mat imagen17 = imread("f17.jpg");
	Mat imagen18 = imread("f18.jpg");
	Mat imagen19 = imread("f18.jpg");
	Mat imagen20 = imread("f20.jpg");
	Mat imagen21 = imread("f21.jpg");

//	Eliminacion de nubes
	vector<Mat> imagenes = {imagen1,imagen2,imagen3,imagen4,imagen5,imagen6,imagen7,imagen8,imagen9,imagen10,imagen11,imagen12,imagen13,imagen14,imagen15,imagen16,imagen17,imagen18,imagen19,imagen20,imagen21,};
	Mat promedio = promediar_imagenes_color(imagenes);
	imwrite("promedio.png",promedio);
	
//	Alineacion
	Mat promedio_hsv;
	cvtColor(promedio,promedio_hsv,CV_BGR2HSV);
	vector<Mat> promedio_vector;
	split(promedio_hsv,promedio_vector);
	
	Mat promedio_u;
	threshold(promedio_vector[0],promedio_u,200*180/255,255,THRESH_BINARY);
	
	vector<Vec2f> lineas;
	HoughLines(promedio_u,lineas,1,CV_PI/180,100);
	Mat orientacion = lineas_hough(promedio_u,lineas);
	
	Mat rotadaH = rotar(promedio_vector[0],lineas);
	Mat rotadaS = rotar(promedio_vector[1],lineas);
	Mat rotadaV = rotar(promedio_vector[2],lineas);
	
	vector<Mat> rotadas = {rotadaH,rotadaS,rotadaV};
	Mat promedio_rotada;
	merge(rotadas,promedio_rotada);
	cvtColor(promedio_rotada,promedio_rotada,CV_HSV2BGR);
	
//	Presentacion de resultados
	vector<Mat> resultados = {promedio,orientacion,promedio_rotada};
	Mat mosaico_res = concatenar_v_color(resultados);
	
	imwrite("resultados.png",mosaico_res);
	
//	Ventanas
	namedWindow("Imagenes originales",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagenes originales",mosaico_res); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
