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
	Mat imagen = imread("Hollywood10.jpg"); // Entrenamiento
//	Mat imagen = imread("Hollywood11.jpg"); // Entrenamiento
//	Mat imagen = imread("Hollywood12.jpg"); // Prueba
	
//	Carga de la persona
	Mat persona = imread("tito03.jpeg");
	Mat persona_rest;
	medianBlur(persona,persona_rest,3);

	vector<Mat> persona_vec;
	split(persona_rest,persona_vec);
	
	Mat persona_hsv;
	cvtColor(persona_rest,persona_hsv,CV_BGR2HSV);
	vector<Mat> persona_hsv_vec;
	split(persona_hsv,persona_hsv_vec);
	
//	Mascara de persona
	Mat persona_mask; //230
	threshold(persona_vec[2],persona_mask,200,255,THRESH_BINARY_INV);
//	Mat ee = getStructuringElement(MORPH_CROSS,{3,3},Point(-1,-1));
//	erode(persona_mask,persona_mask,ee,Point(-1,-1),1);
	
//	
	Mat imagen_rest;
	medianBlur(imagen,imagen_rest,7);
	
	vector<Mat> imagen_vec;
	split(imagen,imagen_vec);
	
	Mat mediaR,stdevR;
	meanStdDev(imagen_vec[2],mediaR,stdevR);
	int lim_supR = mediaR.at<double>(0,0)+stdevR.at<double>(0,0);
	int lim_infR = mediaR.at<double>(0,0)-stdevR.at<double>(0,0);
	
	Mat imagen_uR;
	imagen_uR = umbral_rango(imagen_vec[2],lim_infR,lim_supR);
	imagen_uR = umbral_negativo(imagen_uR,127);

	Mat promedios_v = promedio_intensidad_v(imagen_uR);
	Mat promedios_h = promedio_intensidad_h(imagen_uR);
	threshold(promedios_v,promedios_v,127,255,THRESH_BINARY);
	threshold(promedios_h,promedios_h,127,255,THRESH_BINARY);
	vector<int> vector_v = blancos_v(promedios_h);
	vector<int> vector_h = blancos_h(promedios_v);
	
	Rect roi1(vector_h[1],vector_v[1],vector_h[2]-vector_h[1],vector_v[2]-vector_v[1]);
	Rect roi2(vector_h[5],vector_v[1],vector_h[6]-vector_h[5],vector_v[2]-vector_v[1]);
	Rect roi3(vector_h[9],vector_v[1],vector_h[10]-vector_h[9],vector_v[2]-vector_v[1]);
	Rect roi4(vector_h[1],vector_v[5],vector_h[2]-vector_h[1],vector_v[6]-vector_v[5]);
	Rect roi5(vector_h[5],vector_v[5],vector_h[6]-vector_h[5],vector_v[6]-vector_v[5]);
	Rect roi6(vector_h[9],vector_v[5],vector_h[10]-vector_h[9],vector_v[6]-vector_v[5]);
	Rect roi7(vector_h[1],vector_v[9],vector_h[2]-vector_h[1],vector_v[10]-vector_v[9]);
	Rect roi8(vector_h[5],vector_v[9],vector_h[6]-vector_h[5],vector_v[10]-vector_v[9]);
	Rect roi9(vector_h[9],vector_v[9],vector_h[10]-vector_h[9],vector_v[10]-vector_v[9]);

	Mat imagen_hsv;
	cvtColor(imagen,imagen_hsv,CV_BGR2HSV);
	vector<Mat> imagen_hsv_vec;
	split(imagen_hsv,imagen_hsv_vec);
	
	Mat recuadros_u; //200
	threshold(imagen_hsv_vec[2],recuadros_u,200,255,THRESH_BINARY);
	
	Mat recuadro1 = recuadros_u(roi1);
	Mat recuadro2 = recuadros_u(roi2);
	Mat recuadro3 = recuadros_u(roi3);
	Mat recuadro4 = recuadros_u(roi4);
	Mat recuadro5 = recuadros_u(roi5);
	Mat recuadro6 = recuadros_u(roi6);
	Mat recuadro7 = recuadros_u(roi7);
	Mat recuadro8 = recuadros_u(roi8);
	Mat recuadro9 = recuadros_u(roi9);
	
	int prom1 = promedio_intensidad(recuadro1);
	int prom2 = promedio_intensidad(recuadro2);
	int prom3 = promedio_intensidad(recuadro3);
	int prom4 = promedio_intensidad(recuadro4);
	int prom5 = promedio_intensidad(recuadro5);
	int prom6 = promedio_intensidad(recuadro6);
	int prom7 = promedio_intensidad(recuadro7);
	int prom8 = promedio_intensidad(recuadro8);
	int prom9 = promedio_intensidad(recuadro9);
	
	vector<int> promedios = {prom1,prom2,prom3,prom4,prom5,prom6,prom7,prom8,prom9};
	int indice = maximo(promedios);
	
	vector<Rect> recuadros = {roi1,roi2,roi3,roi4,roi5,roi6,roi7,roi8,roi9};
	
	persona.copyTo(imagen(Rect(posicion_x(vector_h,indice)-persona.cols/2,posicion_y(vector_v,indice)-persona.rows+6,persona.cols,persona.rows)),persona_mask);
	
//	Presentacion de resultados
	vector<Mat> resultados = {imagen,recuadros_u};
	Mat mosaico_res = concatenar_v_color(resultados);
	
//	Ventanas
	namedWindow("Imagenes originales",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagenes originales",mosaico_res); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la image
	
	namedWindow("prom",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("prom",promedios_h); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la image
	
	return 0;
}
