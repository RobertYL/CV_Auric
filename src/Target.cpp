#include "Target.hpp"
#include <opencv2/opencv.hpp>
#include <math.h>
#include <iostream>

using namespace cv;
using namespace std;


void thresh_callback(int, void* )
{
  Mat canny_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  /// Detect edges using canny
  Canny( src_gray, canny_output, thresh, thresh*2, 3 );
  /// Find contours
  findContours( canny_output, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

  /// Draw contours
  Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
  for( int i = 0; i< contours.size(); i++ )
     {
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
     }

  /// Show in a window
  namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
  imshow( "Contours", drawing );
}

double getMinX()
{
	Point min(10000,10000);
	for (unsigned int a=0; a<contours.size(); a++)
	{	
		if(contours[a].x < min.x)
		{
			min = edge[a];
		}
	}
	return max;
}

double getMaxX()
{
   Point max(0,0);
   for(unsigned int a = 0; a < contours.size(); a++)
   {
       if(contours[a].x > max.x)
       {
           max = edge[a];
       }
   }
   return max;
}

double getMinY()
{
  Point min(10000,10000);
  for(unsigned int i = 0; i < contours.size(); i++)
  {
      if(contours[i] < min)
      {
          min = contours[i];
      }
  }
  return min;
}

double getMaxY()
  Point max(0,0);
  for(unsigned int i = 0; i < edge.size(); i++)
  {
      if(edge[i] > max)
      {
          max = edge[i];
      }
  }
  return max
}

double getHeight()
{
    double max = getMaxY();
    double min = getMinY();
    double height = max - min;
    return height;
}

double getWidth()
{
    
      double max = getMaxX();
      double min = getMaxY();
      double width = max - min;
      return width;
}
