#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int superficie(Mat imagen,int referencia) {
	int superficie = 0;
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	for(int i=0;i<filas;i++) { 
		for(int j=0;j<columnas;j++) { 
			if (imagen.at<uchar>(i,j) == referencia)
				superficie+=1;
		}
	}
	
	return superficie;
}
