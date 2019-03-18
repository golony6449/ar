#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

void main()
{
	// 알파 채널 이용
	Mat background = imread("../data/windows.jpg");
	Mat img = imread("../data/ryan.png", IMREAD_UNCHANGED);	// 마지막 체널: 마스크 체널
	Mat roi = background(Rect(100, 100, img.cols, img.rows));

	// split example 1
	//Mat channel[4];
	//split(img, channel);

	// split example 2
	vector<Mat> channels;
	split(img, channels);

	Mat mask = channels[3];
	channels.pop_back();
	merge(channels, img);
	img.copyTo(roi, mask);
	imshow("result", background);
	




	//// 기존방식
	//Mat img = imread("../data/ryan.bmp");

	//Mat img2 = imread("../data/windows.jpg");
	//Mat roi = img2(Rect(100, 100, img.cols, img.rows));
	//Mat mask, gray;
	//cvtColor(img, gray, COLOR_BGR2GRAY);
	//Mat white(img.size(), CV_8UC1, Scalar(255));

	//// XOR 연산을 이용한 마스크 작성
	//bitwise_xor(gray, white, mask);
	////imshow("mask", mask);

	//// 임계값을 이용한 마스크 작성
	//threshold(gray, mask, 254, 255, THRESH_BINARY_INV);	// 입력, 출력, 임계값, 입력의 최대값, 타입

	//img.copyTo(roi, [3]);	// 얕은 복사, 마스크가 0인 부분은 복사하지 않음
	//imshow("windows", img2);

	waitKey();

}