#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

/***************************************************************/

// Estructura de dos puntos para definir una ROI
struct puntos_roi {
	Point p1; // Abajo izquierda
	Point p2; // Arriba derecha
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
	
	Mat imagen = imread("huang2.jpg",CV_LOAD_IMAGE_GRAYSCALE);
//	Mat imagen = imread("luna.jpg",CV_LOAD_IMAGE_GRAYSCALE);

//	Aplicacion de distribucion de ruido
	Mat ruido = ruido_gaussiano(imagen,0,0.025);
//	Mat ruido = ruido_impulsivo(imagen,0,255);
	
//  Definir ROI
	namedWindow("Definir ROI",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Definir ROI",ruido); //muestra la imagen en la ventana
	puntos_roi pr;
	setMouseCallback("Definir ROI",clic,&pr);
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen	
	
	Rect area(pr.p1,pr.p2);
	Mat roi = ruido(area);
	
//	Analisis del ruido mediante el histograma
	Mat histograma = draw_hist(histogram(roi,256));
	
//	Presentacion de resultados
	vector<Mat> imagenes = {imagen,ruido};
	Mat mosaico = concatenar_v_gray(imagenes);
	
//	Ventanas
	namedWindow("Resultados",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Resultados",mosaico); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Histograma",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Histograma",histograma); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
