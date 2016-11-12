#include "GUIManager.hpp"
#include "Target.cpp"
#include <opencv2/opencv>
#include<iostream>

GUI::GUI()
{
    mat = target->getMat();
    Distance = target->distance();
    azimuthX = target->AzimuthX();
    azimuthY = target->AzimuthY();
}

void GUI::show()
{
	imshow("Distance: " + Distance + ", Azimuth(X): " + azimuthX + ", Azimuth(Y): " + azimuthY, mat);
	waitKey(0);
}
