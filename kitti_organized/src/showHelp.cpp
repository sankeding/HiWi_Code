#include <iostream>
#include "../include/showHelp.h"
using namespace std;

void showHelp(char* program_name){
	cout<< endl;
	cout<< "Usage: "<< program_name << endl;
	cout<<"ps: PCDfiles should be under 'project_name'/data/"<<endl;
	cout<< "-h: Show this help." << endl;
}
