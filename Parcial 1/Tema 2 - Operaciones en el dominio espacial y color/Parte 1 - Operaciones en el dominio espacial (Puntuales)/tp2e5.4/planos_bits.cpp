#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "bitset"
//#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

vector<Mat> planos_bits(Mat imagen) {
	
	vector<Mat> planos(8);
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	
	for(int k=0;k<planos.size();k++) { 
		Mat plano(filas,columnas,CV_8UC(1));
		planos[k] = plano;
		for(int i=0;i<filas;i++) { 
			for(int j=0;j<columnas;j++) { 
				string binario = bitset<8>(imagen.at<uchar>(i,j)).to_string();
				string resultado;
				ostringstream convertir;
				convertir << binario[7-k];
				resultado = convertir.str();
				binario = string(7-k,'0') + resultado + string(k,'0');
				unsigned long decimal = bitset<8>(binario).to_ulong();
				if (decimal == pow(2,k))
					planos[k].at<uchar>(i,j) = decimal;
				else
					planos[k].at<uchar>(i,j) = 0;
			}
		}
	}
		
	return planos;
}
