#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

using namespace std;
using namespace pdi;
using namespace cv;

Mat cambiar_valor(Mat imagen,int valor) {
	
	Mat salida = imagen.clone();
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	for(int i=0;i<filas;i++) { 
		for(int j=0;j<columnas;j++) { 
			if (salida.at<uchar>(i,j) == valor)
				salida.at<uchar>(i,j) = 255;
			else
				salida.at<uchar>(i,j) = 0;
		}
	}
	
	return salida;
}
