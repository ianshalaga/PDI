#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

//Mat imagen_u;
//
//void on_trackbar(int n_t,void* imagen_dato) {
//	
//	Mat &imagen_gris = *static_cast<Mat*>(imagen_dato); // Conversion obligatoria
//	
//	imagen_u = umbral(imagen_gris,n_t);
//	imshow("Umbral",imagen_u);
//}

int main(int argc, char** argv) {
	
	Mat imagen_color = imread("Rio.jpeg");
	info(imagen_color);
	
//	Restauracion
	Mat mediana;
	medianBlur(imagen_color,mediana,3);
	
//	Extraccion del canal azul
	Mat imagen_azul;
	vector<Mat> vector_color;
	split(imagen_color,vector_color);
	imagen_azul = vector_color[0];
	
//	Barra de desplazamiento
//	int n_t = 0;
//	namedWindow("Umbral",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	createTrackbar("Nivel de transicion","Umbral",&n_t,255,on_trackbar,&imagen_azul);
//	on_trackbar(n_t,&imagen_azul);
//	waitKey();
	
//	Umbralizacion
	Mat imagen_u;
	double n_t = threshold(imagen_azul,imagen_u,0,255,THRESH_OTSU|THRESH_BINARY);
	cout<<n_t<<"\n";
	
//	Morfologia
	Mat ee = getStructuringElement(MORPH_RECT,{3,3},Point(-1,-1));
//	Mat ee = elemento_estructurante();
	
	Mat dilatacion;
	dilate(imagen_u,dilatacion,ee,Point(-1,-1),1);
	
	Mat erosion;
	erode(dilatacion,erosion,ee,Point(-1,-1),1);
	
//	Mat bordes = objetos_borde(imagen_u);
//	//	bordes = rellenar(bordes);
//	
//	//	Extraccion de globulos de borde
//	bordes = umbral_negativo(bordes,127);
//	
//	vector<Mat> canales;
//	split(mediana,canales);
//	
//	canales[0] = multiplicacion(canales[0],bordes);
//	canales[1] = multiplicacion(canales[1],bordes);
//	canales[2] = multiplicacion(canales[2],bordes);
//	
//	Mat globulos;
//	merge(canales,globulos);
	
//	Presentacion de resultados
	vector<Mat> imagenes = {mediana,imagen_u,erosion};	
	Mat mosaico = concatenar_v_color(imagenes);
	
//	imwrite("globulos.png",mosaico);
	
//	Ventanas
	namedWindow("Resultados",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Resultados",mosaico); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
