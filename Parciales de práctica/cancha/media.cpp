#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "vector"

using namespace std;
using namespace pdi;
using namespace cv;

float media(Mat imagen) {
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	float promedio;
	float suma = 0;
	int cantidad = filas*columnas;
	
	for(int i=0;i<filas;i++) { 
		for(int j=0;j<columnas;j++) { 
			suma += imagen.at<uchar>(i,j);
		}
	}
	
	promedio = suma/cantidad;
	
	return promedio;
}
