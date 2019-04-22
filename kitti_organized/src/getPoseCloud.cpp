#include "../include/getPoseCloud.h"

void getPoseCloud(pcl::PointCloud<pcl::PointXYZI>::Ptr & source_cloud,  pcl::PointCloud<pcl::PointXYZI>::Ptr & pose_cloud, const vector<vector<double> > & oxts, const int frameId){
	
	Matrix4f Pose = Matrix4f::Zero();
	//frameId start from 0 
	Pose = convertOxtsToPose(oxts,frameId);
	
	pose_cloud->clear();
	pcl::PointXYZI point;
	Vector4f vec;
	vec[3] = 1;
	for(size_t i=0;i<source_cloud->size();i++){
		vec[0] = source_cloud->points[i].x;
		vec[1] = source_cloud->points[i].y;
		vec[2] = source_cloud->points[i].z;
		vec = Pose * vec;
		point.x = vec[0];
		point.y = vec[1];
		point.z = vec[2];
		point.intensity = source_cloud->points[i].intensity;
		pose_cloud->push_back(point);	
	}	

}
