#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int promedio(Mat imagen) {
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	int suma = 0;
	int cantidad = filas*columnas;
	
	for (int i=0;i<filas;i++) {
		for (int j=0;j<columnas;j++) {
			suma += imagen.at<uchar>(i,j);
		}
	}
	
	return suma/cantidad;
}
