#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
//#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat cuadrilatero(Mat imagen,int prop_x,int prop_y) {
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	Mat cuad(filas,columnas,CV_8UC(1),Scalar(0));
	
	int paso_x = (columnas/16)*prop_x;
	int paso_y = (filas/16)*prop_y;
	int centro_x = columnas/2;
	int centro_y = filas/2;
	
	Point p1(centro_x-paso_x,centro_y-paso_y);
	Point p2(centro_x+paso_x,centro_y+paso_y);
	
	rectangle(cuad,p1,p2,Scalar(255),-1);
	
	return cuad;
}
