#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "iostream"
#include "pdi_functions.h"
#include "opencv2/video/tracking.hpp"

using namespace std;
using namespace pdi;
using namespace cv;

Mat draw_hist(const Mat &histo) {
	
	Mat data = histo.clone();
	normalize(data,data,0,1,CV_MINMAX);
	
	int rows = data.rows;
	
	Mat graph = Mat::zeros(rows,rows,CV_8U);
	
	for (size_t k=0;k<data.rows-1;k++){
		float value = data.at<float>(k);
		Point p1(k,rows);
		Point p2(k,rows-value*rows);
		line(graph,p1,p2,cv::Scalar::all(255));
	}
	
	return graph;
}
