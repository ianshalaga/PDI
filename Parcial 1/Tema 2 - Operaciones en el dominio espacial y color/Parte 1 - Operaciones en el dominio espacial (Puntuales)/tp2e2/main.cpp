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
	Mat imagen=imread("a7v600-SE(RImpulsivo).tif",CV_LOAD_IMAGE_GRAYSCALE);
	Mat resultado;
//	
	Mat lut_table(256,1,CV_8UC(1),Scalar(255)); //imagen de una dimension
//	
	//	Muestra información la imagen
	info(imagen);
	
//	transformacion_logaritmica(lut_table,45);
	
	float gamma = 2;
	transformacion_potencia(lut_table,255./pow(255,gamma),gamma);
	
	Mat transformacion = draw_graph(lut_table);
	
//	imwrite("rmn_n.png",resultado);
	
//	imagen = 255-imagen;
	
//	imwrite("rmn_n.png",imagen);
	medianBlur(imagen,imagen,3);
	LUT(imagen,lut_table,resultado);
//	resultado = 255-resultado;
//	medianBlur(resultado,resultado,3);
	
//	imwrite("rmn_f.png",resultado);
	
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
