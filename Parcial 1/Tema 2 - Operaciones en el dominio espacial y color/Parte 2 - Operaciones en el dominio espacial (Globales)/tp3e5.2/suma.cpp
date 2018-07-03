#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
//#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat suma(Mat imagen1,Mat imagen2,float alfa) {
	int filas = imagen1.rows;
	int columnas = imagen1.cols;
	
	Mat imagen(filas,columnas,CV_8UC(1));
		
	for(int i=0;i<filas;i++) { 
		for(int j=0;j<columnas;j++) { 
			imagen.at<uchar>(i,j) = (1-alfa)*imagen1.at<uchar>(i,j)+alfa*imagen2.at<uchar>(i,j);
		}
	}
	
	return imagen;
}
