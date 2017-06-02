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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>

//****Field Declarations****
/*
 * A RL item.
 */
struct item{
	string name;
	string cert;
	string paint;
};

/*
 * An offer for a trade.
 */
struct offer{
	struct item item;
	int price;
	int offer; // 1 or 0
	string msg;
};

//****Function Declarations****
queue<string> file_to_queue(string filename);
queue<offer> get_trades();

#endif