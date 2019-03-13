#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;

void main()
{
	Mat img = imread("../data/ryan.bmp");
	Mat img2 = imread("../data/windows.jpg");
	Mat roi = img2(Rect(100, 100, img.cols, img.rows));
	Mat mask, gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	Mat white(img.size(), CV_8UC1, Scalar(255));

	//imshow("roi", roi);
	//img.copyTo(roi);	// ¾èÀº º¹»ç
	//imshow("ryan", img);
	//imshow("windows", img2);

	//imshow("ryan_gray", gray);	imshow("white", white);

	bitwise_xor(gray, white, mask);
	//imshow("mask", mask);

	img.copyTo(roi, mask);
	imshow("windows", img2);

	waitKey();

}