#if !defined(_PRJHEADER_H_)
#define _PRJHEADER_H_

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <graphics.h>
#include <string>
#include <mmsystem.h>
#include "account.h"

using namespace std;

string get_current_dir();
void copyCharArr(char exsitArr[], char newArr[], int n);
void copyCharArr(string exsitStr, char newArr[], int n, int m);

#endif // _PRJHEADER_H_
