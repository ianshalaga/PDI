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

/***************************************************************/

// Estructura de dos puntos para definir una ROI
struct puntos_roi {
	Point p1; // Abajo izquierda
	Point p2; // Arriba derecha
};

// Obtener informacion del mouse
void clic(int evento,int x,int y,int flag,void* estructura) {
	// Conversion obligatoria
	puntos_roi &datos = *static_cast<puntos_roi*>(estructura);
	
	if (evento == CV_EVENT_LBUTTONDOWN) {
		datos.p1 = Point(x,y);
		cout<<"x: "<<x<<" "<<"y: "<<y<<"\n";
	}
	
	if (evento == CV_EVENT_LBUTTONUP) {
		datos.p2 = Point(x,y);
		cout<<"x: "<<x<<" "<<"y: "<<y<<"\n";
	}
	
	//	cout<<x<<" "<<y<<"\n";	
}

/***************************************************************/

int main(int argc,char **argv) {
	
//	Carga de imagenes
//	Mat billete = imread("B2C1_01.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat billete = imread("B2C1_02a.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat billete = imread("B5C1_01.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat billete = imread("B5C1_02a.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat billete = imread("B10C1_01.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat billete = imread("B10C1_02a.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat billete = imread("B20C1_01a.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat billete = imread("B20C1_02.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat billete = imread("B50C1_01a.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat billete = imread("B50C1_02.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat billete = imread("B100C1_01.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	Mat billete = imread("B100C1_02a.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	
//	Restauracion
	Mat billete_rest;
	medianBlur(billete,billete_rest,3);

//  Definir ROI
//	namedWindow("Definir ROI",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("Definir ROI",billete_rest); //muestra la imagen en la ventana
//	puntos_roi pr;
//	setMouseCallback("Definir ROI",clic,&pr);
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen	
	
//	Determinar rotacion
	Point p3(0,0);
	Point p4(177,250);
	Rect izquierda(p3,p4);
	Mat roi2 = billete_rest(izquierda);
	int prom = promedio_intensidad(roi2);
	if (prom < 200)
		billete_rest = rotate(billete_rest,180);
	
//	Definir roi donde se encuentran los rombos
	Point p1(131,3);
	Point p2(179,80);
	Rect area(p1,p2);
	Mat roi = billete_rest(area);
	
//	Umbralizacion
	Mat roi_u;
	int nt = threshold(roi,roi_u,0,255,THRESH_BINARY_INV|THRESH_OTSU);

//	Determinar valor del billete
	Mat roi_cc,roi_est,roi_cen;
	connectedComponentsWithStats(roi_u,roi_cc,roi_est,roi_cen);
	roi_cc.convertTo(roi_cc,CV_8UC(1));
	
	double min,max;
	minMaxLoc(roi_cc,&min,&max);
	int rombos = max;
	cout<<rombos<<" rombos\n";
	int valor = determinar_valor(rombos);
	cout<<"Billete de "<<valor<<" pesos"<<"\n";
	
//	Presentacion de resultados
	vector<Mat> imagenes = {billete,billete_rest,roi,roi_u};
	Mat mosaico_ori = concatenar_v_gray(imagenes);
	
//	Ventanas
	namedWindow("Resultados",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Resultados",mosaico_ori); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
