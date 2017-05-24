/*************************************
 * @AUTHOR Jake Runyan
 *
 * @FILE rocketlib.h
 ************************************/

#ifndef __ROCKETLIB_H__
#define __ROCKETLIB_H__

using namespace std;

//****Library Includes****
#include <string>

//****Local Includes****
#include "auxlib.h"

//****Field Declarations****

//****Function Declarations****
void start_rl();
void bot_loop();
void send_msg(string msg);
int on_menu();

#endif