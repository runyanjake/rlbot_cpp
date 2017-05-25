/*************************************
 * @AUTHOR Jake Runyan
 *
 * @FILE rlbot.cpp
 ************************************/

//****Lib Includes****
#include <iostream>
#include <unistd.h>

//****Local Includes****
#include "auxlib.h"
#include "rocketlib.h"

//****Defines****
#define DEFAULT_RETURN_STATUS 0
#define ERROR_RETURN_STATUS 1

//****Variable Defines****
int num_iterations = 0;

/******Debug Codes******\
**** -d is base flag ****
* a : include all flags.
*/

//#include "opencv/cv.h"
using namespace std;

int main(int argc, char** argv){
	cout << "******************* RLBOT ********************\n********** A script by Jake Runyan ***********\n";
	
	if(argc > 2){
		printf("Usage: rlbot <# loops>\n");
		return ERROR_RETURN_STATUS;
	}

	if(argc == 2){
		num_iterations = atoi(argv[1]);
	}else{
		num_iterations = INFINITY;
	}

	//Begin body of program.
	start_log_entry(num_iterations);
	ballcam_switcher_chatty(num_iterations);
	end_log_entry();

	cout << "***************** COMPLETED ******************\n**********************************************\n";
}
