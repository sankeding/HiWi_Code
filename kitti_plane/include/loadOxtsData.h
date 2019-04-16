#ifndef LOAD_OXTS_DATA
#define LOAD_OXTS_DATA

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "./findFiles.h"

using namespace std;

void loadOxtsData (const string & OxtsPath, vector<vector<double> > & oxts){
	
	if(oxts.size() > 0){ cout << " Data already loaded "<<endl; return; }

	vector<string> files;
	findFiles(OxtsPath.c_str(), files);
	
	for(size_t i=0;i<files.size();i++){
		string InputFile = OxtsPath+files[i];			
		ifstream input;
		input.open(InputFile.c_str());		
		
		vector<double> oxtsRow;
		int count =0;
		while(count<6){                          //when read all data: while(!input.eof())
			char *dataChar;
			input >> dataChar;
			double data = atof(dataChar);
			oxtsRow.push_back(data);
			count++;
		}
		input.close();	
		oxts.push_back(oxtsRow);
	}	
	cout << "load oxts data done" <<endl;
}


#endif
