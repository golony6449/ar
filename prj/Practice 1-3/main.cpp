#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

void main()
{
	// ���� ä�� �̿�
	Mat background = imread("../data/windows.jpg");
	Mat img = imread("../data/ryan.png", IMREAD_UNCHANGED);	// ������ ü��: ����ũ ü��
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
	




	//// �������
	//Mat img = imread("../data/ryan.bmp");

	//Mat img2 = imread("../data/windows.jpg");
	//Mat roi = img2(Rect(100, 100, img.cols, img.rows));
	//Mat mask, gray;
	//cvtColor(img, gray, COLOR_BGR2GRAY);
	//Mat white(img.size(), CV_8UC1, Scalar(255));

	//// XOR ������ �̿��� ����ũ �ۼ�
	//bitwise_xor(gray, white, mask);
	////imshow("mask", mask);

	//// �Ӱ谪�� �̿��� ����ũ �ۼ�
	//threshold(gray, mask, 254, 255, THRESH_BINARY_INV);	// �Է�, ���, �Ӱ谪, �Է��� �ִ밪, Ÿ��

	//img.copyTo(roi, [3]);	// ���� ����, ����ũ�� 0�� �κ��� �������� ����
	//imshow("windows", img2);

	waitKey();

}