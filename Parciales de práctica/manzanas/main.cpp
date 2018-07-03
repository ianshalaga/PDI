#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "vector"
#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int main(int argc,char **argv) {
	
//	Carga de imagenes
//	Mat imagen = imread("EXAMEN09.jpg");
	Mat imagen = imread("EXAMEN10.jpg");

//	Restauracion
	Mat imagen_rest;
	medianBlur(imagen,imagen_rest,3);
	
//	Conversion a HSV
	Mat imagen_hsv;
	cvtColor(imagen_rest,imagen_hsv,CV_BGR2HSV);
	
	vector<Mat> vector_hsv;
	split(imagen_hsv,vector_hsv);
	
//	Mascara de manzanas rojas
	Mat hsv0_u = umbral(vector_hsv[0],235*180./255); // El hue va entre 0 y 180
	Mat hsv1_u = umbral(vector_hsv[1],200);
	
	vector<Mat> mascaras = {hsv0_u,hsv1_u};
	Mat rojas = and_mascaras(mascaras);
	
	Mat ee = getStructuringElement(MORPH_RECT,{3,3},Point(-1,-1));
	dilate(rojas,rojas,ee,Point(-1,-1),1);
	
//	Mascara de manzanas verdes
	Mat verdes = or_exclusivo(hsv1_u,rojas);
	
	erode(verdes,verdes,ee,Point(-1,-1),2);
	dilate(verdes,verdes,ee,Point(-1,-1),3);
	
//	Mascara con todas las manzanas
	Mat todas = or_mascaras({rojas,verdes});
	
//	Cantidad de manzanas rojas
	Mat cc_rojas,est_rojas,cen_rojas;
	connectedComponentsWithStats(rojas,cc_rojas,est_rojas,cen_rojas);
	
	double min,max;
	minMaxLoc(cc_rojas,&min,&max);
	int rojas_cant = max;
	cout<<"Rojas: "<<rojas_cant<<"\n";
	
//	Cantidad de manzanas verdes
	Mat cc_verdes,est_verdes,cen_verdes;
	connectedComponentsWithStats(verdes,cc_verdes,est_verdes,cen_verdes);
	
	minMaxLoc(cc_verdes,&min,&max);
	int verdes_cant = max;
	cout<<"Verdes: "<<verdes_cant<<"\n";
	
//	Mascara de manzanas chicas
	Mat chicas = manzanas_chicas(todas);
	
//	Extraccion de manzanas rojas
	Mat hue_rojas = multiplicacion(vector_hsv[0],rojas);
	Mat sat_rojas = multiplicacion(vector_hsv[1],rojas);
	Mat val_rojas = multiplicacion(vector_hsv[2],rojas);
	vector<Mat> vector_rojas = {hue_rojas,sat_rojas,val_rojas};
	Mat manzanas_rojas;
	merge(vector_rojas,manzanas_rojas);
	cvtColor(manzanas_rojas,manzanas_rojas,CV_HSV2BGR);
	
//	Extraccion de manzanas verdes
	Mat hue_verdes = multiplicacion(vector_hsv[0],verdes);
	Mat sat_verdes = multiplicacion(vector_hsv[1],verdes);
	Mat val_verdes = multiplicacion(vector_hsv[2],verdes);
	vector<Mat> vector_verdes = {hue_verdes,sat_verdes,val_verdes};
	Mat manzanas_verdes;
	merge(vector_verdes,manzanas_verdes);
	cvtColor(manzanas_verdes,manzanas_verdes,CV_HSV2BGR);
	
//	Extraccion de todas las manzanas
	Mat hue_todas = multiplicacion(vector_hsv[0],todas);
	Mat sat_todas = multiplicacion(vector_hsv[1],todas);
	Mat val_todas = multiplicacion(vector_hsv[2],todas);
	vector<Mat> vector_todas = {hue_todas,sat_todas,val_todas};
	Mat manzanas_todas;
	merge(vector_todas,manzanas_todas);
	cvtColor(manzanas_todas,manzanas_todas,CV_HSV2BGR);
	
//	Extraccion de manzanas chicas	
	imagen_rest.setTo(Scalar(255,0,0),chicas);
	
//	Presentacion de resultados
	vector<Mat> imagenes = {imagen,manzanas_rojas,manzanas_verdes,manzanas_todas,imagen_rest};
	Mat mosaico_ori = concatenar_v_color(imagenes);
	
	imwrite("manzanas.png",mosaico_ori);
	
//	Ventanas
	namedWindow("Imagenes originales",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Imagenes originales",mosaico_ori); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
