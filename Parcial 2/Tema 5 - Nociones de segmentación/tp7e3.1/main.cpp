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

struct semilla {
	Point p1;
};

// Obtener informacion del mouse
void clic(int evento,int x,int y,int flag,void* estructura) {
	
	semilla &datos = *static_cast<semilla*>(estructura); // Conversion obligatoria
	
	if (evento == CV_EVENT_LBUTTONDOWN) {
		datos.p1 = Point(x,y);
		cout<<"x: "<<x<<" "<<"y: "<<y<<"\n";
	}
	
//	cout<<x<<" "<<y<<"\n";	
}

/***************************************************************/

int main(int argc, char** argv) {
	
	Mat imagen = imread("bone.tif",CV_LOAD_IMAGE_GRAYSCALE);
	
	// Seleccionar semilla
	namedWindow("Seleccionar semilla",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Seleccionar semilla",imagen); //muestra la imagen en la ventana
	semilla seed;
	setMouseCallback("Seleccionar semilla",clic,&seed);
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen	
	
	/*La mascara debe ser dos unidades mayor a la imagen original 
	tanto en filas como en columnas*/
	Mat mascara(imagen.rows+2,imagen.cols+2,CV_8UC(1),Scalar(0));
	Rect convex_hull; // Envoltorio convexo del area segmentada
	floodFill(imagen,mascara,seed.p1,255,&convex_hull,8,8,8);
	mascara = umbral(mascara,0);
	
	Mat roi = imagen(convex_hull);
	
	vector<Mat> imagenes = {imagen,mascara,roi};
	Mat conc = concatenar_h(imagenes);
	imwrite("conc.jpg",conc);
	
	namedWindow("Imagen original",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagen original",imagen); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Convex Hull",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Convex Hull",roi); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Mascara",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Mascara",mascara); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Concatenacion",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Concatenacion",conc); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
