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
//	Mat cerveza = imread("01.jpg"); // 32 108
//	Mat cerveza = imread("02.jpg"); // 19 98
//	Mat cerveza = imread("05.jpg"); // 19 164
//	Mat cerveza = imread("08.jpg"); // 28 154
//	Mat cerveza = imread("11.jpg"); // 18 156
//	Mat cerveza = imread("12.jpg"); // 20 137
//	Mat cerveza = imread("13.jpg"); // 37 139
//	Mat cerveza = imread("31.jpg"); // 15 67
	Mat cerveza = imread("32.jpg"); // 16 62
//	Mat cerveza = imread("33.jpg"); // 17 76
//	Mat cerveza = imread("34.jpg"); // 62 86
	
//	Restaruracion
	Mat cerveza_rest;
	medianBlur(cerveza,cerveza_rest,7);

	imwrite("cerveza_negra.png",cerveza_rest);
	
//	Separacion de canales
	Mat cerveza_hsv;
	cvtColor(cerveza_rest,cerveza_hsv,CV_BGR2HSV);
	vector<Mat> cerveza_hsv_vec;
	split(cerveza_hsv,cerveza_hsv_vec);
	
//	Umbralizacion
	Mat cerveza_u;
	threshold(cerveza_hsv_vec[1],cerveza_u,5,255,THRESH_BINARY);

//	Determinacion del tipo de cerveza y el porcentaje de espuma
	int prom = promedio_intensidad_mask(cerveza_hsv_vec[1],cerveza_u);

	Mat llena_u;
	threshold(cerveza_hsv_vec[2],llena_u,254,255,THRESH_BINARY_INV);
	
	Mat liquido_u;
	
	if (prom > 90) {
		cout<<"Rubia\n";
		threshold(cerveza_hsv_vec[1],liquido_u,50,255,THRESH_BINARY);
	}
	else {
		cout<<"Negra\n";
		threshold(cerveza_hsv_vec[1],liquido_u,30,255,THRESH_BINARY);
	}
	
	int por = porcentaje_llenado(llena_u,liquido_u);
	cout<<"Porcentaje de espuma: "<<por<<"\n";
	
	//	Presentacion de resultados
	vector<Mat> imagenes = {cerveza,cerveza_rest,llena_u,liquido_u};
	Mat mosaico_res = concatenar_h_color(imagenes);
	
	//	Ventanas
	namedWindow("Imagenes originales",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagenes originales",mosaico_res); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
