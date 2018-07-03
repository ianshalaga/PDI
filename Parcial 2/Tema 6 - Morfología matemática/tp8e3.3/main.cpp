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
	
	Mat imagen_color = imread("estrellas.jpg");
	info(imagen_color);
	
//	Conversion a escala de grises
	Mat imagen_gris;
	cvtColor(imagen_color,imagen_gris,CV_BGR2GRAY);
	
//	Restauración y umbralizacion	
	Mat mediana;
	medianBlur(imagen_gris,mediana,3);
	
	Mat imagen_u = umbral(mediana,200);
	info(imagen_u);

//	Morfologia
	Mat ee = getStructuringElement(MORPH_CROSS,{3,3},Point(-1,-1));
	print(ee,cout);
	
	Mat dilatacion;
	dilate(imagen_u,dilatacion,ee,Point(-1,-1),3);
	
//	Extraccion de extrellas
	vector<Mat> canales;
	split(imagen_color,canales);
	
	canales[0] = multiplicacion(canales[0],dilatacion);
	canales[1] = multiplicacion(canales[1],dilatacion);
	canales[2] = multiplicacion(canales[2],dilatacion);
	
	Mat estrellas;
	merge(canales,estrellas);

//	Presentacion de resultados
	vector<Mat> imagenes = {imagen_color,dilatacion,estrellas};	
	Mat mosaico = concatenar_v_color(imagenes);
	
	imwrite("pleyades.png",mosaico);
	
//	Ventanas
	namedWindow("Resultados",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Resultados",mosaico); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
