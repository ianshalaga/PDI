#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

// Todos estos metodos son sencibles al ruido

int main(int argc, char** argv) {
	
//	Mat imagen = imread("subs1.png",CV_LOAD_IMAGE_GRAYSCALE);
	Mat imagen = imread("subs2.png",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat imagen2 = imread("huang2.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat imagen3 = imread("luna.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat imagen = imread("subs2_rotada.png",CV_LOAD_IMAGE_GRAYSCALE);
	
	Mat color_dst,dst,imagen_u;
	int nt = threshold(imagen,imagen_u,0,255,THRESH_OTSU|THRESH_BINARY);
	Canny(imagen,dst,nt,nt,3);
	
	vector<Vec2f> lineas1;
	HoughLines(dst,lineas1,1,CV_PI/2,100);
	color_dst = lineas_hough(dst,lineas1);
	
//	cout<<lineas1.size()<<"\n";
//	
//	for(int i=0;i<lineas1.size();i++) { 
//		cout<<lineas1[i]<<"\n";
//	}
	
	
	
//	vector<Vec4i> lines;
//	HoughLinesP(dst, lines, 1, CV_PI/180, 50, 50, 10 );
//	color_dst = lineas_houghP(dst,lines);
	
//	Mat rotada = rotate(imagen,(lineas1[0][1]-CV_PI/2)*180/CV_PI);
	
	namedWindow("Imagen original",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen original",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Hough Lines",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Hough Lines",color_dst); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
