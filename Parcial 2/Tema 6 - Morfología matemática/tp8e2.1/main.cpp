#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int main(int argc, char** argv) {
	
	Mat imagen = imread("gracias_francu.png",CV_LOAD_IMAGE_GRAYSCALE);
	
	Mat ee = elemento_estructurante();
	print(ee,cout);
	
	Mat ap = apertura(imagen,ee);
	Mat cr = cierre(imagen,ee);
	
	vector<Mat> imagenes = {imagen,ap,cr};
	Mat muestra = concatenar_v_gray(imagenes);
	
	imwrite("muestra.png",muestra);
	
	//	Ventanas
	namedWindow("Muestra",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Muestra",muestra); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
