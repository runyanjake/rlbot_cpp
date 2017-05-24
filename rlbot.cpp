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
#define INFINITY -1

//****Variable Defines****
int num_iterations = 0;
int primes[] = {199,139,109,89,79}; 

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
	start_log_entry();
	int itor = 0; //iterator counter of loops.
	while(num_iterations == INFINITY || itor < num_iterations){
		//Check to see if at menu.
		if(itor % 50 == 0 && on_menu()){ //check for menu every 50 iterations.
			start_rl(); 
		}

		//Check if we should enter a message.
		if(itor%(primes[0])==0){
			send_msg("sorry+controller+broken");
		}else if(itor%(primes[1])==0){
			send_msg("this+is+weird+i+cant+move+right");
		}else if(itor%(primes[2])==0){
			send_msg("my+controller+disconnected+hold+on");
		}else if(itor%(primes[3])==0){
			send_msg("sorry+getting+a+call");
		}

		//Run the bot loop.
		bot_loop();

		//Increment loop counter. If infinity no need to do anything.
		if(num_iterations!=INFINITY)itor++;
	}

	end_log_entry();

	
}
