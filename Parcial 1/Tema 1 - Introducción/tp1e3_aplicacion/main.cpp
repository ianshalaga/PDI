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

int main(int argc,char **argv){
//	Carga una imagen en escala de grises	
	Mat imagen=imread("botellas.tif",CV_LOAD_IMAGE_GRAYSCALE);
	
//	Muestra información la imagen
	info(imagen);
	
	Mat perfil_v = achatar_v(imagen);
	Mat perfil_v_b = umbral(perfil_v,30);

	vector<int> b = botellas(perfil_v_b);

//	for (int i=0;i<b.size();i++) {
//		cout<<b[i]<<"\n";
//	}
	
//	Mat umbral_capacidad = umbral_negativo(imagen,30);
	Mat umbral_llena = umbral_negativo(imagen,235);
	
	vector<int> prom_llena = promedio_intensidad(umbral_llena,b);
//	vector<int> prom_cap = promedio_intensidad(umbral_capacidad,b);
	
	vector<int> no_llen = no_llenas(b,prom_llena);
	
//	Una botella llena debe tener un promedio de intensidad mayor a 222
//	Una botella vacia tiene un promedio de intensidad de 40 

	for (int i=0;i<no_llen.size();i++) {
		cout<<no_llen[i]<<"\n";
	}

	vector<int> porc_llen = porcentaje_llenado(umbral_llena,no_llen);
	
	for (int i=0;i<porc_llen.size();i++) {
		cout<<porc_llen[i]<<"\n";
	}	
	
	namedWindow("Imagen original",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen original",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
//	namedWindow("umbral capacidad",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("umbral capacidad",umbral_capacidad); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen

	namedWindow("umbral llena",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("umbral llena",umbral_llena); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Perfil Vertical",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Perfil Vertical",perfil_v); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Perfil Vertical Binarizado",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Perfil Vertical Binarizado",perfil_v_b); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
}
