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
	
	Mat imagen_color = imread("Melanoma.jpg");
	info(imagen_color);

//	Restauracion
	Mat mediana;
	medianBlur(imagen_color,mediana,3);

	Mat imagen_gris;
	cvtColor(mediana,imagen_gris,CV_BGR2GRAY);
	
//	Barra de desplazamiento
//	int n_t = 0;
//	namedWindow("Umbral",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	createTrackbar("Nivel de transicion","Umbral",&n_t,255,on_trackbar,&imagen_azul);
//	on_trackbar(n_t,&imagen_azul);
//	waitKey();
	
//	Umbralizacion
	Mat imagen_u;
	double n_t = threshold(imagen_gris,imagen_u,0,255,THRESH_OTSU|THRESH_BINARY);
	cout<<n_t<<"\n";

//	convexHull
//	vector<vector<Point>> contornos;
//	vector<Vec4i> jerarquia;
//	findContours(imagen_u,contornos,jerarquia,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE,Point(0,0));
//	
//	RNG rng(12345);
//	
//	vector<vector<Point>>hull(contornos.size());
//	for(int i=0;i<contornos.size();i++) {
//		convexHull(Mat(contornos[i]), hull[i], false );
//	}
//	
//	Mat drawing = Mat::zeros(imagen_u.size(),CV_8UC3);
//	for(int i=0;i<contornos.size();i++) {
//		Scalar color = Scalar(rng.uniform(0,255),rng.uniform(0,255),rng.uniform(0,255));
////		drawContours(drawing,contornos,i,color,2,8,jerarquia,0,Point());
////		drawContours(drawing,contornos,i,color,1,8,vector<Vec4i>(),0,Point());
//		drawContours(drawing,hull,i,color,1,8,vector<Vec4i>(),0,Point());
//	}
//	
//	// Show in a window
//	namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
//	imshow( "Contours", drawing );
	
//	Morfologia
	Mat ee = getStructuringElement(MORPH_RECT,{3,3},Point(-1,-1));

	Mat erosion;
	erode(imagen_u,erosion,ee,Point(-1,-1),6);

	Mat dilatacion;
	dilate(erosion,dilatacion,ee,Point(-1,-1),6);
	
//	Extraccion del melanoma
	dilatacion = umbral_negativo(dilatacion,127);
	
	vector<Mat> canales;
	split(imagen_color,canales);
	
	canales[0] = multiplicacion(canales[0],dilatacion);
	canales[1] = multiplicacion(canales[1],dilatacion);
	canales[2] = multiplicacion(canales[2],dilatacion);
	
	Mat melanoma;
	merge(canales,melanoma);
	
//	Presentacion de resultados
	vector<Mat> imagenes = {imagen_color,dilatacion,melanoma};	
	Mat mosaico = concatenar_v_color(imagenes);
	
//	imwrite("globulos.png",mosaico);
	
//	Ventanas
	namedWindow("Resultados",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Resultados",mosaico); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
