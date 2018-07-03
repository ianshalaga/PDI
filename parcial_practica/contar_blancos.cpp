#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "vector"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int contar_blancos(const Mat &imagen,const int &ini_f,const int &fin_f,const int &ini_c,const int &fin_c) {
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	int c = 0;
	
	for (int i=ini_f;i<fin_f;i++) {
		for (int j=ini_c;j<fin_c;j++) {
			if (imagen.at<uchar>(i,j) == 255) {
				c = c + 1;
			}
		}
	}
	
	return c;
}
