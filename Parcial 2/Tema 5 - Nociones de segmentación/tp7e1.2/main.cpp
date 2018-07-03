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
	
	//	Mat imagen = imread("estanbul.tif",CV_LOAD_IMAGE_GRAYSCALE);
	//	Mat imagen = imread("huang2.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	//	Mat imagen = imread("luna.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	//	Mat imagen = imread("subs1.png",CV_LOAD_IMAGE_GRAYSCALE);
	Mat imagen = imread("subs2.png",CV_LOAD_IMAGE_GRAYSCALE);
	
	Mat kernel_ln4 = laplaciano_n4();
//	print(kernel_ln4,cout);
	Mat kernel_ln8 = laplaciano_n8();
//	print(kernel_ln8,cout);

	Mat kernel_log = lap_of_gauss();
//	print(kernel_log,cout);
	
	//---------------------------------------------------//	
	
	Mat prewitt = filtro_prewitt(imagen,100);
	
	Mat sobel = filtro_sobel(imagen,100);
	
	int n_t = 100;
	
	Mat laplaciano4 = umbral(convolve(imagen,kernel_ln4),n_t);
	Mat laplaciano8 = umbral(convolve(imagen,kernel_ln8),n_t);
	
	Mat l_of_g = umbral(convolve(imagen,kernel_log),n_t);
	
	//	Ventanas
	
	namedWindow("Imagen original",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen original",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Prewitt",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Prewitt",prewitt); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Sobel",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Sobel",sobel); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Laplaciano 4",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Laplaciano 4",laplaciano4); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Laplaciano 8",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Laplaciano 8",laplaciano8); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("LoG",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("LoG",l_of_g); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
