#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"
#include "vector"

using namespace std;
using namespace pdi;
using namespace cv;

vector<int> no_llenas(vector<int> botellas,vector<int> promedios) {
	int numero = 0;
	for (int i=0;i<promedios.size();i++) {
		if (promedios[i] < 222)
			numero+=1;
	}
	
	vector<int> no_llenas(2*numero);
	
	for (int i=0;i<no_llenas.size();i+=2) {
		for (int j=0;j<promedios.size();j++) {
			if (promedios[j] < 222) {
				no_llenas[i]   = botellas[2*j];
				no_llenas[i+1] = botellas[2*j+1];
			}
		}	
	}
	return no_llenas;
}
