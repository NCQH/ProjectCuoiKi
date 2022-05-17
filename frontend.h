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

extern char gUsrname[30], gPasswd[30], gFullname[50];
extern account gAcc;
extern char *gName, *gAge, *gAddress;
extern char *PName, *PAge, *PAddress;
extern void *emptyBox, *checkedBox, *noMessageBox, *yesMessageBox;

void createImage(); 				// Luu hinh anh da ve ra man hinh vao 1 bien
void load();						// Khoi tao man hinh load
void initChooseScr();				// Khoi tao man hinh lua chon
void initGuestInfo();				// Khoi tao man hinh dien thong tin khach
void initPredictScr();				// Khoi tao man hinh chan doan
void initMngLoginScr();				// Khoi tao man hinh dang nhap cua quan li
void initMngScr(account mngAcc);	// Khoi tao man hinh quan li
void initSignUpScr();				// Khoi tao man hinh dang ki

void showAlertScr();				// Hien thi man hinh canh bao
void sndEffect(char *sound);		// Hieu ung am thanh

void rndConnerRect(int left, int top, int right, int bottom, int rad);												// ve hinh chu nhat bo goc
void barWithTxt(int left, int top, int right, int bottom, int fontsize, char *txt, int align, int fillstyle = 0);	// ve thanh bar voi chu ben trong
bool yesNoMessBox();																								// hien thi hop thoai thong bao yes no

#endif // _FRONTEND_H_
