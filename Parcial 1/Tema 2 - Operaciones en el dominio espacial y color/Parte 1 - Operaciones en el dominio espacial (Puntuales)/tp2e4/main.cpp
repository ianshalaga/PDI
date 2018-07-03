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
	
	Mat imagen = imread("huang2.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	info(imagen);
	
	vector<Mat> planos = planos_bits(imagen);
	vector<Mat> sumas = suma_planos(planos);
	vector<Mat> planos_bin = planos_bits_bin(planos);
	
	Mat histo1 = draw_hist(histogram(imagen,256));
	Mat histo2 = draw_hist(histogram(sumas[7],256));
	
//	Ventanas
	namedWindow("Histo1",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Histo1",histo1); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Histo2",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Histo2",histo2); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Entrada",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Entrada",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Bit 0",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Bit 0",planos_bin[0]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Bit 1",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Bit 1",planos_bin[1]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Bit 2",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Bit 2",planos_bin[2]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Bit 3",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Bit 3",planos_bin[3]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Bit 4",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Bit 4",planos_bin[4]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Bit 5",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Bit 5",planos_bin[5]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Bit 6",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Bit 6",planos_bin[6]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Bit 7",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Bit 7",planos_bin[7]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Suma 0",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Suma 0",sumas[0]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Suma 1",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Suma 1",sumas[1]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Suma 2",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Suma 2",sumas[2]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Suma 3",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Suma 3",sumas[3]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Suma 4",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Suma 4",sumas[4]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Suma 5",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Suma 5",sumas[5]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Suma 6",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Suma 6",sumas[6]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Suma 7",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Suma 7",sumas[7]); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
