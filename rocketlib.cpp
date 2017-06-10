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
 * Writes text TO THE CURRENT FOCUS.
 * @param msg The message to be sent.
 */
void send_txt(string msg){
	string cmd = "exe/send_txt.exe " + msg;
	run_exe(cmd.c_str());
}
//Overloaded method to show iterations.
void send_txt(string msg, int itor, int max){
	string cmd = "exe/send_txt.exe " + msg;
	run_exe_show_progress(cmd.c_str(), itor, max);
}

/*
 * Navigates to trade page.
 * @file Uses executable file RLGNavToTrade.exe found in ./exe
 */
void RLGNavToTrade(){
	string cmd = "exe/RLGNavToTrade.exe ";
	run_exe(cmd.c_str());
}
//Overloaded method to show iterations.
void RLGNavToTrade(int itor, int max){
	string cmd = "exe/RLGNavToTrade.exe ";
	run_exe_show_progress(cmd.c_str(), itor, max);
}

/*
 * Sends a trade to RLG.
 * @param trades A queue of trades to be sent.
 */
void RLGMakeTrade(offer trade){
	
}
//Overloaded method to show iterations.
void RLGMakeTrade(offer trade, int itor, int max){

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
void ballcam_switcher_chatty (int num_iterations, int sendingMessages, int tradingOffers, int tradingCrates, int buyingCrates){
	queue<offer> offerz = get_trades();
	queue<string> message_queue = file_to_queue("strings.txt"); //contains all messages.
	int itor = 0; //iterator counter of loops.
	while(num_iterations == INFINITY || itor < num_iterations){
		//Check to see if at menu every 50 iterations.
		//if(itor % 50 == 0 && on_menu()){ start_rl(itor, num_iterations); } //check for menu every 50 iterations.
		
		if(itor % 51 == 0 && found_popup()){ /*Do something*/ } //Check to see if stopped by popup.

		//Check if we should enter a message. If so take first, say it, and requeue.
		if(sendingMessages && itor%35==0){ 
			string excuse = message_queue.front();
			message_queue.pop();
			message_queue.push(excuse);
			send_msg(excuse, itor, num_iterations);
		
		}

		//See if we should make a trade offer.
		if(tradingOffers && itor%30==0){
			trade_poster(&offerz);
		}

		//check to see if we should make a crate offer.
		if(tradingCrates && itor%15==0){
			crate_trader();
		}

		//check to see if we should make a crate offer.
		if(buyingCrates && itor%15==0){
			crate_buyer();
		}

		//Run the bot loop.
		bot_loop(itor, num_iterations);
		
		//Increment loop counter. If infinity no need to do anything.
		if(num_iterations!=INFINITY)itor++;
	}
}

/*
 * Posts trade onto RLGarage.
 * @pre Assume we're on the create trade page.
 */
void trade_poster(queue<offer>* offerz){
	run_exe("exe/RLGDeleteLastTrade.exe");
	run_exe("exe/RLGMakeOfferTrade.exe");
	string whattosay = "";
	for(int a = 0; a < 5; a++){
		offer offr = offerz->front();
		offerz->pop();
		offerz->push(offr);
		if(!(offr.item.cert == "none" || offr.item.cert == "")){
			whattosay = whattosay + offr.item.cert + "+";
		}
		if(!(offr.item.paint == "none" || offr.item.paint == "")){
			whattosay = whattosay + offr.item.paint + "+";
		}
		whattosay = whattosay + offr.item.name + "+for+";
		//get key value into string
		stringstream ss;
		ss << offr.price;
		string price = ss.str();
		whattosay = whattosay + price + "+keys+";
		if(offr.offer){
			whattosay = whattosay + "or+items+with+overpay.+///+";
		}else{
			whattosay = whattosay + "only.+///+";
		}
		whattosay = whattosay + "=+++";
	}
	send_txt(whattosay + "++I+also+have+keys+to+buy+crates+or+items.=+add+me+if+you+have+an+offer.");
	run_exe("exe/RLGSendTrade.exe");
	start_rl();
}

/*
 * Post crate trade to RLG.
 * @pre assume we're on the page 
 */
void crate_trader(){
	run_exe("exe/RLGDeleteLastTrade.exe");
	run_exe("exe/RLGTradeCratesForKeys.exe");
	send_txt("selling+cc1+cc2+cc3+cc4+++11+to+1.=+add+me+if+you+want+to+trade.");
	run_exe("exe/RLGSendTrade.exe");
	start_rl();
}

/*
 * Post crate trade to RLG.
 * @pre assume we're on the page 
 */
void crate_buyer(){
	run_exe("exe/RLGDeleteLastTrade.exe");
	run_exe("exe/RLGTradeForCrates.exe");
	send_txt("buying+cc1+cc2+cc3+cc4+++18+to+1.+will+give+better+rates+if+youre+selling+a+lot.=+add+me+if+you+want+to+trade.");
	run_exe("exe/RLGSendTrade.exe");
	start_rl();
}
