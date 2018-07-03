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
	
	Mat circ = imagen.clone();
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	int centro = columnas/2;
	
	Point c(centro,centro);
	
	circle(circ,c,radio,Scalar(255),-1);
	
	return circ;
}
