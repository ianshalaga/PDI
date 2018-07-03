#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
//#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat circulo(Mat imagen,int radio) {
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	Mat circ(filas,columnas,CV_8UC(1),Scalar(0));
	
	int centro_x = columnas/2;
	int centro_y = filas/2;
	
	Point c(centro_x,centro_y);
	
	circle(circ,c,radio,Scalar(255),-1);
	
	return circ;
}
