#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat media_aritmetica(const Mat &imagen,const int kf,const int kc) {
	
	Mat media = imagen.clone();
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	int kf2 = kf/2;
	int kc2 = kc/2;
	
	for(int i=kf2;i<filas-kf2;i++) { 
		for(int j=kc2;j<columnas-kc2;j++) { 
			int suma = 0;
			for(int ki=i-kf2;ki<i+1+kf2;ki++) {
				for(int kj=j-kc2;kj<j+1+kc2;kj++) {
					suma += media.at<uchar>(ki,kj);
				}
			}
			media.at<uchar>(i,j) = suma/(kf*kc);
		}
	}
	
	return media;
}
