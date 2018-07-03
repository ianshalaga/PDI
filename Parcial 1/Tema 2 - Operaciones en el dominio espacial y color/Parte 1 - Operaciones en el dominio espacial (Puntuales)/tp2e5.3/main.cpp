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
	
	Mat completo = imread("blister_completo.jpg",CV_LOAD_IMAGE_GRAYSCALE); // Carga una imagen
	
	Mat incompleto = imread("blister_incompleto.jpg",CV_LOAD_IMAGE_GRAYSCALE); // Carga una imagen
	resize(incompleto,incompleto,completo.size(),0,0,INTER_LINEAR);
	
	completo = umbral(completo,90);
	incompleto = umbral(incompleto,90);
	
	Mat faltantes = or_exclusivo(completo,incompleto);
	imwrite("faltantes.jpg",faltantes);
	Mat kernel = filtro_pb(3,3);
	faltantes = convolve(faltantes,kernel);
	faltantes = umbral(faltantes,90); // Imagen binaria con pastillas faltantes

	vector<Mat> dividida = partir_mitad(faltantes,true);
	
	Mat prom_superior = umbral(promedio_intensidad_v(dividida[0]),1);
	Mat prom_inferior = umbral(promedio_intensidad_v(dividida[1]),1);
	
	vector<int> superior = blancos(prom_superior);
	vector<int> inferior = blancos(prom_inferior);
	
	cout<<"Arriba: "<<"\n";
	for(int i=0;i<superior.size();i++) { 
		cout<<superior[i]<<"\n";
	}
	
	cout<<"Abajo: "<<"\n";
	for(int i=0;i<inferior.size();i++) { 
		cout<<inferior[i]<<"\n";
	}
	
//	----------------------------------------------------------
//	Ventanas de muestra
	
	namedWindow("Blister completo",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Blister completo",completo); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	namedWindow("Blister incompleto",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("Blister incompleto",incompleto); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
		
	namedWindow("com bin",CV_WINDOW_KEEPRATIO); //reserva ventana para imagen
	imshow("com bin",faltantes); //muestra la imagen en la ventana
	waitKey(); //espera a una tecla para cerrar la ventana de la imagen
	
	return 0;
}
