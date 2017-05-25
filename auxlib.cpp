/*************************************
 * @AUTHOR Jake Runyan
 *
 * @FILE auxlib.cpp
 ************************************/

//****Library Includes****
#include <stdio.h>

//****Local Includes****
#include "auxlib.h"

//****Variables****
char* debug_flags;
string lastexe = "";


//****Function Implementations****

/*
 * Runs a file from the program executable folder. 
 * @pre ./exe/program.exe must exist.
 */
void run_exe(string program){
	if(program != lastexe){ //only update when there's a new program being run.
		printf("Running: %s...\n", program.c_str());
		lastexe = program;
	}
	system(program.c_str());
}

/*
 * Passes a debug parameter to be used in DEBUGF print statements.
 * COMING SOON!
 */
void set_debug_flags(char* optarg){
	debug_flags = optarg;
}


void start_log_entry(int itors){
	FILE* log = fopen("log.txt", "w");
	fprintf(log, "----- Entry at %s -----\nRequested number of iterations: %d.\n", currentDateTime().c_str(), itors);
	fclose(log);
}

void make_log_entry(string msg, string callee){
	FILE* log = fopen("log.txt", "w");
	fprintf(log, "%s-%s: %s\n", callee.c_str(), currentDateTime().c_str(), msg.c_str());
	fclose(log);
}

void end_log_entry(){
	FILE* log = fopen("log.txt", "w");
	fprintf(log, "----- Process Completed -----\n-----------------------------\n\n");
	fclose(log);
}

string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
