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

int contar_blancos(Mat imagen,int inicio,int fin) {
	int filas = imagen.rows;
	int columnas = imagen.cols;
	int c = 0;
	for (int i=0;i<filas;i++) {
		for (int j=inicio;j<fin;j++) {
			if (imagen.at<uchar>(i,j) == 255) {
				c = c + 1;
			}
		}
	}
	return c;
}
