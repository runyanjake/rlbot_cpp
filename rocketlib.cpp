/*************************************
 * @AUTHOR Jake Runyan
 *
 * @FILE rocketlib.cpp
 ************************************/

//****Library Includes****
#include <stdio.h>

//****Local Includes****
#include "rocketlib.h"
#include "auxlib.h"

//****Field Declarations****
static int primes[] = {450,420,390,360,330,300,270,240,210,180,150,120,90,60,30}; 

//****Function Implementations****
/*
 * From the Main Menu, searches for and begins a match.
 * @file Uses executable file "startRL.exe" found in ./exe
 * @pre Must already be at main menu.
 * @pre Must have solo duel (or any unranked game mode) selected.
 */
void start_rl(){
	run_exe("exe/startRL.exe");
}

/*
 * Runs 5 iterations of a primitive loop to stay in-game indefinitely.
 * @file Uses executable file "RLBotAutom.exe" found in ./exe
 * @pre Recommended to be used when already in or finding match.
 */
void bot_loop(){
	run_exe("exe/RLBotAutom.exe");
}

/*
 * Sends a message to the global chat.
 * @note Presses 't' to enable chat and ENTER to send message automatically.
 * @param msg The message to be sent.
 */
void send_msg(string msg){
	string cmd = "exe/send_msg.exe " + msg;
	run_exe(cmd.c_str());
}

/*
 * Checks to see if application is on Main Menu.
 * @file Uses executable file "_____" found in ./exe
 * @return true If application is on Main Menu.
 * @return false If application is not on Main Menu.
 */
int on_menu(){
	return 1;
}

/*
 * Checks to see if a popup dialog box has appeared.
 * @file Uses executable file "_____" found in ./exe
 */
int found_popup(){
	return 1;
}

//**** PROGRAM CONFIGURATIONS ****
/*
 * Can maintain basic activity in unranked games. Makes comment to opponent every once and awhile.
 * @param num_iterations The number of iterations to run for.
 */
void ballcam_switcher_chatty (int num_iterations){
	int itor = 0; //iterator counter of loops.
	while(num_iterations == INFINITY || itor < num_iterations){
		//Check to see if at menu every 50 iterations.
		if(itor % 50 == 0 && on_menu()){ start_rl(); } //check for menu every 50 iterations.
		if(itor % 51 == 0 && found_popup()){ /*Do something*/ } //Check to see if stopped by popup.
		//Check if we should enter a message.
		if(itor%(primes[0])==0){ send_msg("sorry+controller+broken"); }
		else if(itor%(primes[1])==0){ send_msg("this+is+weird+i+cant+move+right"); }
		else if(itor%(primes[2])==0){ send_msg("my+controller+disconnected+hold+on"); }
		else if(itor%(primes[3])==0){ send_msg("sorry+getting+a+call"); }
		else if(itor%(primes[4])==0){ send_msg("cord+got+tangled"); }
		else if(itor%(primes[5])==0){ send_msg("one+sec"); }
		else if(itor%(primes[6])==0){ send_msg("pizzas+here+lol"); }
		else if(itor%(primes[7])==0){ send_msg("one+sec+spilled+my+drink"); }
		//Run the bot loop.
		bot_loop();
		//Increment loop counter. If infinity no need to do anything.
		if(num_iterations!=INFINITY)itor++;
	}
}

/*
 * Posts trade onto RLGarage.
 */
void trade_poster(){

}
