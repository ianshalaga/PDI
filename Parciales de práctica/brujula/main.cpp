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
//	Mat brujula = imread("1.png");
//	Mat brujula = imread("2.png");
//	Mat brujula = imread("3.png");
	Mat brujula = imread("4.png");
	
//	Mascara de deteccion de norte
	Mat mascara1 = imread("mascara1.png",CV_LOAD_IMAGE_GRAYSCALE);
	Mat mascara2 = imread("mascara2.png",CV_LOAD_IMAGE_GRAYSCALE);
	threshold(mascara1,mascara1,0,255,THRESH_BINARY|THRESH_OTSU);
	threshold(mascara2,mascara2,0,255,THRESH_BINARY|THRESH_OTSU);
	
//	Restaruracion
	Mat brujula_rest;
	medianBlur(brujula,brujula_rest,7);
	
//	Separacion de canales
	Mat brujula_hsv;
	cvtColor(brujula_rest,brujula_hsv,CV_BGR2HSV);
	vector<Mat> brujula_hsv_vec;
	split(brujula_hsv,brujula_hsv_vec);
	
//	Umbralizacion
	Mat brujula_u;
	int nt = threshold(brujula_hsv_vec[0],brujula_u,253*180/255,255,THRESH_BINARY);
	
//	Morfologia
	Mat ee = getStructuringElement(MORPH_RECT,{3,3},Point(-1,-1));
	morphologyEx(brujula_u,brujula_u,MORPH_CLOSE,ee,Point(-1,-1),5);
	
//	Alineacion del norte
	Mat norte = multiplicacion(brujula_u,mascara1);
	norte = or_mascaras({norte,mascara2});
	
	vector<Vec2f> lineas_n;
	HoughLines(norte,lineas_n,1,CV_PI/180,20);
	Mat lineas_norte = lineas_hough(norte,lineas_n);
	
	brujula_u = rotar(brujula_u,lineas_n);
	
//	Direccion de la aguja
	vector<Vec2f> lineas;
	HoughLines(brujula_u,lineas,1,CV_PI/180,50);
	Mat lineas_rojas = lineas_hough(brujula_u,lineas);
	
//	Angulo
	cout<<"Angulo: "<<detectar_angulo(brujula_u,lineas)<<"\n";
	
//	Presentacion de resultados
	vector<Mat> imagenes = {brujula_rest,lineas_rojas};
	Mat mosaico_res = concatenar_v_color(imagenes);
	
//	Ventanas
	namedWindow("Imagenes originales",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagenes originales",mosaico_res); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
