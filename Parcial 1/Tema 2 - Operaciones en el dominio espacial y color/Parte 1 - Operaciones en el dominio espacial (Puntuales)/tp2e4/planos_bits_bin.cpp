#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "bitset"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

vector<Mat> planos_bits_bin(vector<Mat> planos) {
	
	vector<Mat> planos_bin(8);
	
	int filas = planos[0].rows;
	int columnas = planos[0].cols;
	
	for(int k=0;k<planos_bin.size();k++) { 
		Mat plano(filas,columnas,CV_8UC(1));
		planos_bin[k] = plano;
		for(int i=0;i<filas;i++) { 
			for(int j=0;j<columnas;j++) {
				if (planos[k].at<uchar>(i,j) == pow(2,k))
					planos_bin[k].at<uchar>(i,j) = 255;
				else
					planos_bin[k].at<uchar>(i,j) = 0;
			}
		}
	}
	
	return planos_bin;
}
