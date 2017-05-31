/*************************************
 * @AUTHOR Jake Runyan
 *
 * @FILE fileio.cpp
 ************************************/

using namespace std;

//****Library Includes****

//****Local Includes****
#include "fileio.h"

//****Variables****

//****Function Implementations****
queue<string> file_to_queue(string filename){
	ifstream file (filename.c_str());
	queue<string> q;
	//See if the file could open. If not give back empty queue.
	if(!file.is_open()){fprintf(stderr, "Error: %s missing or was unable to open. Please verify that it exists in the current folder.", filename.c_str()); return q;}
	//find number of lines in file
	string txt;
	int numlines = 0;
    while (!file.eof()){
	    getline(file,txt);
	    numlines++;
	}
	file.close();
	//Get text out of file and put into queue.
	ifstream strfile (filename.c_str());
	for(int a = 0; a < numlines; a++){
		getline(strfile, txt);
		q.push(txt);
	}
	return q;
}
