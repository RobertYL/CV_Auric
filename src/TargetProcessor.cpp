#include "Target.hpp"
#include "TargetProcessor.hpp"
#include <math.h>

TargetProcessor::TargetProcessor(Target* target){
    focalLength = 415.74; //varies by camera
    horizCenter = 210.2315; //aslo varies by camera (center horizontal point on video)
    vertCenter = 207.87; //center vertical point on video

} //constructor

void TargetProcessor::setTarget(int type){
	target = type;
}

void TargetProcessor::loadTarget(Target* target){
    objectWidth = target->getObjWidth(target);
	imageTarWidth = target->getWidth();
    //double imageHeight = target->getHeight();
    imageTarCenter = target->getCenter();
}

double TargetProcessor::calculateDistance(){
    return objectWidth*focalLength/imageTarWidth; //returns the distance (m)
}

double TargetProcessor::calculateAzimuth(){
    double offset = imageTarCenter.x - horizCenter;
    double distance = calculateDistance();
    return (atan(offset/focalLength))*(180/M_PI); //in degrees
}

double TargetProcessor::calculateAltitude(){
    int cameraAngle = 0; //angle the camera is pointing up from the horizon; assumes camera is level
    double offset =  vertCenter - imageTarCenter.y;
    double distance = calculateDistance();
    return (atan(offset/focalLength))*(180/M_PI) + cameraAngle; //in degrees
}
