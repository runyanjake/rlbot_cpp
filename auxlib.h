/*************************************
 * @AUTHOR Jake Runyan
 *
 * @FILE auxlib.h
 ************************************/

#ifndef __AUXLIB_H__
#define __AUXLIB_H__

using namespace std;

//****Library Includes****
#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h> /*system, NULL, EXIT_FAILURE*/
#include <stdio.h> /*printf*/

//****Field Declarations****
extern char* debug_flags;

//****Function Declarations****
void run_exe(string program);
void set_debug_flags(char* optarg);
void start_log_entry(int itors);
void end_log_entry();
string currentDateTime();

#endif