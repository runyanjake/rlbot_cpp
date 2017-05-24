/*************************************
 * @AUTHOR Jake Runyan
 *
 * @FILE rocketlib.cpp
 ************************************/

//****Library Includes****
#include <stdio.h>

//****Local Includes****
#include "auxlib.h"

//****Variables****

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
