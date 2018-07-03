#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat and_mascaras(vector<Mat> mascaras,int referencia) {
	
	int filas = mascaras[0].rows;
	int columnas = mascaras[0].cols;
	Mat mask(filas,columnas,CV_8UC(1),Scalar(255));
	
	for(int k=0;k<mascaras.size();k++) { 
		for(int i=0;i<filas;i++) { 
			for(int j=0;j<columnas;j++) { 
				if (mascaras[k].at<uchar>(i,j) == referencia || mask.at<uchar>(i,j) == referencia)
					mask.at<uchar>(i,j) = 0;
				else
					mask.at<uchar>(i,j) = 255;
			}
		}
	}
	
	return mask;
}
