#include "Target.cpp"
#include <iostream>

using namespace cv;
using namespace std;

TargetProcessor::TargetProcessor() {
  maxX = target->getMaxX();
  minX = target->getMinX();
  maxY = target->getMaxY();
  minY = target->getMinY();
  width = target->getWidth();
  height = target->getHeight();
  imageWidth = target->getImageWidth();
}

int TargetProcessor::getCenterX() {
  centerX = (maxX + minX)/2;
  return centerX;
}

int TargetProcessor::getCenterY() {
  centerY = (maxY+ minY)/2;
  return centerY;
}

double TargetProcessor::getDistance() {
  double foc = 15.118;
  double actualWidth = 26.94;
  double distance = (foc * actualWidth)/width;
  return distance;
}

double TargetProcessor::getAzimuthX() {
  centerX = getCenterX();
  double angleX = atan((imageWidth - centerX)/calcDistance()) * 180 / 3.1415;
  return angleX;
}

double TargetProcessor::getAzimuthY() {
    centerY = getCenterY();
  double angleY = atan((imageWidth - centerY)/calcDistance()) * 180 / 3.1415;
  return angleY;
  }

int main() {
  cout << "Distance: " + distance;
  cout << "Azimuth(X): " + angleX;
  cout << "Azimuth(Y): " + angleY;
}

