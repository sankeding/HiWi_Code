/*******use mercator coordinate*******/

#ifndef CONVERT_OXTS_TO_POSE
#define CONVERT_OXTS_TO_POSE

#include <iostream>
#include <cmath>
#include <Eigen/Dense>
#include<vector>

#define ER 6378137            //Earth radius
#define PI 3.1415926536

using namespace std;
using namespace Eigen;

static int poseAlreadyInit ;
static double scale ;
static Matrix4f Tr_0_inv ;

Matrix4f calculateTransition(const vector<double> oxtsRow);

void initPose(const vector<double> oxtsFirst);
Matrix4f convertOxtsToPose(const vector<vector<double> > & oxts, const int frameId);



#endif
