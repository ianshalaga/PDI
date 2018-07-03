#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat media_geometrica(const Mat &imagen,const int kf,const int kc) {
	
	Mat media = imagen.clone();
	media.convertTo(media,CV_64F,1./255);
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	int kf2 = kf/2;
	int kc2 = kc/2;
	
	for(int i=kf2;i<filas-kf2;i++) { 
		for(int j=kc2;j<columnas-kc2;j++) { 
			float producto = 1;
			for(int ki=i-kf2;ki<i+1+kf2;ki++) {
				for(int kj=j-kc2;kj<j+1+kc2;kj++) {
					if (media.at<double>(ki,kj) == 0)
						producto *= 1./255;
					else
						producto *= media.at<double>(ki,kj);
				}
			}
			media.at<double>(i,j) = pow(producto,1./(kf*kc));
		}
	}
	media.convertTo(media,CV_8UC(1),255);
	
	return media;
}
