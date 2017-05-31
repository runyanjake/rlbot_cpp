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
#include "fileio.h"

//****Field Declarations****

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
//Overloaded method to show iterations.
void start_rl(int itor, int max){
	run_exe_show_progress("exe/startRL.exe", itor, max);
}

/*
 * Runs 5 iterations of a primitive loop to stay in-game indefinitely.
 * @file Uses executable file "RLBotAutom.exe" found in ./exe
 * @pre Recommended to be used when already in or finding match.
 */
void bot_loop(){
	run_exe("exe/RLBotAutom.exe");
}
//Overloaded method to show iterations.
void bot_loop(int itor, int max){
	run_exe_show_progress("exe/RLBotAutom.exe", itor, max);
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
//Overloaded method to show iterations.
void send_msg(string msg, int itor, int max){
	string cmd = "exe/send_msg.exe " + msg;
	run_exe_show_progress(cmd.c_str(), itor, max);
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
	queue<string> message_queue = file_to_queue("strings.txt"); //contains all messages.
	int itor = 0; //iterator counter of loops.
	while(num_iterations == INFINITY || itor < num_iterations){
		//Check to see if at menu every 50 iterations.
		if(itor % 50 == 0 && on_menu()){ start_rl(itor, num_iterations); } //check for menu every 50 iterations.
		if(itor % 51 == 0 && found_popup()){ /*Do something*/ } //Check to see if stopped by popup.
		//Check if we should enter a message. If so take first, say it, and requeue.
		if(itor%35==0){ 
			string excuse = message_queue.front();
			message_queue.pop();
			message_queue.push(excuse);
			send_msg(excuse, itor, num_iterations);
		}
		//Run the bot loop.
		bot_loop(itor, num_iterations);
		//Increment loop counter. If infinity no need to do anything.
		if(num_iterations!=INFINITY)itor++;
	}
}

/*
 * Posts trade onto RLGarage.
 */
void trade_poster(){

}
