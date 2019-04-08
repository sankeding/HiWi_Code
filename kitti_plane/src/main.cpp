#include <iostream>	//用

#include<algorithm>
#include<Eigen/Dense>

#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/point_cloud.h>
#include <pcl/console/parse.h>    //用
#include <pcl/common/transforms.h>
#include <pcl/visualization/pcl_visualizer.h>

#include <pcl/filters/statistical_outlier_removal.h>

//#include <vector>
#include <cmath>
//#include <string>	//用
//#include <dirent.h>  //用(struct dirent)

#include"../include/showHelp.h"
#include"../include/findFiles.h"

using namespace std;


//main function
int main(int argc, char** argv)
{	
	//show help
	if(pcl::console::find_switch(argc, argv, "-h")){
		showHelp(argv[0]);    
		return 0;
	}  

	//give the path of the files
	string filePath = "../data";
	vector<string> files;
	//search PCD files, write filenames in vector<string> files
	findFiles( filePath.c_str(),files);
	
	
	
	

	
  return 0;
}
