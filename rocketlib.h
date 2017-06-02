/*************************************
 * @AUTHOR Jake Runyan
 *
 * @FILE rocketlib.h
 ************************************/

#ifndef __ROCKETLIB_H__
#define __ROCKETLIB_H__

using namespace std;

#define INFINITY -1

//****Library Includes****
#include <string>

//****Local Includes****
#include "auxlib.h"
#include "fileio.h"

//****Function Declarations****
void start_rl();
void bot_loop();
void send_msg(string msg);
void send_txt(string msg);
void RLGNavToTrade();
void RLGNavToTrade(int itor, int max);
void RLGMakeTrade(offer trade);
void RLGMakeTrade(offer trade, int itor, int max);
int on_menu();
int found_popup();

void ballcam_switcher_chatty (int num_iterations);
void trade_poster(queue<offer>* offerz);

#endif