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
	
	Mat imagen_color = imread("lluviaEstrellas.jpg");
	info(imagen_color);
	
//	Conversion a escala de grises
	Mat imagen_gris;
	cvtColor(imagen_color,imagen_gris,CV_BGR2GRAY);
	imwrite("imagen_gris.png",imagen_gris);
	
//	Restauración y umbralizacion (mediante deteccion de bordes)
	Mat mediana;
	medianBlur(imagen_gris,mediana,3);
	imwrite("mediana.png",mediana);
	
	Mat bordes;
	Canny(mediana,bordes,100,200);
	imwrite("bordes.png",bordes);
	
//	Morfologia
	Mat ee1 = elemento_estructurante();
	print(ee1,cout);
	
	Mat erosion;
	erode(bordes,erosion,ee1,Point(-1,-1),3);
	imwrite("erosion.png",erosion);
	
	Mat ee2 = getStructuringElement(MORPH_RECT,{3,3},Point(-1,-1));
	print(ee2,cout);
	
	Mat dilatacion;
	dilate(erosion,dilatacion,ee2,Point(-1,-1),1);
	imwrite("dilatacion.png",dilatacion);
	
//	Extraccion de la estrella fugaz
	vector<Mat> canales;
	split(imagen_color,canales);
	
	canales[0] = multiplicacion(canales[0],dilatacion);
	canales[1] = multiplicacion(canales[1],dilatacion);
	canales[2] = multiplicacion(canales[2],dilatacion);
	
	Mat estrella;
	merge(canales,estrella);
	imwrite("estrella.png",estrella);
	
//	Presentacion de resultados
	vector<Mat> imagenes = {imagen_color,dilatacion,estrella};	
	Mat mosaico = concatenar_v_color(imagenes);
	
	imwrite("estrella_fugaz.png",mosaico);
	
//	Ventanas
	namedWindow("Resultados",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Resultados",mosaico); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
