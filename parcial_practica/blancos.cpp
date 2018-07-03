#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "vector"

using namespace std;
using namespace pdi;
using namespace cv;

vector<int> blancos(const Mat &perfil_v) {
	
	int columnas = perfil_v.cols;
	bool contar = true;
	int numero = 0;
	
	for (int i=0;i<columnas;i++) {
		if (perfil_v.at<uchar>(0,i) == 255 && contar == true) {
			numero = numero + 1;
			contar = false;
		}
		else if (perfil_v.at<uchar>(0,i) == 0 && contar == false)
			contar = true;
	}
	
	vector<int> blanco(numero*2);
	
	if (perfil_v.at<uchar>(0,columnas-1) == 255)
		blanco[numero*2-1] = columnas-1;
	
	contar = true;
	int c = 0;
	
	for (int i=0;i<columnas;i++) {
		if (perfil_v.at<uchar>(0,i) == 255 && contar == true) {
			blanco[c] = i;
			contar = false;
			c = c+1;
		}
		else if (perfil_v.at<uchar>(0,i) == 0 && contar == false) {
			contar = true;
			blanco[c] = i-1;
			c = c+1;
		}
	}
	
	return blanco;
}
