#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

const string dataPath = "../data/out/";

void main()
{
	VideoCapture capture(1);
	QRCodeDetector detector;

	Mat frame, points, qrcode;
	string data;
	int num = 1;

	while (true) {
		// 화면 출력
		//capture.read(frame);
		capture >> frame;
		imshow("cam", frame);

		data = detector.detectAndDecode(frame, points, qrcode);
		if (data.length() > 0) {
			imshow("qrcode", qrcode);
			cout << data << endl;
		}

		//imwrite(dataPath + to_string(num) + ".jpg", frame);
		//num++;
		waitKey(1);
	}
}
