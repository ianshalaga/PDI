#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

Mat imagen_u;

void on_trackbar(int n_t,void* imagen_dato) {
	
	Mat &imagen_gris = *static_cast<Mat*>(imagen_dato); // Conversion obligatoria
	
	imagen_u = umbral(imagen_gris,n_t);
	imshow("Umbral",imagen_u);
}

int main(int argc, char** argv) {
	
	Mat imagen_color = imread("Globulos Rojos.jpg");
	info(imagen_color);
	
//	Restauracion
	Mat mediana;
	medianBlur(imagen_color,mediana,3);
	
//	Conversion a escala de grises
	Mat imagen_gris;
	cvtColor(mediana,imagen_gris,CV_BGR2GRAY);
	
//	Barra de desplazamiento
	int n_t = 0;
	namedWindow("Umbral",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	createTrackbar("Nivel de transicion","Umbral",&n_t,255,on_trackbar,&imagen_gris);
	on_trackbar(n_t,&imagen_gris);
	waitKey();
	
//	Umbralizacion
//	double n_t = threshold(imagen_gris,imagen_u,0,255,THRESH_OTSU|THRESH_BINARY_INV);
//	cout<<n_t<<"\n";
	
//	Morfologia
	Mat bordes = objetos_borde(imagen_u);
//	bordes = rellenar(bordes);
	
//	Extraccion de globulos de borde
	bordes = umbral_negativo(bordes,127);
	
	vector<Mat> canales;
	split(mediana,canales);
	
	canales[0] = multiplicacion(canales[0],bordes);
	canales[1] = multiplicacion(canales[1],bordes);
	canales[2] = multiplicacion(canales[2],bordes);
	
	Mat globulos;
	merge(canales,globulos);
	
//	Presentacion de resultados
	vector<Mat> imagenes = {imagen_color,bordes,globulos};	
	Mat mosaico = concatenar_v_color(imagenes);

	imwrite("globulos.png",mosaico);
	
//	Ventanas
	namedWindow("Resultados",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Resultados",mosaico); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
