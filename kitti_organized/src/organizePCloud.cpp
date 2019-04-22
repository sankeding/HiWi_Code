#include "../include/organizePCloud.h"

void organizePCloud(pcl::PointCloud<pcl::PointXYZI>::Ptr & cloud,const vector<vector<double> > & oxts, const int frameId){
	pcl::PointCloud<pcl::PointXYZI>::Ptr part_cloud (new pcl::PointCloud<pcl::PointXYZI> ());
	pcl::PointCloud<pcl::PointXYZI>::Ptr org_cloud (new pcl::PointCloud<pcl::PointXYZI> ());
	
	string Path = "./data/";		
	makeDir(Path.c_str());

	for(size_t i=0;i<cloud->size();i++){
		if(cloud->points[i].x < uplimitX && cloud->points[i].x > downlimitX && cloud->points[i].y < limitY ) {
			part_cloud->push_back(cloud->points[i]);
		}		
	} 
	
	for(int i=0;i<laserRange;i++){
		double uplimitRad = (laserUppest + 0.15 - i * laserInterval) * M_PI / 180.0;
		double downlimitRad = (laserUppest - 0.15 - i * laserInterval) * M_PI / 180.0;
		
		org_cloud->clear();		
		for(size_t k=0;k < part_cloud->size();k++){	
			double x = part_cloud->points[k].x;
			double y = part_cloud->points[k].y;
			double z = part_cloud->points[k].z;
			double rad = atan( z / sqrt(pow(x,2) + pow(y,2)) );
			//rad = atan (cloud->points[i].z / cloud->point[i].x);
			if(rad > downlimitRad && rad < uplimitRad){
				org_cloud->push_back(part_cloud->points[k]);
			}
		}
		//doFiltering();	
		
		
		if(org_cloud->size() > 10){
			stringstream ss;
			pcl::PCDWriter writer;
			char cc[2];
			sprintf(cc,"%02d",i); 
  			ss << Path <<"org_cloud" << cc <<".pcd";
			writer.write<pcl::PointXYZI> (ss.str(), *org_cloud, false);
		}	

	}


	
	


}
