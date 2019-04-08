#include"../include/findFiles.h"


void findFiles(const char* PATH,vector<string> & files){	
	struct dirent * filePtr;
	DIR * dir;
	dir = opendir(PATH);
	
	while((filePtr = readdir(dir))!=NULL){
		if(filePtr->d_name[0]=='.')
			continue;
		files.push_back(filePtr->d_name);
	}

	closedir(dir);
	sort(files.begin(), files.end());
}
