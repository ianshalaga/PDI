#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "vector"

using namespace std;
using namespace pdi;
using namespace cv;

Mat recortar(Mat imagen,vector<int> recuadro_x,vector<int> recuadro_y) {
	int x_ini = recuadro_x[1]+1;
	int x_fin = recuadro_x[2]-1;
	int y_ini = recuadro_y[1]+1;
	int y_fin = recuadro_y[2]-1;

//	Mat recorte(y_fin-y_ini,x_fin-x_ini,CV_8UC(1));
	
//	int filas = imagen.rows;
//	int columnas = imagen.cols;
	
//	for (int i=0;i<filas;i++) {
//		for(int j=0;j<columnas;j++) {
//			if (j > x_ini && j < x_fin && i > y_ini && i < y_fin)
//				recorte.at<uchar>(i-y_ini,j-x_ini) = imagen.at<uchar>(i,j);
//		}
//	}
	
//	return recorte;
	
	Rect ROI(x_ini,y_ini,x_fin-x_ini,y_fin-y_ini);
	return imagen(ROI);
}
