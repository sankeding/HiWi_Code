/*******use mercator coordinate*******/

#ifndef CONVERT_OXTS_TO_POSE
#define CONVERT_OXTS_TO_POSE

#include <iostream>
#include <cmath>
#include <Eigen/Dense>


#define ER 6378137            //Earth radius
#define PI 3.1415926536

using namespace std;
using namespace Eigen;

static int poseAlreadyInit =0;
static double scale = 0;
static Matrix4f Tr_0_inv = Matrix4f::Zero();

Matrix4f calculateTransition(const vector<double> oxtsRow){
	double lat = oxtsRow[0];
	double lon = oxtsRow[1];	
	Matrix3f R, Rx, Ry, Rz =Matrix3f::Zero(); 
	double rx, ry, rz = 0.0;	
	double tx, ty, tz = 0.0;
	Matrix4f Tr = Matrix4f::Zero();

	//translation(use mercator coordinate and a scale to amend)
	tx = scale * lon * PI * ER / 180.0;
	ty = scale * ER * log( tan( (90+lat) * PI / 360.0) );
	tz = oxtsRow[2];

	//rotation matrix
	rx = oxtsRow[3];
	ry = oxtsRow[4];
	rz = oxtsRow[5];
	
	Rx << 1, 0,       0,
	      0, cos(rx), -sin(rx),
              0, sin(rx), cos(rx);

	Ry << cos(ry),  0, sin(ry),
              0,        1, 0,
              -sin(ry), 0, cos(ry);

	Rz << cos(rz), -sin(rz), 0,
              sin(rz), cos(rz),  0,
              0,       0,        1;

	R = Rz * Ry * Rx;

	Tr << R(0,0), R(0,1), R(0,2), tx,
	      R(1,0), R(1,1), R(1,2), ty,
              R(2,0), R(2,1), R(2,2), tz,
	      0,      0,      0,      1;

	

	return Tr;
}

void initPose(const vector<double> oxtsFirst){
	
	scale = cos(oxtsFirst[0] * PI / 180.0);	
	Matrix4f Tr0 = calculateTransition(oxtsFirst);
	Tr_0_inv = Tr0.inverse();
	int poseAlreadyInit = 1;
}

Matrix4f convertOxtsToPose(const vector<vector<double> > & oxts, const int frameId){
	if(!poseAlreadyInit){ initPose(oxts[0]); }
	
	Matrix4f Tr = calculateTransition(oxts[frameId]);
	Matrix4f Pose = Tr_0_inv * Tr;
	return Pose;
}



#endif
