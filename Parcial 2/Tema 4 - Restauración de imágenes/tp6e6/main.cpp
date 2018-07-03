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
	
//	Carga de imagenes
	Mat familia_a = imread("FAMILIA_a.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	Mat familia_b = imread("FAMILIA_b.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	Mat familia_c = imread("FAMILIA_c.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	
//	Informacion de las imagenes cargadas
	stats(familia_a);
	stats(familia_b);
	stats(familia_c);
	
//  Definir ROI (la misma para todas las imagenes)
	namedWindow("Definir ROI",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Definir ROI",familia_a); //muestra la imagen en la ventana
	puntos_roi pr;
	setMouseCallback("Definir ROI",clic,&pr);
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen	
	
	Rect area(pr.p1,pr.p2);
	Mat roi_a = familia_a(area);
	Mat roi_b = familia_b(area);
	Mat roi_c = familia_c(area);
	
//	Informacion de las ROIs
	stats(roi_a);
	stats(roi_b);
	stats(roi_c);
	
//	Histogramas de las ROIs
	Mat histo_a = draw_hist(histogram(roi_a,256)); // ruido gaussiano
	Mat histo_b = draw_hist(histogram(roi_b,256)); // ruido uniforme
	Mat histo_c = draw_hist(histogram(roi_c,256)); // ruido impulsivo (sal y pimienta)
	
//	Restauracion
	/*Familia a*/
	Mat media_a,stdev_a;
	meanStdDev(familia_a,media_a,stdev_a);
	Mat gauss_a = gauss_kernel(3,stdev_a.at<double>(0,0));
	Mat familia_a_rest = convolve(familia_a,gauss_a);
//	int prom1 = promedio_intensidad(familia_a_rest);
//	cout<<prom1<<"\n";
//	
//	vector<Mat> familia_a_rest_v = imagenes_ruidosas(familia_a_rest,50,0,stdev_a.at<double>(0,0));
//	familia_a_rest = reduccion_ruido(familia_a_rest_v);
//	int prom2 = promedio_intensidad(familia_a_rest);
//	cout<<prom2<<"\n";
//	
//	int dif = 2*(prom1-prom2);
//	Mat lut_table(256,1,CV_8UC(1),Scalar(255));
//	transformacion_rectilinea(lut_table,1,dif);
//	LUT(familia_a_rest,lut_table,familia_a_rest);
	
	/*Familia b*/
	Mat media_b,stdev_b;
	meanStdDev(familia_b,media_b,stdev_b);
	Mat gauss_b = gauss_kernel(3,stdev_b.at<double>(0,0));
	Mat familia_b_rest = convolve(familia_b,gauss_b);
	
	/*Familia c*/
	Mat familia_c_rest;
	medianBlur(familia_c,familia_c_rest,3);
	
//	ROIs restauradas
	Mat roi_a_rest = familia_a_rest(area);
	Mat roi_b_rest = familia_b_rest(area);
	Mat roi_c_rest = familia_c_rest(area);
	
//	Histogramas de las ROIs restauradas
	Mat histo_a_rest = draw_hist(histogram(roi_a_rest,256)); // ruido gaussiano
	Mat histo_b_rest = draw_hist(histogram(roi_b_rest,256)); // ruido uniforme
	Mat histo_c_rest = draw_hist(histogram(roi_c_rest,256)); // ruido impulsivo (sal y pimienta)
	
//	Presentacion de resultados
	vector<Mat> imagenes = {familia_a,familia_b,familia_c};
	Mat mosaico = concatenar_v_gray(imagenes);
	
	vector<Mat> rois = {roi_a,roi_b,roi_c};
	Mat mosaico_rois = concatenar_v_gray(rois);
	
	vector<Mat> histogramas = {histo_a,histo_b,histo_c};
	Mat mosaico_hist = concatenar_v_gray(histogramas);
	
	vector<Mat> restauradas = {familia_a_rest,familia_b_rest,familia_c_rest};
	Mat mosaico_rest = concatenar_v_gray(restauradas);
	
	vector<Mat> rois_rest = {roi_a_rest,roi_b_rest,roi_c_rest};
	Mat mosaico_rois_rest = concatenar_v_gray(rois_rest);
	
	vector<Mat> histogramas_rest = {histo_a_rest,histo_b_rest,histo_c_rest};
	Mat mosaico_hist_rest = concatenar_v_gray(histogramas_rest);
	
//	Ventanas
	namedWindow("Resultados",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Resultados",mosaico); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("ROIs",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("ROIs",mosaico_rois); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Histogramas",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Histogramas",mosaico_hist); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Restauradas",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Restauradas",mosaico_rest); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("ROIs restauradas",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("ROIs restauradas",mosaico_rois_rest); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Histogramas (restauradas)",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Histogramas (restauradas)",mosaico_hist_rest); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
