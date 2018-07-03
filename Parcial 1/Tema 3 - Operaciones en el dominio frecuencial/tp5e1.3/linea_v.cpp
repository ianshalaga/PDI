#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
//#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat linea_v(const Mat &imagen) {
	
	Mat linea_vertical = imagen.clone();
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	Point p1(columnas/2,0);
	Point p2(columnas/2,columnas);
	
	line(linea_vertical,p1,p2,Scalar(255));
	
	return linea_vertical;
}
