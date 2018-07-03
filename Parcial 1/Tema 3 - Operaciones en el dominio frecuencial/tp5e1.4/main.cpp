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
	
//	Carga de imagenes
	Mat imagen1 = imread("escaneo6.png");
	Mat imagen2 = imread("escaneo7.png");
	Mat imagen3 = imread("escaneo9.png");
	
//	medianBlur(imagen1,imagen1,3);
//	medianBlur(imagen2,imagen2,3);
//	medianBlur(imagen3,imagen3,3);
	
//	Conversion a escala de grises
	Mat imagen1_gris,imagen2_gris,imagen3_gris;
	cvtColor(imagen1,imagen1_gris,CV_BGR2GRAY);
	cvtColor(imagen2,imagen2_gris,CV_BGR2GRAY);
	cvtColor(imagen3,imagen3_gris,CV_BGR2GRAY);
	
//	int nt1 = threshold(imagen1_gris,imagen1_gris,0,255,THRESH_OTSU|THRESH_BINARY_INV);
//	int nt2 = threshold(imagen2_gris,imagen2_gris,0,255,THRESH_OTSU|THRESH_BINARY_INV);
//	int nt3 = threshold(imagen3_gris,imagen3_gris,0,255,THRESH_OTSU|THRESH_BINARY_INV);
	
//	Mat ee = getStructuringElement(MORPH_RECT,{3,3},Point(-1,-1));
//	Mat ee = elemento_estructurante();
//	dilate(imagen1_gris,imagen1_gris,ee,Point(-1,-1),10);
//	dilate(imagen2_gris,imagen2_gris,ee,Point(-1,-1),10);
//	dilate(imagen3_gris,imagen3_gris,ee,Point(-1,-1),10);
	
//	Conversion a tipo flotante
	Mat imagen1_f,imagen2_f,imagen3_f;
	imagen1_gris.convertTo(imagen1_f,CV_64F);
	imagen2_gris.convertTo(imagen2_f,CV_64F);
	imagen3_gris.convertTo(imagen3_f,CV_64F);
	
//	Espectros de frecuencia
	imagen1_f = spectrum(imagen1_f);
	imagen2_f = spectrum(imagen2_f);
	imagen3_f = spectrum(imagen3_f);
	
//	Conversion a entero de los espectros
	Mat imagen1_fu,imagen2_fu,imagen3_fu;
	normalize(imagen1_f,imagen1_fu,0,255,CV_MINMAX,CV_8UC(1));
	normalize(imagen2_f,imagen2_fu,0,255,CV_MINMAX,CV_8UC(1));
	normalize(imagen3_f,imagen3_fu,0,255,CV_MINMAX,CV_8UC(1));
	
//	Informacion de los espectros
	info(imagen1_f);
	info(imagen2_f);
	info(imagen3_f);
	
//	Barra de desplazamiento
//	int n_t = 0;
//	namedWindow("Umbral",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	createTrackbar("Nivel de transicion","Umbral",&n_t,255,on_trackbar,&imagen1_fu);
//	on_trackbar(n_t,&imagen1_fu);
//	waitKey();
	
//	Binarizacion de los espectros
	imagen1_fu = umbral(imagen1_fu,150);
	imagen2_fu = umbral(imagen2_fu,150);
	imagen3_fu = umbral(imagen3_fu,150);
	
//	Transformada de Hough aplicada a los espectros binarizados
	vector<Vec2f> lineas1,lineas2,lineas3;
	HoughLines(imagen1_fu,lineas1,1,CV_PI/180,1);
	HoughLines(imagen2_fu,lineas2,1,CV_PI/180,1);
	HoughLines(imagen3_fu,lineas3,1,CV_PI/180,1);
	
//	Lineas de Hough dibujadas sobre los espectros binarizados
	Mat imagen1_lineas = lineas_hough(imagen1_fu,lineas1);
	Mat imagen2_lineas = lineas_hough(imagen2_fu,lineas2);
	Mat imagen3_lineas = lineas_hough(imagen3_fu,lineas3);
	
//	Primeros elementos de los vectores de lineas
	for(int i=0;i<1/*lineas1.size()*/;i++) { 
		cout<<lineas1[i]<<"\n";
	}
	
	for(int i=0;i<1/*lineas1.size()*/;i++) { 
		cout<<lineas2[i]<<"\n";
	}
	
	for(int i=0;i<1/*lineas1.size()*/;i++) { 
		cout<<lineas3[i]<<"\n";
	}
	
//	Alineacion de las imagenes con la vertical
	Mat rotada1 = rotar(imagen1,lineas1);
	Mat rotada2 = rotar(imagen2,lineas2);
	Mat rotada3 = rotar(imagen3,lineas3);
	
//	Presentacion de resultados
	vector<Mat> imagenes = {imagen1,imagen2,imagen3};
	Mat mosaico_ima = concatenar_h_color(imagenes);
	
//	vector<Mat> imagenes_bin = {imagen1_gris,imagen2_gris,imagen3_gris};
//	Mat mosaico_imu = concatenar_h_gray(imagenes_bin);
	
	vector<Mat> espectros = {imagen1_f,imagen2_f,imagen3_f};
	Mat mosaico_esp = concatenar_h_gray(espectros);
	
	vector<Mat> umbrales = {imagen1_fu,imagen2_fu,imagen3_fu};
	Mat mosaico_umb = concatenar_h_gray(umbrales);
	
	vector<Mat> lineas = {imagen1_lineas,imagen2_lineas,imagen3_lineas};
	Mat mosaico_lin = concatenar_h_color(lineas);
	
	vector<Mat> rotadas = {rotada1,rotada2,rotada3};
	Mat mosaico_rot = concatenar_h_color(rotadas);
	
	vector<Mat> resultados = {mosaico_ima,mosaico_umb,mosaico_lin,mosaico_rot};
	Mat mosaico_res = concatenar_v_color(resultados);
	
//	imwrite("mosaico_ima.png",mosaico_ima);
//	imwrite("mosaico_esp.png",mosaico_esp);
//	imwrite("mosaico_umb.png",mosaico_umb);
//	imwrite("mosaico_lin.png",mosaico_lin);
//	imwrite("mosaico_rot.png",mosaico_rot);
//	imwrite("mosaico_res.png",mosaico_res);
	
//	Ventanas
	namedWindow("Imagenes originales",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagenes originales",mosaico_ima); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
//	namedWindow("Imagenes binarizadas",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
//	imshow("Imagenes binarizadas",mosaico_imu); //muestra la imagen en la ventana
//	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Espectros",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Espectros",mosaico_esp); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Umbrales",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Umbrales",mosaico_umb); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen

	namedWindow("Lineas",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Lineas",mosaico_lin); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Rotadas",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Rotadas",mosaico_rot); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
} 
