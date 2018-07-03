#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

/***************************************************************/

// Estructura de dos puntos para definir una ROI
struct puntos_roi {
	Point p1;
	Point p2;
};

// Obtener informacion del mouse
void clic(int evento,int x,int y,int flag,void* estructura) {
	// Conversion obligatoria
	puntos_roi &datos = *static_cast<puntos_roi*>(estructura);
	
	if (evento == CV_EVENT_LBUTTONDOWN) {
		datos.p1 = Point(x,y);
		cout<<"x: "<<x<<" "<<"y: "<<y<<"\n";
	}
	
	if (evento == CV_EVENT_LBUTTONUP) {
		datos.p2 = Point(x,y);
		cout<<"x: "<<x<<" "<<"y: "<<y<<"\n";
	}
	
//	cout<<x<<" "<<y<<"\n";	
}

/***************************************************************/

int main(int argc, char** argv) {
	
//	Mat placa1 = imread("a7v600-SE.tif",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat placa1 = imread("a7v600-X.tif",CV_LOAD_IMAGE_GRAYSCALE);
	
//	Mat placa1_ruido = imread("a7v600-SE(RImpulsivo).tif",CV_LOAD_IMAGE_GRAYSCALE);
	Mat placa1_ruido = imread("a7v600-X(RImpulsivo).tif",CV_LOAD_IMAGE_GRAYSCALE);

	Mat placa1_noruido;
	medianBlur(placa1_ruido,placa1_noruido,3);
	
	namedWindow("Definir ROI",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Definir ROI",placa1_noruido); //muestra la imagen en la ventana
	puntos_roi pr;
	setMouseCallback("Definir ROI",clic,&pr);
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen	

	Rect ROI(pr.p1,pr.p2);
	Mat micro = placa1_noruido(ROI);
	
	int prom = promedio_intensidad(micro);
	
	if (prom > 70)
		cout<<"a7v600-SE"<<"\n";
	else
		cout<<"a7v600-X"<<"\n";
	
	waitKey();
	
//	Mat reduc_ruido = mosaic(placa1_ruido,placa1_noruido,false);
//	
//	namedWindow("Reduccion de ruido",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("Reduccion de ruido",reduc_ruido); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen	
	
	return 0;
}
