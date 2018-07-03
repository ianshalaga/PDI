#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

using namespace std;
using namespace pdi;
using namespace cv;

//Achatamiento horizontal, cada fila es el promedio de intensidades de dicha fila
Mat achatar_h(Mat imagen) {
	int filas = imagen.rows;
	int columnas = imagen.cols;
	Mat perfil_h(filas,1,CV_8UC(1),Scalar(0));
	for (int i=0;i<filas;i++) { //recorre filas
		int suma = 0;
		for (int j=0;j<columnas;j++) { //recorre columnas
			suma = suma + imagen.at<uchar>(i,j);
		}
		perfil_h.at<uchar>(i,0) = suma/columnas;
	}
	return perfil_h;
}
