#include"../include/doVisualization.h"

void doVisualization( const string & filePath, const vector<string> & files,const vector<vector<double> > &oxts ){
	pcl::PointCloud<pcl::PointXYZI>::Ptr source_cloud (new pcl::PointCloud<pcl::PointXYZI> ());
	pcl::PointCloud<pcl::PointXYZI>::Ptr pose_cloud (new pcl::PointCloud<pcl::PointXYZI> ());
	pcl::visualization::PCLVisualizer viewer ("BEV sequence");

	//Define R,G,B colors for the point cloud	 
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZI> pose_cloud_color_handler (pose_cloud, 255, 255, 255);
	// Setting background to a dark grey
	viewer.setBackgroundColor(0.1, 0.1, 0.1, 0); 
	
	for(int i=0; i<files.size();i++){
		if(i != 0){		
			source_cloud->clear();
			pose_cloud->clear();
			viewer.removePointCloud("pose_cloud");
		}	

		//doUntwisting();		
		pcl::io::loadPCDFile (filePath + files[i], *source_cloud);
	
		//transform
		getPoseCloud(source_cloud, pose_cloud, oxts, i);		
			
		viewer.addPointCloud (pose_cloud, pose_cloud_color_handler,"pose_cloud");
		int loopIndex=1;		
		while(loopIndex){
			viewer.spinOnce();
			//usleep(2000000); //micosecond
			loopIndex=0;
		}
	}
	while(!viewer.wasStopped()){
		viewer.spinOnce();
	}	
	cout << "visualization done" << endl;
}
