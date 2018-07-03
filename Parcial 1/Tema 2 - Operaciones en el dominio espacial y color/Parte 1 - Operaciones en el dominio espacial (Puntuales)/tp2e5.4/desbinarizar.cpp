#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "bitset"
//#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat desbinarizar(const Mat &imagen,const int &bit) {
	
	Mat desbinarizada = imagen.clone();
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	for(int i=0;i<filas;i++) { 
		for(int j=0;j<columnas;j++) { 
			if (imagen.at<uchar>(i,j) == 0)
				desbinarizada.at<uchar>(i,j) = 0;
			else
				desbinarizada.at<uchar>(i,j) = pow(2,bit);
		}
	}
	
	return desbinarizada;
}
