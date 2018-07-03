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
	Mat imagen=imread("huang2_2.png",CV_LOAD_IMAGE_GRAYSCALE);
	Mat resultado;
	
	Mat lut_table(256,1,CV_8UC(1),Scalar(255)); //imagen de una dimension
	
//	Muestra información la imagen
	info(imagen);
	
//	transformacion_rectilinea(lut_table,0.5,0);
	
//	Negativo
//	transformacion_rectilinea(lut_table,-1,255);
	
	transformacion_tramos(lut_table,{0,100,200,255},{0,0,255,255});
	
	print(lut_table,cout);
	
	Mat transformacion = draw_graph(lut_table);
	
	LUT(imagen,lut_table,resultado);
	
	imwrite("huang2_3.png",resultado);
	
	namedWindow("Imagen original",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen original",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Transformacion",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Transformacion",transformacion); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Tabla LUT",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Tabla LUT",lut_table); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Imagen Transformada",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen Transformada",resultado); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
