#ifndef TARGET_CLASS_H
#define TARGET_CLASS_H
#include <opencv2/opencv.hpp>
using namespace cv;

class Target
{
public:
    Target(std::vector<Point> contour, int *TargetData);
    double getHeight();
    double getWidth();
	int getObjWidth(int object);
	int getObjCorners(int object);
	int getObjMinSize(int object);
    void printPoints();
    Point getCenter();
    //bool isInitialized();
    //int crow;
private:
	struct TargetData{
		int objWidth;
		int corners;
		int minSize;
	} cross, square;
    Point getTopPoint();
    Point getBottomPoint();
    Point getLeftPoint();
    Point getRightPoint();
    std::vector<Point> edge;
};

#endif
