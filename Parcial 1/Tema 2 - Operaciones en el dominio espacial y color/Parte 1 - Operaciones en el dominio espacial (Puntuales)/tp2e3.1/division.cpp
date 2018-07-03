#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat division(Mat imagen1,Mat imagen2) {

	int filas = imagen1.rows;
	int columnas = imagen1.cols;
	
	Mat imagen(filas,columnas,CV_64F);
	
	for(int i=0;i<filas;i++) { 
		for(int j=0;j<columnas;j++) { 
			if (imagen2.at<uchar>(i,j) == 0)
				imagen.at<double>(i,j) = imagen1.at<uchar>(i,j)*255.;
			else
				imagen.at<double>(i,j) = imagen1.at<uchar>(i,j)*(1./imagen2.at<uchar>(i,j));
		}
	}

	return imagen;
}
