#include "TargetDetector.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Process(Mat image)
{
	Mat img = image.clone();
}

Threshold(Mat image)
{
	Mat image;
	cvtColor(input, image, BGR2HSV);
	vector<Mat> channels;
	split(hsv, channels);
	Mat hue1 = channels.at(0);
	Mat threshLower, threshUpper;
	Mat result;
	threshold(hue1, threshLower, 0, 255, CV_THRESH_BINARY);
        threshold(hue1, threshUpper, 50, 255, CV_THRESH_BINARY_INV);

        result = threshLower & threshUpper;
	
}
