#include "Target.hpp"
#include <opencv2/opencv.hpp>
#include <math.h>
#include <iostream>

Target::Target(std::vector<cv::Point> contour, int *TargetData){
    edge = contour;
    //crap
    std::cout << "EDGE" << edge.size();

    //crow = 1415;
	cross.objWidth = TargetData[0];
	cross.corners = TargetData[1];
	cross.minSize = TargetData[2];
	square.objWidth = TargetData[3];
	square.corners = TargetData[4];
	square.minSize = TargetData[5];
}

double Target::getHeight(){
    return fabs(getTopPoint().y - getBottomPoint().y);
}

double Target::getWidth(){
    return fabs(getRightPoint().x - getLeftPoint().x);
}

int Target::getObjWidth(int object){
	if(object)
		return cross.objWidth;
	else
		return square.objWidth;
}

int Target::getObjCorners(int object){
	if(object)
		return cross.corners;
	else
		return square.corners;
}

int Target::getObjMinSize(int object){
	if(object)
		return cross.minSize;
	else
		return square.minSize;
}

/*
bool Target::isInitialized(){
    std::cout << "EDGE" << edge;
    if (edge.size() == 0) {
        return false;
    }
    return true;
}
*/

void Target::printPoints() //debugging
{
    std::cout << "TopPoint: " << getTopPoint() << std::endl;
    std::cout << "BottomPoint: " << getBottomPoint() << std::endl;
    std::cout << "LeftPoint: " << getLeftPoint() << std::endl;
    std::cout << "RightPoint: " << getRightPoint() << std::endl;
}

cv::Point Target::getCenter()//finds center point of target
{
    cv::Point center(0, 0);

    for(int x = 0; x < edge.size(); x++){
        center += edge.at(x);
    }

    if(x = 0)
        x = 1;

    center.x /= x;
    center.y /= x;

    return center;
}

cv::Point Target::getTopPoint(){
    cv::Point max(0,0);
    for(unsigned int i = 0; i < edge.size(); i++)
        if(edge[i].y > max.y)
            max = edge[i];
    return max;
}

cv::Point Target::getBottomPoint(){
    cv::Point min(10000,10000);
    for(int i = 0; i < edge.size(); i++)
        if(edge[i].y < min.y)
            min = edge[i];
    return min;
}

cv::Point Target::getLeftPoint(){
    cv::Point min(0,0);
    for(unsigned int i = 0; i < edge.size(); i++)
        if(edge[i].x > min.x)
            min = edge[i];
    return min;
}

cv:: Point Target::getRightPoint(){
    cv::Point max(10000,10000);
    for(unsigned int i = 0; i < edge.size(); i++)
        if(edge[i].x < max.x)
            max = edge[i];
    return max;
}
