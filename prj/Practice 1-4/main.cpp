#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

const string dataPath = "../data/";

void main()
{
	VideoCapture capture(1);
	VideoCapture capture2;
	QRCodeDetector detector;

	Mat frame, frame2, points, qrcode;
	string data;
	int num = 1;
	int thickness = 3;

	while (true) {
		// ȭ�� ���
		//capture.read(frame);
		capture >> frame;

		data = detector.detectAndDecode(frame, points, qrcode);

		if (data.length() > 0) {
			cout << data << endl;

			// ������ �ռ�
			if (!capture2.isOpened()) capture2.open(dataPath + data + ".mp4");	// ���ϸ�
			
			capture2 >> frame2;
			imshow("frame2", frame2);	// ���ɻ� putText, line �ڿ��� �����ϴ� ���� ����

			// QR �ڵ� ��ŷ
			putText(frame, data, Point((int)points.at<float>(0, 0), (int)points.at<float>(0, 1)), 
				FONT_HERSHEY_PLAIN, 3, Scalar(255, 0, 0), thickness);

			line(frame, Point((int)points.at<float>(1, 0), (int)points.at<float>(1, 1)), 
				Point((int)points.at<float>(2, 0), (int)points.at<float>(2, 1)),
				Scalar(0, 255, 255), thickness);

			line(frame, Point((int)points.at<float>(2, 0), (int)points.at<float>(2, 1)),
				Point((int)points.at<float>(3, 0), (int)points.at<float>(3, 1)),
				Scalar(255, 0, 255), thickness);

			line(frame, Point((int)points.at<float>(0, 0), (int)points.at<float>(0, 1)),
				Point((int)points.at<float>(1, 0), (int)points.at<float>(1, 1)),
				Scalar(255, 255, 0), thickness);

			line(frame, Point((int)points.at<float>(3, 0), (int)points.at<float>(3, 1)),
				Point((int)points.at<float>(0, 0), (int)points.at<float>(0, 1)),
				Scalar(0, 0, 255), thickness);
			
		//	for (int i = 0; i < 3; i++)
		//		line(frame, Point((int)points.at<float>(i, 0), (int)points.at<float>(i, 1)), 
		//			Point((int)points.at<float>(i + 1, 0), (int)points.at<float>(i + 1, 1)),
		//			Scalar(255, 255, 255));

			//// �ν� �׽�Ʈ
			//imshow("qrcode", qrcode);
		}

		//// �̹��� ����
		//imwrite(dataPath + to_string(num) + ".jpg", frame);
		//num++;

		imshow("cam", frame);
		waitKey(1);
	}
}
