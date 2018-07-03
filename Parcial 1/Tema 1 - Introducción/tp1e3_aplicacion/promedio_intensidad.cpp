#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "vector"

using namespace std;
using namespace pdi;
using namespace cv;

vector<int> promedio_intensidad(Mat imagen,vector<int> botellas) {
	vector<int> promedio(botellas.size()/2);
	int filas = imagen.rows;
	for (int b=0;b<botellas.size();b+=2) {
		int intensidad = 0;
		for (int i=0;i<filas;i++) {
			for (int j=botellas[b];j<botellas[b+1];j++) {
				intensidad+=imagen.at<uchar>(i,j);
			}
		}
		promedio[b/2] = intensidad/(filas*(botellas[b+1]-botellas[b]));
	}
	return promedio;
}
