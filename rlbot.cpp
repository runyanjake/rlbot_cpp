/*************************************
 * @AUTHOR Jake Runyan
 *
 * @FILE rlbot.cpp
 ************************************/

//****Lib Includes****
#include <iostream>
#include <unistd.h>

//****Local Includes****
#include  "auxlib.h"

//****Defines****
#define DEFAULT_RETURN_STATUS 0
#define ERROR_RETURN_STATUS 1

/******Debug Codes******\
**** -d is base flag ****
* a : include all flags.
*/

//#include "opencv/cv.h"
using namespace std;

int main(int argc, char** argv){
	run_exe("startRL.exe");

	cout << "******************* RLBOT ********************\n********** A script by Jake Runyan ***********\n";
	
	int flag;
	while((flag = getopt(argc, argv, "d::")) != -1){
		switch(flag){
			case 'd': 
				if(optarg){
					set_debug_flags(optarg);
					cout << "Setting debug_flag: " << optarg << "\n";
				}
				break;
			default:
				cout << "No readable flags.\n";
		}
	}

	
}
