#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
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

int main(int argc, char** argv) {
	
	Mat imagen = imread("rosas.jpg");
	
//  Definir ROI
	namedWindow("Definir ROI",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Definir ROI",imagen); //muestra la imagen en la ventana
	puntos_roi pr;
	setMouseCallback("Definir ROI",clic,&pr);
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen	
	
	Rect area(pr.p1,pr.p2);
	Mat roi = imagen(area);
	
//  Segmentacion
	Mat mascara_h(imagen.size(),CV_8UC(1),Scalar(0));
	Mat mascara_s(imagen.size(),CV_8UC(1),Scalar(0));
	Mat mascara_v(imagen.size(),CV_8UC(1),Scalar(0));
	vector<Mat> mascara_hsv = {mascara_h,mascara_s,mascara_v};
	
	Mat imagen_hsv,roi_hsv;
	cvtColor(imagen,imagen_hsv,CV_BGR2HSV);
	cvtColor(roi,roi_hsv,CV_BGR2HSV);
	vector<Mat> imagen_hsv_v,roi_hsv_v;
	split(imagen_hsv,imagen_hsv_v);
	split(roi_hsv,roi_hsv_v);
	
	Mat histo_roi_h = draw_hist(histogram(roi_hsv_v[0],256));
	Mat histo_roi_s = draw_hist(histogram(roi_hsv_v[1],256));
	Mat histo_roi_v = draw_hist(histogram(roi_hsv_v[2],256));
	
	int prom_roi_h = promedio_intensidad(roi_hsv_v[0]);
	int prom_roi_s = promedio_intensidad(roi_hsv_v[1]);
	
	inRange(imagen_hsv_v[0],prom_roi_h-10,prom_roi_h+10,mascara_hsv[0]);
	inRange(imagen_hsv_v[1],prom_roi_s-75,prom_roi_s+75,mascara_hsv[1]);
	inRange(imagen_hsv_v[2],0,255,mascara_hsv[2]);
	
	Mat mask = and_mascaras(mascara_hsv);
	
	// Descarte de regiones erroneas
	Mat kernel = gauss_kernel(3,0.5);
	mask = umbral(convolve(mask,kernel),200);
	//
	
	Mat res1 = multiplicacion(imagen_hsv_v[0],mask);
	Mat res2 = multiplicacion(imagen_hsv_v[1],mask);
	Mat res3 = multiplicacion(imagen_hsv_v[2],mask);
	imagen_hsv_v[0] = res1;
	imagen_hsv_v[1] = res2;
	imagen_hsv_v[2] = res3;
	merge(imagen_hsv_v,imagen_hsv);
	Mat rosas;
	cvtColor(imagen_hsv,rosas,CV_HSV2BGR);
	
//  Identificacion de regiones mediante el etiquetado de componentes conectadas
	Mat componentes_conectadas,estadisticas,centroides;
	connectedComponentsWithStats(mask,componentes_conectadas,estadisticas,centroides);
//	print(centroides,cout);
	
	// Cantidad de rosas presentes en la imagen original
	double min,max;
	minMaxLoc(componentes_conectadas,&min,&max);
	int numero_objetos = max;
	cout<<numero_objetos<<"\n";
	//
	
	componentes_conectadas.convertTo(componentes_conectadas,CV_8UC(1));
	int etiqueta = 17;
	Mat etiquetas = umbral(componentes_conectadas,etiqueta);
	
//	Circulos en los centroides de las rosas
	Mat circulos = dibujar_circulos(imagen,centroides,15);
	
	vector<Mat> mosaico = {imagen,mask,rosas,circulos};
	Mat conc = concatenar_h_color(mosaico);
	imwrite("conc.jpg",conc);
	
//	Ventanas
	namedWindow("Imagen original",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen original",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("ROI",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("ROI",roi); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
//	namedWindow("Histograma ROI H",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("Histograma ROI H",histo_roi_h); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
//	
//	namedWindow("Histograma ROI S",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("Histograma ROI S",histo_roi_s); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
//	
//	namedWindow("Histograma ROI V",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("Histograma ROI V",histo_roi_v); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Mascara",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Mascara",mask); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Rosas",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Rosas",rosas); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Componentes conectadas",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Componentes conectadas",etiquetas); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("circulos",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("circulos",circulos); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
