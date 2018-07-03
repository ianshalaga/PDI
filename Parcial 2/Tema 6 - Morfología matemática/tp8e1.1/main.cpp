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
	
//	Mat imagen = imread("lluviaEstrellas.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	
	Mat ip = imagen_prueba();
	Mat ee = elemento_estructurante();
	print(ee,cout);
	
	Mat dilatacion,erosion;
	dilate(ip,dilatacion,ee,Point(-1,-1));
	erode(ip,erosion,ee,Point(-1,-1));
	
	vector<Mat> imagenes = {ip,dilatacion,erosion};
	Mat muestra = concatenar_h_gray(imagenes);
	
	//	Ventanas
	namedWindow("Muestra",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Muestra",muestra); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
