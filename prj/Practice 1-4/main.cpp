#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

const string dataPath = "../data/out/";

void main()
{
	VideoCapture capture(1);
	VideoCapture capture2;
	QRCodeDetector detector;

	Mat frame, frame2, points, qrcode;
	string data;
	int num = 1;

	while (true) {
		// ȭ�� ���
		//capture.read(frame);
		capture >> frame;
		imshow("cam", frame);

		data = detector.detectAndDecode(frame, points, qrcode);

		if (data.length() > 0) {
			cout << data << endl;

			// ������ �ռ�
			if (!capture2.isOpened()) capture2.open(dataPath + data);	// ���ϸ�
			
			capture2 >> frame2;
			imshow("frame2", frame2);	// ���ɻ� putText, line �ڿ��� �����ϴ� ���� ����

			// QR �ڵ� ��ŷ
			putText(frame, data, Point((int)points.at<float>(0, 0), (int)points.at<float>(0, 1)), 
				FONT_HERSHEY_PLAIN, 20, Scalar(255, 0, 0));

			line(frame, Point((int)points.at<float>(1, 0), (int)points.at<float>(1, 1)), 
				Point((int)points.at<float>(2, 0), (int)points.at<float>(2, 1)),
				Scalar(0, 255, 255), 3);

			line(frame, Point((int)points.at<float>(2, 0), (int)points.at<float>(2, 1)),
				Point((int)points.at<float>(3, 0), (int)points.at<float>(3, 1)),
				Scalar(255, 0, 255), 3);

			line(frame, Point((int)points.at<float>(0, 0), (int)points.at<float>(0, 1)),
				Point((int)points.at<float>(1, 0), (int)points.at<float>(1, 1)),
				Scalar(255, 255, 0), 3);

			line(frame, Point((int)points.at<float>(3, 0), (int)points.at<float>(3, 1)),
				Point((int)points.at<float>(1, 0), (int)points.at<float>(1, 1)),
				Scalar(0, 0, 255), 3);
			
		//	for (int i = 0; i < 3; i++)
		//		line(frame, Point((int)points.at<float>(i, 0), (int)points.at<float>(i, 1)), 
		//			Point((int)points.at<float>(i + 1, 0), (int)points.at<float>(i + 1, 1)),
		//			Scalar(255, 255, 255));
		}

		//imwrite(dataPath + to_string(num) + ".jpg", frame);
		//num++;

		imshow("qrcode", qrcode);
		waitKey(1);
	}
}
