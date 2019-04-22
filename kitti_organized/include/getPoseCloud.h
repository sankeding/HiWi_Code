#ifndef GET_POSE_CLOUD
#define GET_POSE_CLOUD

#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>



#include <Eigen/Dense>

#include "../include/convertOxtsToPose.h"
using namespace std;


void getPoseCloud(pcl::PointCloud<pcl::PointXYZI>::Ptr &,  pcl::PointCloud<pcl::PointXYZI>::Ptr & ,const vector<vector<double> > & ,const int);


#endif
