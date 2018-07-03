#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int suma_kernel(const Mat &kernel) {
	
	int filas = kernel.rows;
	int columnas = kernel.cols;
	int suma = 0;
	
	for(int i=0;i<filas;i++) { 
		for(int j=0;j<columnas;j++) { 
			suma += kernel.at<double>(i,j);
		}
	}
	
	return suma;
}
