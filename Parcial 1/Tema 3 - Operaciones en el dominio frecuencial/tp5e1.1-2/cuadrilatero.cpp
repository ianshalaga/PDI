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
	
	Mat cuad = imagen.clone();
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	int paso_x = (columnas/16)*prop_x;
	int paso_y = (columnas/16)*prop_y;
	int centro = columnas/2;
	
	Point p1(centro-paso_x,centro-paso_y);
	Point p2(centro+paso_x,centro+paso_y);
	
	rectangle(cuad,p1,p2,Scalar(255),-1);
	
	return cuad;
}
