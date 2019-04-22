#include <iostream>	//用

#include<algorithm>
#include<Eigen/Dense>

#include <pcl/io/pcd_io.h>
#include <pcl/point_cloud.h>
#include <pcl/console/parse.h>    //用
#include <pcl/common/transforms.h>
#include <pcl/visualization/pcl_visualizer.h>

#include <pcl/filters/statistical_outlier_removal.h>

//#include <vector>
#include <cmath>
#include <Eigen/Dense>
//#include <string>	//用
//#include <dirent.h>  //用(struct dirent)

#include "../include/showHelp.h"
#include "../include/findFiles.h"
#include "../include/loadOxtsData.h"
#include "../include/doVisualization.h"

using namespace std;
using namespace Eigen;


//main function
int main(int argc, char** argv)
{	
	//show help
	if(pcl::console::find_switch(argc, argv, "-h")){
		showHelp(argv[0]);    
		return 0;
	}  

	//give the path of the files
	string KittiDataPath = "../kitti_data/2011_09_26_drive_0005_sync/";
	string PCDfilePath = KittiDataPath + "velodyne_points/data_pcd/";
 	string OxtsPath = KittiDataPath + "oxts/data/";
	

	vector<string> PCDfiles;
	vector<vector<double> > oxts;
	//search PCD files, write filenames in vector<string> files
	findFiles( PCDfilePath.c_str(),PCDfiles);
	//OXTS
	loadOxtsData(OxtsPath,oxts);

	
	doVisualization(PCDfilePath, PCDfiles, oxts);
	
  return 0;
}
