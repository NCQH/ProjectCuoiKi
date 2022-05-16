#include "prjHeader.h"
#include "backend.h"
#include "frontend.h"

using namespace std;

char gUsrname[30], gPasswd[30], gFullname[50];
account gAcc;
char *gName, *gAge, *gAddress;
void *emptyBox, *checkedBox, *noMessageBox, *yesMessageBox;

const int SCREEN_WIDTH = 600;

const int SCREEN_HEIGHT = 750;

bool init();
void run();
void close();

int main()
{
	if (init() == false)
	{
		return 0;
	}
	else
	{
		run();
	}
	close();

	return 0;
}
bool init()
{
	bool success = true;
	initwindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Covid19Program by Nguyen Cong Quoc Huy & Nguyen Huu Khanh", 0, 0, 0, 1);
	if (graphresult() != 0)
	{
		success = false;
	}
	return success;
}
void run()
{
	createImage();
	load();
	initChooseScr();
}
void close()
{
	delete[](char *) emptyBox;
	delete[](char *) checkedBox;
	delete[](char *) noMessageBox;
	delete[](char *) yesMessageBox;
	closegraph();
}
