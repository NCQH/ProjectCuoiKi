#if !defined(_FRONTEND_H_)
#define _FRONTEND_H_

#include "prjHeader.h"
#include "backend.h"

using namespace std;

#define MAX 100
#define ENTER 13
#define ESC 27
#define TAB 9
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define BACKSPACE 8

struct box
{
    int left, top;
    bool check;

    void display();
};
struct button
{
    int left;
    int top;
    int right;
    int bottom;
    int bgcolor;
    int rad;

    char *title;
    int fontsize;
    int txtcolor;

    button(int left, int top, int right, int bottom, int bgcolor, int rad);
    void setTitle(char *title, int txtcolor, int fontsize);
    void display();
};

struct radioButton
{
    int x;
    int y;
    int rad;
    char *name;
    bool checked;

    radioButton(int x, int y, int rad, char *name);
    void display();
};

extern char gUsrname[30], gPasswd[30], gFullname[50];
extern account gAcc;
extern char *gName, *gAge, *gAddress;
extern char *PName, *PAge, *PAddress;
extern void *emptyBox, *checkedBox, *noMessageBox, *yesMessageBox;

void createImage();
void load();
void initChooseScr();
void initGuestInfo();
void initPredictScr();
void initMngLoginScr();
void initMngScr(account mngAcc);
void initSignUpScr();

void showAlertScr();
void sndEffect(char *sound);

void rndConnerRect(int left, int top, int right, int bottom, int rad);
void barWithTxt(int left, int top, int right, int bottom, int fontsize, char *txt, int align, int fillstyle = 0); // default fill empty
bool yesNoMessBox();

#endif // _FRONTEND_H_
