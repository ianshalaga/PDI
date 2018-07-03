#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
//#include "djr_functions.h"

using namespace std;
using namespace pdi;
using namespace cv;

int maximo(vector<int> numeros) {
	
	int maxi = numeros[0];
	int indice = 0;
	
	for(int i=0;i<numeros.size();i++) { 
		if (numeros[i] > maxi) {
			maxi = numeros[i];
			indice = i;
		}
	}
	
	return indice;
}
