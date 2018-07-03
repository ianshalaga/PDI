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
	
	Mat imagenA = imread("imagenA.tif",CV_LOAD_IMAGE_GRAYSCALE);
	Mat imagenB = imread("imagenB.tif",CV_LOAD_IMAGE_GRAYSCALE);
	Mat imagenC = imread("imagenc.tif",CV_LOAD_IMAGE_GRAYSCALE);
	Mat imagenD = imread("imagenD.tif",CV_LOAD_IMAGE_GRAYSCALE);
	Mat imagenE = imread("imagenE.tif",CV_LOAD_IMAGE_GRAYSCALE);
	
	Mat histo1 = imread("histo1.tif",CV_LOAD_IMAGE_GRAYSCALE);
	Mat histo2 = imread("histo2.tif",CV_LOAD_IMAGE_GRAYSCALE);
	Mat histo3 = imread("histo3.tif",CV_LOAD_IMAGE_GRAYSCALE);
	Mat histo4 = imread("histo4.tif",CV_LOAD_IMAGE_GRAYSCALE);
	Mat histo5 = imread("histo5.tif",CV_LOAD_IMAGE_GRAYSCALE);
	
	Mat histograma1 = draw_hist(histogram(imagenA,256));
	Mat histograma2 = draw_hist(histogram(imagenB,256));
	Mat histograma3 = draw_hist(histogram(imagenC,256));
	Mat histograma4 = draw_hist(histogram(imagenD,256));
	Mat histograma5 = draw_hist(histogram(imagenE,256));

	resize(histograma1,histograma1,imagenA.size(),0,0,INTER_LINEAR);
	resize(histograma2,histograma2,imagenB.size(),0,0,INTER_LINEAR);
	resize(histograma3,histograma3,imagenC.size(),0,0,INTER_LINEAR);
	resize(histograma4,histograma4,imagenD.size(),0,0,INTER_LINEAR);
	resize(histograma5,histograma5,imagenE.size(),0,0,INTER_LINEAR);
	
	resize(histo2,histo2,imagenA.size(),0,0,INTER_LINEAR);
	resize(histo4,histo4,imagenB.size(),0,0,INTER_LINEAR);
	resize(histo1,histo1,imagenC.size(),0,0,INTER_LINEAR);
	resize(histo5,histo5,imagenD.size(),0,0,INTER_LINEAR);
	resize(histo3,histo3,imagenE.size(),0,0,INTER_LINEAR);
	
	Mat analisis1 = mosaic(mosaic(imagenA,histograma1,false),histo2,false);
	Mat analisis2 = mosaic(mosaic(imagenB,histograma2,false),histo4,false);
	Mat analisis3 = mosaic(mosaic(imagenC,histograma3,false),histo1,false);
	Mat analisis4 = mosaic(mosaic(imagenD,histograma4,false),histo5,false);
	Mat analisis5 = mosaic(mosaic(imagenE,histograma5,false),histo3,false);
	
//	Ventanas
	namedWindow("Analisis A",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Analisis A",analisis1); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen

	namedWindow("Analisis B",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Analisis B",analisis2); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen	
	
	namedWindow("Analisis C",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Analisis C",analisis3); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen	
	
	namedWindow("Analisis D",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Analisis D",analisis4); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen	
	
	namedWindow("Analisis E",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Analisis E",analisis5); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen	
	
	return 0;
} 
