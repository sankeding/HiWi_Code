#include"../include/doVisualization.h"

void doVisualization(const string & filePath, const vector<string> & files){
	pcl::PointCloud<pcl::PointXYZI>::Ptr source_cloud (new pcl::PointCloud<pcl::PointXYZI> ());
	
	pcl::visualization::PCLVisualizer viewer ("BEV sequence");

	//Define R,G,B colors for the point cloud	 
	pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZI> source_cloud_color_handler (source_cloud, 255, 255, 255);
	// Setting background to a dark grey
	viewer.setBackgroundColor(0.1, 0.1, 0.1, 0); 
	
	for(int i=0; i<files.size();i++){
		if(i != 0){		
			source_cloud->clear();
			viewer.removePointCloud("source_cloud");
		}			
		pcl::io::loadPCDFile (filePath + files[i], *source_cloud);
		viewer.addPointCloud (source_cloud, source_cloud_color_handler,"source_cloud");
		int loopIndex=1;		
		while(loopIndex){
			viewer.spinOnce();
			//usleep(2000000); //micosecand
			loopIndex=0;
		}
	}
	while(!viewer.wasStopped()){
		viewer.spinOnce();
	}	
	cout << "visualization done" << endl;
}
