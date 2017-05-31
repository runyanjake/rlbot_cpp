/*************************************
 * @AUTHOR Jake Runyan
 *
 * @FILE fileio.h
 ************************************/

#ifndef __FILEIO_H__
#define __FILEIO_H__

using namespace std;

//****Library Includes****
#include <queue>
#include <string>
#include <stdio.h>
#include <fstream>

//****Field Declarations****

//****Function Declarations****
queue<string> file_to_queue(string filename);

#endif