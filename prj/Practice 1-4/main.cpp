#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

const string dataPath = "../data/out/";

void main()
{
	VideoCapture capture(1);
	Mat frame;
	int num = 1;

	while (true) {
		//capture.read(frame);
		capture >> frame;

		imshow("cam", frame);
		imwrite(dataPath + to_string(num) + ".jpg", frame);
		waitKey(1);
		num++;
	}
}
