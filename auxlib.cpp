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

/*
 * Runs a file from the program executable folder. 
 * @pre ./exe/program.exe must exist.
 */
void run_exe(string program){
	string cmd = "exe/" + program;
	printf("Running: ./%s...\n", cmd.c_str());
	system(cmd.c_str());
}

/*
 * Passes a debug parameter to be used in DEBUGF print statements.
 * COMING SOON!
 */
void set_debug_flags(char* optarg){
	debug_flags = optarg;
}

