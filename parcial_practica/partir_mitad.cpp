#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

vector<Mat> partir_mitad(const Mat &imagen,const bool &tipo) {
	
	int filas = imagen.rows;
	int columnas = imagen.cols;
	vector<Mat> divididas(2);
	
	if (tipo == true) { // division horizontal
		Rect arriba(0,0,columnas,filas/2);
		Rect abajo(0,filas/2,columnas,filas/2);
		divididas[0] = imagen(arriba);
		divididas[1] = imagen(abajo);
	}
	
	if (tipo == false) { // division vertical
		Rect izquierda(0,0,columnas/2,filas);
		Rect derecha(columnas/2,0,columnas/2,filas);
		divididas[0] = imagen(izquierda);
		divididas[1] = imagen(derecha);
	}
	
	return divididas;
}
