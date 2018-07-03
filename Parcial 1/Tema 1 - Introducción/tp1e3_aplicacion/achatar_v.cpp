#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

using namespace std;
using namespace pdi;
using namespace cv;

//Achatamiento vertical, cada columna es el promedio de intensidades de dicha columna
Mat achatar_v(Mat imagen) {
	int filas = imagen.rows;
	int columnas = imagen.cols;
	Mat perfil_v(1,columnas,CV_8UC(1),Scalar(0));
	for (int i=0;i<columnas;i++) { //recorre columnas
		int suma = 0;
		for (int j=0;j<filas;j++) { //recorre filas
			suma = suma + imagen.at<uchar>(j,i);
		}
		perfil_v.at<uchar>(0,i) = suma/filas;
	}
	return perfil_v;
}
