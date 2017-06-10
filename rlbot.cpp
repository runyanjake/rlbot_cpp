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

//**** FIELDS ****
int sendingmessages;
int makeoffers;
int tradingcrates;
int buyingcrates;

//#include "opencv/cv.h"
using namespace std;

int main(int argc, char** argv){
	cout << "******************* RLBOT ********************\n********** A script by Jake Runyan ***********\n";
	
	if(argc > 2 && argc !=6){
		printf("Usage: rlbot <# loops> OR rlbot <# loops> <shouldsendmsg> <shouldmakeoffers> <shouldtradecrates> <shouldbuycrates>\n");
		return ERROR_RETURN_STATUS;
	}

	if(argc == 2){
		num_iterations = atoi(argv[1]);
		sendingmessages = 0;
		makeoffers = 0;
		tradingcrates = 0;
		buyingcrates = 0;
	}else if(argc == 6){
		num_iterations = atoi(argv[1]);
		sendingmessages = atoi(argv[2]);
		makeoffers = atoi(argv[3]);
		tradingcrates = atoi(argv[4]);
		buyingcrates = atoi(argv[5]);
	}else{
		num_iterations = INFINITY;
		sendingmessages = 0;
		makeoffers = 0;
		tradingcrates = 0;
		buyingcrates = 0;
	}

	//Begin body of program.
	start_log_entry(num_iterations);
	ballcam_switcher_chatty(num_iterations, sendingmessages, makeoffers, tradingcrates, buyingcrates);
	end_log_entry();

	cout << "***************** COMPLETED ******************\n**********************************************\n";
}
