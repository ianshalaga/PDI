#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "bitset"
#include "pdi_functions.h"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int main(int argc, char** argv) {
	
	Mat imagen = imread("esqueleto.tif",CV_LOAD_IMAGE_GRAYSCALE);
	
	Mat lut_table(256,1,CV_8UC(1),Scalar(255)); //imagen de una dimension
	
	float gamma = 2;
	transformacion_potencia(lut_table,255./pow(255,gamma),gamma);
	Mat potencia;
	LUT(imagen,lut_table,potencia);
	
	
//	Mat mediana;
//	medianBlur(imagen,mediana,3);
//	Mat kernel_gauss = filtro_pb(3,3);
//	Mat imagen_gauss = convolve(imagen,kernel_gauss);
	
//	Mat kernel_pa = filtro_pa(3,3,0);
//	Mat imagen_pa = convolve(mediana,kernel_pa);
	
//	Mat sum = suma(potencia,potencia,0.5);
	
//	Ventanas
	namedWindow("Imagen",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("imagen_gauss",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("imagen_gauss",potencia); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
