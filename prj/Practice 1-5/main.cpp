#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;

void main()
{
	Mat qr = imread("../data/frame.png");
	QRCodeDetector detector;
	
	Mat point, processed;

	detector.detectAndDecode(qr, point, processed);

	imshow("qr_origin", qr);
	std::cout << point;

	imshow("processed", processed);

	waitKey();
}
