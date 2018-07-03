#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
//#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat linea_h(Mat imagen) {
	
	Mat linea_horizontal = imagen.clone();
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	Point p1(0,filas/2);
	Point p2(filas,filas/2);
	
	line(linea_horizontal,p1,p2,Scalar(255));
	
	return linea_horizontal;
}
