#ifndef DO_VISUALIZATION
#define DO_VISUALIZATION

#include <iostream>
#include <string>
#include <unistd.h>

#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>

using namespace std;
using namespace pcl;


void doVisualization(const string &, const vector<string> &);

#endif
