#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

using namespace std;
using namespace pdi;
using namespace cv;

Mat dibujar_circulos(const Mat &imagen,const Mat &centroides,const int &radio) {
	
	int filas = centroides.rows;
	
	Mat circulos = imagen.clone();
	
	for(int i=0;i<filas;i++) { 
		Point p(centroides.at<double>(i,0),centroides.at<double>(i,1));
		circle(circulos,p,radio,Scalar(255,0,0),3);
	}
		
	return circulos;
}
