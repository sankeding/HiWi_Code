#include "../include/makeDir.h"

int makeDir(const char * path){
	if (access(path, 0) == -1){
		return mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	}
	else{
		cout << endl << "dir: " << path << " already exist" <<endl;
		cout << "wait to be writed: how to remove dir and all files unter it" <<endl<<endl;
		return -1;
	}
}

