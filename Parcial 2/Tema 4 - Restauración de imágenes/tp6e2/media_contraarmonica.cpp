#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

//	Q > 0  elimina pimienta
//	Q < 0  elimina sal
//	Q = 0  media aritmetica
//	Q = -1 media armonica

Mat media_armonica(const Mat &imagen,const int &kf,const int &kc) {
	
	Mat media = imagen.clone();
	media.convertTo(media,CV_64F,1./255);
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	int kf2 = kf/2;
	int kc2 = kc/2;
	double cantidad = kf*kc;
//	cout<<cantidad<<"\n";
	
	for(int i=kf2;i<filas-kf2;i++) { 
		for(int j=kc2;j<columnas-kc2;j++) { 
			double suma = 0;
			for(int ki=i-kf2;ki<i+1+kf2;ki++) {
				for(int kj=j-kc2;kj<j+1+kc2;kj++) {
					suma += pow(media.at<double>(ki,kj),-1);
				}
			}
			media.at<double>(i,j) = cantidad/suma;
		}
	}
	
	media.convertTo(media,CV_8UC(1),255);
	
	return media;
}
