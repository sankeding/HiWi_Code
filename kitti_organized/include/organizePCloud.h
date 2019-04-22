#ifndef ORGANIZE_POINT_CLOUD
#define ORGANIZE_POINT_CLOUD

#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>

#include "../include/convertOxtsToPose.h"
#include "../include/makeDir.h"


const int laserRange = 20;
const double laserInterval = 10.5/31;
const double laserUppest = 2.0;
const double uplimitX = 6.0;
const double downlimitX = -6.0;
const double limitY = 0.0;


void organizePCloud(pcl::PointCloud<pcl::PointXYZI>::Ptr & ,const vector<vector<double> > &, const int );




#endif
