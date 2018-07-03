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
	Mat imagen1 = imread("cielo_contraste.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	Mat imagen2 = imread("refucilo.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	
	resize(imagen1,imagen1,imagen2.size(),0,0,INTER_LINEAR);
	
	info(imagen1);
	info(imagen2);
	
	Mat imagen = mosaic(imagen1,imagen2,false);
	
//	Suma 
	Mat sum = suma(imagen1,imagen2,0.5);
	
//	Resta
	Mat diferencia1 = resta(imagen1,imagen2);
	Mat diferencia2 = resta(imagen2,imagen1);
	Mat diferencia = mosaic(diferencia1,diferencia2,false);
	
//	Producto
	Mat mask_cuadrada = cuadrilatero(imagen1,3,3);
	Mat mask_circular = circulo(imagen1,100);
	
	Mat producto1 = multiplicacion(imagen2,mask_cuadrada);
	Mat producto2 = multiplicacion(imagen2,mask_circular);
	Mat producto = mosaic(producto1,producto2,false);
	
//	Division
//	Mat imagen1_div, imagen2_div;
//	imagen1.convertTo(imagen1_div,CV_64F);
//	imagen2.convertTo(imagen2_div,CV_64F);
	
	Mat div1 = division(imagen1,imagen2);
	Mat div2 = division(imagen2,imagen1);
	Mat div = mosaic(div1,div2,false);
	
//	Ventanas
	
	namedWindow("Imagen 1 | Imagen 2",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen 1 | Imagen 2",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Suma",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Suma",sum); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Imagen 1 - Imagen 2 | Imagen 2 - Imagen 1",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen 1 - Imagen 2 | Imagen 2 - Imagen 1",diferencia); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Multiplicacion",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Multiplicacion",producto); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Imagen1/Imagen2 | Imagen2/Imagen1",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen1/Imagen2 | Imagen2/Imagen1",div); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
