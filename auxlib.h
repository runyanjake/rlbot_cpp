/*************************************
 * @AUTHOR Jake Runyan
 *
 * @FILE auxlib.h
 ************************************/

#ifndef __AUXLIB_H__
#define __AUXLIB_H__

using namespace std;

//****Library Includes****
#include <string>
#include <stdlib.h> /*system, NULL, EXIT_FAILURE*/
#include <stdio.h> /*printf*/

//****Field Declarations****
extern char* debug_flags;
void run_exe(string program);

//****Method Declarations****
 void set_debug_flags(char* optarg);

#endif