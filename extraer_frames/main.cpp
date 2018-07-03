#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int argc, char **argv){
	
	VideoCapture video("snk.mp4");
	int count = 500;
	int total_frames = video.get(CV_CAP_PROP_FRAME_COUNT);
	float step = float(total_frames)/count;
	
	for(float K=step/2, i=0; K<total_frames; K+=step, ++i) {
		video.set(CV_CAP_PROP_POS_FRAMES,K);
		Mat frame;
		video >> frame;
		
		stringstream s;
		s << "fotograma" << setfill('0') << setw(3) << i << ".jpg";
		cout << "writing " << s.str() << '\n';
		imwrite(s.str(),frame);
	}
	
	return 0;
}
