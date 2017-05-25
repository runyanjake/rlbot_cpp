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

//****Function Declarations****
void start_rl();
void bot_loop();
void send_msg(string msg);
int on_menu();
int found_popup();

void ballcam_switcher_chatty (int num_iterations);
void trade_poster();

#endif