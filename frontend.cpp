#include "frontend.h"

button::button(int left, int top, int right, int bottom, int bgcolor, int rad)
{
    this->left = left;
    this->top = top;
    this->right = right;
    this->bottom = bottom;
    this->bgcolor = bgcolor;
    this->rad = rad;
}
// button setting
void button::setTitle(char *title, int txtcolor, int fontsize)
{
    this->title = title;
    this->txtcolor = txtcolor;
    this->fontsize = fontsize;
}
void button::display()
{
    setfillstyle(1, bgcolor);
    setbkcolor(bgcolor);
    setcolor(bgcolor);
    rndConnerRect(left, top, right, bottom, rad);
    floodfill(left + rad * 3, top + rad * 3, bgcolor);
    setcolor(txtcolor);
    barWithTxt(left, top, right, bottom, fontsize, title, 1);
}
// end button setting
radioButton::radioButton(int x, int y, int rad, char *name)
{
    this->x = x;
    this->y = y;
    this->rad = rad;
    this->name = name;
}
void radioButton::display()
{
    circle(x, y, rad);
    if (checked)
    {
        circle(x, y, (float)rad * 2 / 3);
        setfillstyle(1, 0);
        floodfill(x, y, 0);
    }
}
void box::display()
{
    if (check)
    {
        putimage(left, top, checkedBox, COPY_PUT);
    }
    else
    {
        putimage(left, top, emptyBox, COPY_PUT);
    }
}
void rndConnerRect(int left, int top, int right, int bottom, int rad)
{
    line(left + rad, top, right - rad, top);
    line(left + rad, bottom, right - rad, bottom);
    line(left, top + rad, left, bottom - rad);
    line(right, top + rad, right, bottom - rad);
    arc(left + rad, top + rad, 90, 180, rad);
    arc(left + rad, bottom - rad, -180, -90, rad);
    arc(right - rad, top + rad, 0, 90, rad);
    arc(right - rad, bottom - rad, -90, 0, rad);
}
void barWithTxt(int left, int top, int right, int bottom, int fontsize, char *txt, int align, int fillstyle)
{
    settextstyle(BOLD_FONT, HORIZ_DIR, fontsize);
    int text_w = textwidth(txt);
    int text_h = textheight(txt);
    int bar_w = right - left;
    int bar_h = bottom - top;
    int x;
    if (align == 0) // align left
    {
        x = left;
    }
    else if (align == 1)
    {
        x = left + (bar_w - text_w) / 2; // align center
    }
    else
    {
        x = left + bar_w - text_w; // align right
    }
    int y = top + (bar_h - text_h) / 2;
    if (fillstyle != 0)
    {
        setfillstyle(fillstyle, getbkcolor());
        bar(left, top, right, bottom);
    }
    outtextxy(x, y, txt);
}
void createImage()
{
    // Vẽ ảnh nháp
    setbkcolor(9);
    setfillstyle(1, 15);
    setcolor(0);

    cleardevice();
    // emptyBox
    bar(10, 10, 25, 25);
    // checkedBox
    bar(30, 10, 45, 25);
    line(30, 10, 45, 25);
    line(30, 25, 45, 10);

    // Khai báo biến để chứa kích thước của ảnh
    unsigned int size1;

    // Gán kích thước của ảnh vào biến
    size1 = imagesize(10, 10, 25, 25);

    // Cấp phát động cho 2 con trỏ
    emptyBox = new int[size1];
    checkedBox = new int[size1];

    // Gán giá trị theo bit vào con trỏ
    getimage(10, 10, 25, 25, emptyBox);
    getimage(30, 10, 45, 25, checkedBox);

    setbkcolor(15);
    cleardevice();
    // message box no
    setfillstyle(1, 15);
    setbkcolor(15);
    setcolor(15);
    rndConnerRect(100, 100, 500, 200, 7);
    floodfill(150, 150, 15);
    setcolor(0);
    rndConnerRect(100, 100, 500, 200, 7);
    barWithTxt(100, 100, 500, 150, 2, "Are you sure?", 1);
    rndConnerRect(165, 160, 235, 190, 5);
    barWithTxt(165, 160, 235, 190, 2, "Yes", 1);
    rndConnerRect(365, 160, 435, 190, 5);
    barWithTxt(365, 160, 435, 190, 2, "No", 1);
    setcolor(9);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    rndConnerRect(365, 160, 435, 190, 5);

    unsigned int size3 = imagesize(30, 0, 430, 100);

    noMessageBox = new int[size3];

    getimage(100, 100, 500, 200, noMessageBox);

    setbkcolor(15);
    setcolor(0);
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    cleardevice();
    // messagebox yes
    setfillstyle(1, 15);
    setbkcolor(15);
    setcolor(15);
    rndConnerRect(100, 100, 500, 200, 7);
    floodfill(150, 150, 15);
    setcolor(0);
    rndConnerRect(100, 100, 500, 200, 7);
    barWithTxt(100, 100, 500, 150, 2, "Are you sure?", 1);
    rndConnerRect(165, 160, 235, 190, 5);
    barWithTxt(165, 160, 235, 190, 2, "Yes", 1);
    rndConnerRect(365, 160, 435, 190, 5);
    barWithTxt(365, 160, 435, 190, 2, "No", 1);
    setcolor(9);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    rndConnerRect(165, 160, 235, 190, 5);

    yesMessageBox = new int[size3];

    getimage(100, 100, 500, 200, yesMessageBox);
}
void load()
{
    setbkcolor(BLACK);
    setcolor(YELLOW);
    cleardevice();

    setfillstyle(0, getbkcolor());
    barWithTxt(0, 0, 600, 100, 4, "COVID19 PROGRAM", 1, 1);

    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    rectangle(200, 300, 400, 350);
    for (int i = 0; i < 200; i++)
    {
        delay(10);
        line(200 + i, 300, 200 + i, 350);
        // Prevent kbhit and click
        if (kbhit())
        {
            getch();
        }
        clearmouseclick(WM_LBUTTONDOWN);
    }
    setfillstyle(0, getbkcolor());
    do
    {
        barWithTxt(0, 650, 600, 700, 2, "by Nguyen Cong Quoc Huy & Nguyen Huu Khanh", 1);
        barWithTxt(0, 700, 600, 750, 2, "INT1008_21", 1, 1);
        clearmouseclick(WM_LBUTTONDOWN);
        delay(500);
        barWithTxt(0, 400, 600, 500, 2, "Press any key to continue", 1, 1);
        delay(500);
        barWithTxt(0, 400, 600, 500, 3, "Press any key to continue", 1, 1);
    } while (!kbhit());
    getch();
}
void initChooseScr()
{
    setbkcolor(9);
    cleardevice();

    int hover = 4, unhover = 14, hoverTxt = 14, unhoverTxt = 4;
    bool isFirstHover = 1;
    bool holding = 0;
    bool change = 1;

    button btnA(150, 250, 450, 300, hover, 8);
    button btnB(150, 400, 450, 450, unhover, 8);

    btnA.setTitle("Manager", hoverTxt, 3);
    btnB.setTitle("Guest", unhover, 3);

    do
    {
        delay(10);
        if (change)
        {
            if (isFirstHover)
            {
                btnA.bgcolor = hover;
                btnA.txtcolor = hoverTxt;
                btnB.bgcolor = unhover;
                btnB.txtcolor = unhoverTxt;
                btnA.display();
                btnB.display();

                setbkcolor(15);
                setcolor(0);
                rndConnerRect(80, 45, 520, 190, 4);
                setfillstyle(SOLID_FILL, 15);
                floodfill(90, 90, 0);
                barWithTxt(90, 55, 510, 75, 2, "Go to the manager login screen", 1, 1);
            }
            else
            {
                btnA.bgcolor = unhover;
                btnA.txtcolor = unhoverTxt;
                btnB.bgcolor = hover;
                btnB.txtcolor = hoverTxt;
                btnA.display();
                btnB.display();

                setbkcolor(15);
                setcolor(0);
                rndConnerRect(80, 45, 520, 190, 4);
                setfillstyle(SOLID_FILL, 15);
                floodfill(90, 90, 0);
                barWithTxt(90, 55, 510, 75, 2, "Go to the guest information screen", 1, 1);
            }
            change = 0;
        }
        if (ismouseclick(WM_MOUSEMOVE))
        {
            int pos_x, pos_y;
            getmouseclick(WM_MOUSEMOVE, pos_x, pos_y);
            bool btnAhold = pos_x >= btnA.left && pos_x <= btnA.right && pos_y >= btnA.top && pos_y <= btnA.bottom;
            bool btnBhold = pos_x >= btnB.left && pos_x <= btnB.right && pos_y >= btnB.top && pos_y <= btnB.bottom;
            if (btnAhold && !holding)
            {
                sndEffect("hold");
                holding = 1;
                isFirstHover = 1;
                change = 1;
            }
            else if (btnBhold && !holding)
            {
                sndEffect("hold");
                holding = 1;
                isFirstHover = 0;
                change = 1;
            }
            else if (!btnAhold && !btnBhold)
            {
                holding = 0;
            }
        }
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int pos_x, pos_y;
            getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);
            bool btnAclick = pos_x >= btnA.left && pos_x <= btnA.right && pos_y >= btnA.top && pos_y <= btnA.bottom;
            bool btnBclick = pos_x >= btnB.left && pos_x <= btnB.right && pos_y >= btnB.top && pos_y <= btnB.bottom;
            if (btnAclick)
            {
                sndEffect("click");
                showAlertScr();
                initMngLoginScr();
            }
            else if (btnBclick)
            {
                sndEffect("click");
                showAlertScr();
                initGuestInfo();
            }
        }
        if (kbhit())
        {
            char ch = getch();
            if (ch == 0)
            {
                ch = getch();
                if (ch == UP && isFirstHover == 0)
                {
                    isFirstHover = 1;
                    change = 1;
                }
                if (ch == DOWN && isFirstHover == 1)
                {
                    isFirstHover = 0;
                    change = 1;
                }
            }
            else if (ch == ENTER)
            {
                if (isFirstHover)
                {
                    showAlertScr();
                    initMngLoginScr();
                }
                else
                {
                    showAlertScr();
                    initGuestInfo();
                }
            }
        }
    } while (1);
}
void initMngLoginScr()
{
    char *tempPass;
    string strUsrname = "", strPasswd = "", strTempPass = "";
begin:
    setbkcolor(9);
    cleardevice();

    setfillstyle(1, 15);
    setbkcolor(15);
    setcolor(15);
    rndConnerRect(5, 200, 595, 500, 5);
    floodfill(350, 350, 15);

    setcolor(0);
    setbkcolor(9);
    barWithTxt(5, 100, 595, 190, 5, "Sign in", 1);
    setbkcolor(15);
    barWithTxt(15, 250, 100, 300, 2, "Username: ", 0);
    barWithTxt(15, 350, 100, 400, 2, "Password: ", 0);
    rndConnerRect(150, 250, 580, 300, 5);
    rndConnerRect(150, 350, 580, 400, 5);

    button cfBtn(480, 445, 570, 485, LIGHTBLUE, 8);
    cfBtn.setTitle("Confirm", 15, 1);
    cfBtn.display();

    button backBtn(15, 700, 75, 730, 15, 8);
    backBtn.setTitle("<<<", 0, 3);
    backBtn.display();

    copyCharArr(strUsrname, gUsrname, strUsrname.length(), 30);
    copyCharArr(strPasswd, gPasswd, strPasswd.length(), 30);
    tempPass = &strTempPass[0];

    int currentCur = 250;
    char ch;

    barWithTxt(160, 255, 570, 295, 2, gUsrname, 0, 1);
    barWithTxt(160, 355, 570, 395, 2, tempPass, 0, 1);

    do
    {
        if (kbhit())
        {
            ch = getch();
            if (ch == 0)
            {
                ch = getch();
                if (ch == UP)
                {
                    if (currentCur == 350)
                    {
                        currentCur = 250;
                    }
                }
                else if (ch == DOWN)
                {
                    currentCur = 350;
                }
            }
            else if (ch == ENTER || ch == TAB)
            {
                if (currentCur == 250)
                {
                    currentCur = 350;
                }
            }
            else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '@' || ch == '.')
            {
                if (currentCur == 250)
                {
                    strUsrname.push_back(ch);
                }
                else if (currentCur == 350)
                {
                    if (ch != '.')
                    {
                        strPasswd.push_back(ch);
                        strTempPass.push_back('*');
                    }
                }
            }
            else if (ch == BACKSPACE)
            {
                if (currentCur == 250 && strUsrname.length() > 0)
                {
                    strUsrname.pop_back();
                }
                else if (currentCur == 350 && strTempPass.length() > 0)
                {
                    strPasswd.pop_back();
                    strTempPass.pop_back();
                }
                else if ((currentCur == 250 && strUsrname.length() == 0) || (currentCur == 350 && strPasswd.length() == 0))
                {
                    sndEffect("error");
                }
            }
            if (currentCur == 250)
            {
                copyCharArr(strUsrname, gUsrname, strUsrname.length(), 30);
                setcolor(0);
                setfillstyle(1, 15);
                barWithTxt(160, 255, 570, 295, 2, gUsrname, 0, 1);
            }
            else if (currentCur == 350)
            {
                copyCharArr(strPasswd, gPasswd, strPasswd.length(), 30);
                tempPass = &strTempPass[0];
                setcolor(0);
                setfillstyle(1, 15);
                barWithTxt(160, 355, 570, 395, 2, tempPass, 0, 1);
            }
        }
        if (!kbhit())
        {
            delay(100);
            if (!kbhit())
            {
                if (currentCur == 250)
                {
                    setcolor(0);
                    line(160 + textwidth(gUsrname), currentCur + 10, 160 + textwidth(gUsrname), currentCur + 40);
                    setcolor(15);
                    delay(50);
                    line(160 + textwidth(gUsrname), currentCur + 10, 160 + textwidth(gUsrname), currentCur + 40);
                    setcolor(0);
                }
                else if (currentCur == 350)
                {
                    setcolor(0);
                    line(160 + textwidth(tempPass), currentCur + 10, 160 + textwidth(tempPass), currentCur + 40);
                    setcolor(15);
                    delay(50);
                    line(160 + textwidth(tempPass), currentCur + 10, 160 + textwidth(tempPass), currentCur + 40);
                    setcolor(0);
                }
            }
        }
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int pos_x, pos_y;
            getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);
            bool backBtnClick = pos_x >= backBtn.left && pos_x <= backBtn.right && pos_y >= backBtn.top && pos_y <= backBtn.bottom;
            bool cfBtnClick = pos_x >= cfBtn.left && pos_x <= cfBtn.right && pos_y >= cfBtn.top && pos_y <= cfBtn.bottom;
            if (backBtnClick) // return choose screen
            {
                sndEffect("click");
                initChooseScr();
            }
            else if (pos_x >= 150 && pos_x <= 580 && pos_y >= 250 && pos_y <= 300)
            {
                sndEffect("click");
                currentCur = 250;
            }
            else if (pos_x >= 150 && pos_x <= 580 && pos_y >= 350 && pos_y <= 400)
            {
                sndEffect("click");
                currentCur = 350;
            }
            else if (cfBtnClick)
            {
                sndEffect("click");
                bool yes = yesNoMessBox();
                if (yes)
                {
                    gAcc.setUsrname(gUsrname);
                    gAcc.setPasswd(gPasswd);
                    account &acc = gAcc;
                    if (signIn(gAcc) == 1)
                    {
                        setbkcolor(9);
                        barWithTxt(0, 630, 600, 700, 3, "Sign in successfully!!", 1, 0);
                        delay(2000);
                        initMngScr(gAcc);
                    }
                    else if (signIn(gAcc) == -1)
                    {
                        setbkcolor(9);
                        barWithTxt(0, 630, 600, 700, 3, "Something went wrong!!", 1, 0);
                        delay(2000);
                        goto begin;
                    }
                    else if (signIn(gAcc) == 0)
                    {
                        setbkcolor(9);
                        barWithTxt(0, 630, 600, 700, 3, "Username/password is incorrect!", 1, 0);
                        delay(2000);
                        goto begin;
                    }
                }
                else
                {
                    goto begin;
                }
            }
        }
    } while (1);
}
void initGuestInfo()
{
    string strName = "", strAge = "", strAddress = "";
    gName = &strName[0], gAge = &strAge[0], gAddress = &strAddress[0];

begin:
    setbkcolor(9);
    cleardevice();
    setfillstyle(1, 15);
    setbkcolor(15);
    setcolor(15);
    rndConnerRect(5, 200, 595, 500, 5);
    floodfill(350, 350, 15);

    button cfBtn(480, 445, 570, 485, LIGHTBLUE, 8);
    cfBtn.setTitle("Confirm", 15, 1);
    cfBtn.display();

    setbkcolor(9);
    setcolor(0);
    barWithTxt(5, 100, 595, 190, 5, "Your information", 1);
    setbkcolor(15);
    barWithTxt(15, 200, 100, 275, 3, "Name: ", 0);
    barWithTxt(15, 275, 100, 350, 3, "Age: ", 0);
    barWithTxt(15, 350, 100, 425, 3, "Address: ", 0);

    button backBtn(15, 700, 75, 730, 15, 8);
    backBtn.setTitle("<<<", 0, 3);
    backBtn.display();

    barWithTxt(175, 200, 595, 200 + 75, 3, gName, 0, 1);
    barWithTxt(175, 275, 595, 275 + 75, 3, gAge, 0, 1);
    barWithTxt(175, 350, 595, 350 + 75, 3, gAddress, 0, 1);

    int currentCur = 200;
    char ch;
    do
    {
        if (!kbhit())
        {
            delay(100);
            if (!kbhit())
            {
                if (currentCur == 200)
                {
                    setcolor(0);
                    line(175 + textwidth(gName), currentCur + 20, 175 + textwidth(gName), currentCur + 55);
                    setcolor(15);
                    delay(50);
                    line(175 + textwidth(gName), currentCur + 20, 175 + textwidth(gName), currentCur + 55);
                    setcolor(0);
                }
                else if (currentCur == 275)
                {
                    setcolor(0);
                    line(175 + textwidth(gAge), currentCur + 20, 175 + textwidth(gAge), currentCur + 55);
                    setcolor(15);
                    delay(50);
                    line(175 + textwidth(gAge), currentCur + 20, 175 + textwidth(gAge), currentCur + 55);
                    setcolor(0);
                }
                else if (currentCur == 350)
                {
                    setcolor(0);
                    line(175 + textwidth(gAddress), currentCur + 20, 175 + textwidth(gAddress), currentCur + 55);
                    setcolor(15);
                    delay(50);
                    line(175 + textwidth(gAddress), currentCur + 20, 175 + textwidth(gAddress), currentCur + 55);
                    setcolor(0);
                }
            }
        }
        if (kbhit())
        {
            ch = getch();
            if (ch != 0)
            {
                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == ' ')
                {
                    if (currentCur == 200)
                    {
                        strName.push_back(ch);
                    }
                    else if (currentCur == 350)
                    {
                        strAddress.push_back(ch);
                    }
                }
                else if (ch == BACKSPACE)
                {
                    if (currentCur == 200 && strName.length() > 0)
                    {
                        strName.pop_back();
                    }
                    else if (currentCur == 350 && strAddress.length() > 0)
                    {
                        strAddress.pop_back();
                    }
                    else if (currentCur == 275 && strAge.length() > 0)
                    {
                        strAge.pop_back();
                    }
                    else if ((currentCur == 200 && strName.length() == 0) || (currentCur == 350 && strAddress.length() == 0) ||
                             (currentCur == 275 && strAge.length() == 0))
                    {
                        sndEffect("error");
                    }
                }
                else if (ch == ENTER || ch == TAB)
                {
                    if (currentCur == 200)
                    {
                        currentCur = 275;
                    }
                    else if (currentCur == 275)
                    {
                        currentCur = 350;
                    }
                    else if (currentCur == 350)
                    {
                        bool yes = yesNoMessBox();
                        if (yes)
                        {
                            initPredictScr();
                        }
                        else
                        {
                            goto begin;
                        }
                    }
                }
                else if (ch >= '0' && ch <= '9')
                {
                    if (currentCur == 275)
                    {
                        strAge.push_back(ch);
                    }
                }
            }
            else
            {
                ch = getch();
                if (ch == DOWN)
                {
                    if (currentCur <= 275)
                    {
                        currentCur += 75;
                    }
                }
                else if (ch == UP)
                {
                    if (currentCur >= 275)
                        currentCur -= 75;
                }
            }
            if (currentCur == 200)
            {
                gName = &strName[0];
                barWithTxt(175, currentCur, 595, currentCur + 75, 3, gName, 0, 1);
            }
            else if (currentCur == 275)
            {
                gAge = &strAge[0];
                barWithTxt(175, currentCur, 595, currentCur + 75, 3, gAge, 0, 1);
            }
            else if (currentCur == 350)
            {
                gAddress = &strAddress[0];
                barWithTxt(175, currentCur, 595, currentCur + 75, 3, gAddress, 0, 1);
            }
        }
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int pos_x, pos_y;
            getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);
            bool backBtnClick = pos_x >= backBtn.left && pos_x <= backBtn.right && pos_y >= backBtn.top && pos_y <= backBtn.bottom;
            bool cfBtnClick = pos_x >= cfBtn.left && pos_x <= cfBtn.right && pos_y >= cfBtn.top && pos_y <= cfBtn.bottom;
            if (backBtnClick)
            {
                sndEffect("click");
                initChooseScr();
            }
            else if (pos_x >= 175 && pos_x <= 595 && pos_y >= 200 && pos_y <= 275)
            {
                sndEffect("click");
                currentCur = 200;
            }
            else if (pos_x >= 175 && pos_x <= 595 && pos_y >= 275 && pos_y <= 350)
            {
                sndEffect("click");
                currentCur = 275;
            }
            else if (pos_x >= 175 && pos_x <= 595 && pos_y >= 350 && pos_y <= 425)
            {
                sndEffect("click");
                currentCur = 350;
            }
            else if (cfBtnClick)
            {
                sndEffect("click");
                bool yes = yesNoMessBox();
                if (yes)
                {
                    initPredictScr();
                }
                else
                {
                    goto begin;
                }
            }
        }
    } while (1);
}
void initPredictScr()
{
    char *symptom[] =
        {
            "Runny Nose",
            "Headache",
            "Tired",
            "Sneeze",
            "Sore throat",
            "Persistent cough",
            "Creepy",
            "Fever",
            "Anosmia",
            "Chest tightness",
            "Shortness of breath"};

    const int omicron[11] = {3, 3, 3, 3, 3, 2, 2, 2, 0, 0, 0}, // max = 21
        delta[11] = {3, 3, 3, 2, 3, 3, 2, 2, 3, 0, 2},         // max = 26
        beforeDelta[11] = {2, 3, 3, 0, 2, 3, 2, 3, 3, 0, 2};   // max = 23

    int usr[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    box boxes[11];

    for (int i = 0; i < 6; i++)
    {
        boxes[i].left = 230 + 50,
        boxes[i].top = 30 + 70 * i + 27 + 100,
        boxes[i].check = 0;
    }
    for (int i = 6; i < 11; i++)
    {
        boxes[i].left = 480 + 50,
        boxes[i].top = 30 + 70 * (i - 6) + 27 + 100,
        boxes[i].check = 0;
    }
    setbkcolor(9);
    cleardevice();
    setfillstyle(1, 9);
    barWithTxt(0, 0, 600, 50, 4, "Diagnosis of covid 19 strain", 1);
    barWithTxt(50, 50, 120, 65, 2, "Name: ", 0);
    barWithTxt(120, 50, 450, 65, 2, gName, 0);
    barWithTxt(420, 50, 500, 65, 2, "Age: ", 2);
    barWithTxt(500, 50, 600, 65, 2, gAge, 0);
    barWithTxt(50, 65, 120, 100, 2, "Address: ", 0);
    barWithTxt(150, 65, 600, 100, 2, gAddress, 0);

    setbkcolor(7);
    setfillstyle(1, 7);
    barWithTxt(50, 100, 550, 130, 1, "Symptoms", 1, 1);
    setcolor(0);
    rectangle(50, 100, 549, 130);

    for (int i = 0; i < 6; i++)
    {
        setbkcolor(7);
        barWithTxt(50, 130 + 70 * i, 275, 200 + 70 * i, 1, *(symptom + i), 1, 1);
        bar(275, 130 + 70 * i, 300, 200 + 70 * i);
        setcolor(0);
        rectangle(50, 130 + 70 * i, 275, 200 + 70 * i);
        rectangle(275, 130 + 70 * i, 300, 200 + 70 * i);
        boxes[i].display();
    }
    for (int i = 6; i < 11; i++)
    {
        setbkcolor(7);
        barWithTxt(300, 130 + 70 * (i - 6), 525, 200 + 70 * (i - 6), 1, *(symptom + i), 1, 1);
        bar(525, 130 + 70 * (i - 6), 550, 200 + 70 * (i - 6));
        setcolor(0);
        rectangle(300, 130 + 70 * (i - 6), 525, 200 + 70 * (i - 6));
        rectangle(525, 130 + 70 * (i - 6), 549, 200 + 70 * (i - 6));
        boxes[i].display();
    }
    int i = 11;
    setbkcolor(7);
    barWithTxt(300, 130 + 70 * (i - 6), 525, 200 + 70 * (i - 6), 1, "", 1, 1);
    bar(525, 130 + 70 * (i - 6), 550, 200 + 70 * (i - 6));
    setcolor(0);
    rectangle(300, 130 + 70 * (i - 6), 525, 200 + 70 * (i - 6));
    rectangle(525, 130 + 70 * (i - 6), 549, 200 + 70 * (i - 6));
    rectangle(50, 100, 550, 550);

    button PrintBtn(515, 700, 575, 730, 7, 8);
    PrintBtn.setTitle("Print", 0, 1);

    button backBtn(15, 700, 75, 730, 7, 8);
    backBtn.setTitle("<<<", 0, 3);

    PrintBtn.display();
    backBtn.display();

    do
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            string txtOmi = "% you have omicron!";
            string txtDel = "% you have delta!";
            string txtBeDel = "% you have before delta!";
            int resOmi = 0, resDel = 0, resBeDel = 0;
            int pos_x, pos_y;
            getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);
            bool PrintBtnClick = pos_x >= PrintBtn.left && pos_x <= PrintBtn.right && pos_y >= PrintBtn.top && pos_y <= PrintBtn.bottom;
            bool backBtnClick = pos_x >= backBtn.left && pos_x <= backBtn.right && pos_y >= backBtn.top && pos_y <= backBtn.bottom;
            if (PrintBtnClick)
            {
                sndEffect("click");
                // hide button for print
                setfillstyle(1, 9);
                bar(15 - 1, 700 - 1, 75 + 1, 730 + 1);
                bar(515 - 1, 700 - 1, 575 + 1, 730 + 1);
                string image = get_current_dir() + "\\Image\\" + string(gName) + ".bmp";
                writeimagefile(image.c_str(), 0, 0, INT_MAX, INT_MAX);
                PrintBtn.display();
                backBtn.display();
            }
            else if (backBtnClick)
            {
                sndEffect("click");
                initGuestInfo();
            }

            for (int i = 0; i < 11; i++)
            {
                bool boxClick = pos_x >= boxes[i].left && pos_x <= boxes[i].left + 15 && pos_y >= boxes[i].top && pos_y <= boxes[i].top + 15;
                if (boxClick)
                {
                    sndEffect("click");
                    boxes[i].check = !boxes[i].check;
                }
                if (boxes[i].check)
                {
                    usr[i] = 1;
                    boxes[i].display();
                }
                else
                {
                    usr[i] = 0;
                    boxes[i].display();
                }
            }
            for (int i = 0; i < 11; i++)
            {
                if (boxes[i].check)
                {
                    resOmi = resOmi + omicron[i] - usr[i];
                    resDel = resDel + delta[i] - usr[i];
                    resBeDel = resBeDel + beforeDelta[i] - usr[i];
                }
                if (resOmi < 0)
                {
                    resOmi = 0;
                }
                else if (resDel < 0)
                {
                    resDel = 0;
                }
                else if (resBeDel < 0)
                {
                    resBeDel = 0;
                }
            }
            resOmi = resOmi * 100 / 18;
            resDel = resDel * 100 / 23;
            resBeDel = resBeDel * 100 / 20;

            ostringstream convert1, convert2, convert3;
            string txtResOmi, txtResDel, txtResBeDel;
            convert1 << resOmi;
            txtResOmi = convert1.str();
            txtOmi = txtResOmi + txtOmi;
            convert2 << resDel;
            txtResDel = convert2.str();
            txtDel = txtResDel + txtDel;
            convert3 << resBeDel;
            txtResBeDel = convert3.str();
            txtBeDel = txtResBeDel + txtBeDel;

            char *chOmi = &txtOmi[0];
            char *chDel = &txtDel[0];
            char *chBeDel = &txtBeDel[0];

            setfillstyle(1, 9);
            setbkcolor(9);
            setcolor(0);
            barWithTxt(160, 551, 590, 600, 3, chOmi, 0, 1);
            barWithTxt(160, 600, 590, 650, 3, chDel, 0, 1);
            barWithTxt(160, 650, 590, 700, 3, chBeDel, 0, 1);
        }
    } while (1);
}
void initMngScr(account acc)
{

    string mngFullname = acc.getName();
    string mngPermission;
    if (acc.getPermission())
    {
        mngPermission = "admin account";
    }
    else
    {
        mngPermission = "normal account";
    }

    string strName = "", strAge = "", strAddress = "";
    char *PName, *PAge, *PAddress;
    PName = &strName[0], PAge = &strAge[0], PAddress = &strAddress[0];
    bool radio1check;
begin:
    setbkcolor(9);
    cleardevice();
    setfillstyle(1, 15);
    setbkcolor(15);
    setcolor(15);
    rndConnerRect(5, 200, 595, 500, 5);
    floodfill(350, 350, 15);

    button cfBtn(480, 445, 570, 485, LIGHTBLUE, 8);
    cfBtn.setTitle("Confirm", 15, 1);
    cfBtn.display();

    setcolor(0);
    setbkcolor(9);
    barWithTxt(20, 10, 500, 50, 2, "Manager name: ", 0);
    barWithTxt(190, 10, 500, 50, 2, &mngFullname[0], 0);
    barWithTxt(20, 50, 500, 90, 2, "Type account:", 0);
    barWithTxt(190, 50, 500, 90, 2, &mngPermission[0], 0);

    barWithTxt(5, 100, 595, 190, 5, "Patient infomation", 1);
    setbkcolor(15);
    barWithTxt(15, 200, 100, 275, 3, "Name: ", 0);
    barWithTxt(15, 275, 100, 350, 3, "Age: ", 0);
    barWithTxt(15, 350, 100, 425, 3, "Address: ", 0);

    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(60, 465, "F0");
    outtextxy(120, 465, "F1");

    button backBtn(15, 700, 75, 730, 15, 8);
    backBtn.setTitle("<<<", 0, 3);
    backBtn.display();

    button listBtn(515, 700, 575, 730, 15, 8);
    listBtn.setTitle("List", 0, 3);
    listBtn.display();

    button AddBtn(515, 650, 575, 680, 15, 8);
    AddBtn.setTitle("Add", 0, 3);
    if (acc.getPermission())
    {
        AddBtn.display();
    }

    // radio button
    circle(100, 475, 8);
    circle(160, 475, 8);

    int currentCur = 200;

    barWithTxt(175, 200, 595, 200 + 75, 3, PName, 0, 1);
    barWithTxt(175, 275, 595, 275 + 75, 3, PAge, 0, 1);
    barWithTxt(175, 350, 595, 350 + 75, 3, PAddress, 0, 1);

    char ch;
    do
    {
        if (!kbhit())
        {
            delay(100);
            if (!kbhit())
            {
                if (currentCur == 200)
                {
                    setcolor(0);
                    line(175 + textwidth(PName), currentCur + 20, 175 + textwidth(PName), currentCur + 55);
                    setcolor(15);
                    delay(50);
                    line(175 + textwidth(PName), currentCur + 20, 175 + textwidth(PName), currentCur + 55);
                    setcolor(0);
                }
                else if (currentCur == 275)
                {
                    setcolor(0);
                    line(175 + textwidth(PAge), currentCur + 20, 175 + textwidth(PAge), currentCur + 55);
                    setcolor(15);
                    delay(50);
                    line(175 + textwidth(PAge), currentCur + 20, 175 + textwidth(PAge), currentCur + 55);
                    setcolor(0);
                }
                else if (currentCur == 350)
                {
                    setcolor(0);
                    line(175 + textwidth(PAddress), currentCur + 20, 175 + textwidth(PAddress), currentCur + 55);
                    setcolor(15);
                    delay(50);
                    line(175 + textwidth(PAddress), currentCur + 20, 175 + textwidth(PAddress), currentCur + 55);
                    setcolor(0);
                }
            }
        }
        if (kbhit())
        {
            ch = getch();
            if (ch != 0)
            {
                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == ' ')
                {
                    if (currentCur == 200)
                    {
                        strName.push_back(ch);
                    }
                    else if (currentCur == 350)
                    {
                        strAddress.push_back(ch);
                    }
                }
                else if (ch == BACKSPACE)
                {
                    if (currentCur == 200 && strName.length() > 0)
                    {
                        strName.pop_back();
                    }
                    else if (currentCur == 350 && strAddress.length() > 0)
                    {
                        strAddress.pop_back();
                    }
                    else if (currentCur == 275 && strAge.length() > 0)
                    {
                        strAge.pop_back();
                    }
                    else if ((currentCur == 200 && strName.length() == 0) || (currentCur == 350 && strAddress.length() == 0) ||
                             (currentCur == 275 && strAge.length() == 0))
                    {
                        sndEffect("error");
                    }
                }
                else if (ch == ENTER || ch == TAB)
                {
                    if (currentCur == 200)
                    {
                        currentCur = 275;
                    }
                    else if (currentCur == 275)
                    {
                        currentCur = 350;
                    }
                    else if (currentCur == 350)
                    {
                        bool yes = yesNoMessBox();
                        if (yes)
                        {
                            bool check = writeData(strName, strAge, strAddress, radio1check);
                            if (check == -1)
                            {
                                setbkcolor(9);
                                barWithTxt(0, 530, 600, 580, 2, "Something went wrong!!", 1);
                                delay(2000);
                            }
                            else if (check == 1)
                            {
                                setbkcolor(9);
                                barWithTxt(0, 530, 600, 580, 2, "Patient information added!!", 1);
                                delay(2000);
                            }

                            goto begin;
                        }
                        else
                        {
                            goto begin;
                        }
                    }
                }
                else if (ch >= '0' && ch <= '9')
                {
                    if (currentCur == 275)
                    {
                        strAge.push_back(ch);
                    }
                }
            }
            else
            {
                ch = getch();
                if (ch == DOWN)
                {
                    if (currentCur <= 275)
                    {
                        currentCur += 75;
                    }
                }
                else if (ch == UP)
                {
                    if (currentCur >= 275)
                        currentCur -= 75;
                }
            }
            if (currentCur == 200)
            {
                PName = &strName[0];
                setcolor(0);
                barWithTxt(175, currentCur, 595, currentCur + 75, 3, PName, 0, 1);
            }
            else if (currentCur == 275)
            {
                PAge = &strAge[0];
                setcolor(0);
                barWithTxt(175, currentCur, 595, currentCur + 75, 3, PAge, 0, 1);
            }
            else if (currentCur == 350)
            {
                PAddress = &strAddress[0];
                setcolor(0);
                barWithTxt(175, currentCur, 595, currentCur + 75, 3, PAddress, 0, 1);
            }
        }
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int pos_x, pos_y;
            getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);
            bool backBtnClick = pos_x >= backBtn.left && pos_x <= backBtn.right && pos_y >= backBtn.top && pos_y <= backBtn.bottom;
            bool cfBtnClick = pos_x >= cfBtn.left && pos_x <= cfBtn.right && pos_y >= cfBtn.top && pos_y <= cfBtn.bottom;
            bool AddBtnClick = pos_x >= AddBtn.left && pos_x <= AddBtn.right && pos_y >= AddBtn.top && pos_y <= AddBtn.bottom;
            bool listBtnclick = pos_x >= listBtn.left && pos_x <= listBtn.right && pos_y >= listBtn.top && pos_y <= listBtn.bottom;
            if (backBtnClick)
            {
                sndEffect("click");
                initMngLoginScr();
            }
            else if (pos_x >= 175 && pos_x <= 595 && pos_y >= 200 && pos_y <= 275)
            {
                sndEffect("click");
                currentCur = 200;
            }
            else if (pos_x >= 175 && pos_x <= 595 && pos_y >= 275 && pos_y <= 350)
            {
                sndEffect("click");
                currentCur = 275;
            }
            else if (pos_x >= 175 && pos_x <= 595 && pos_y >= 350 && pos_y <= 425)
            {
                sndEffect("click");
                currentCur = 350;
            }
            else if (cfBtnClick)
            {
                sndEffect("click");
                bool yes = yesNoMessBox();
                if (yes)
                {
                    bool check = writeData(strName, strAge, strAddress, radio1check);
                    if (check == -1)
                    {
                        setbkcolor(9);
                        barWithTxt(0, 530, 600, 580, 2, "Something went wrong!!", 1);
                        delay(2000);
                    }
                    else if (check == 1)
                    {
                        setbkcolor(9);
                        barWithTxt(0, 530, 600, 580, 2, "Patient information added!!", 1);
                        delay(2000);
                    }

                    goto begin;
                }
                else
                {
                    goto begin;
                }
            }
            else if (AddBtnClick && acc.getPermission())
            {
                initSignUpScr();
            }
            else if (listBtnclick)
            {
                openlist();
            }
            else if (pos_x >= 100 - 8 && pos_x <= 100 + 8 && pos_y >= 475 - 8 && pos_y <= 475 + 8)
            {
                radio1check = true;
                setfillstyle(SOLID_FILL, 15);
                bar(160 - 8, 475 - 8, 160 + 8, 475 + 8);
                bar(100 - 8, 475 - 8, 100 + 8, 475 + 8);
                circle(100, 475, 8);
                circle(100, 475, 6);
                setfillstyle(SOLID_FILL, 0);
                floodfill(100, 475, 0);
                circle(160, 475, 8);
            }
            else if (pos_x >= 160 - 8 && pos_x <= 160 + 8 && pos_y >= 475 - 8 && pos_y <= 475 + 8)
            {
                radio1check = false;
                setfillstyle(SOLID_FILL, 15);
                bar(160 - 8, 475 - 8, 160 + 8, 475 + 8);
                bar(100 - 8, 475 - 8, 100 + 8, 475 + 8);
                circle(100, 475, 8);
                circle(160, 475, 8);
                circle(160, 475, 6);
                setfillstyle(SOLID_FILL, 0);
                floodfill(160, 475, 0);
            }
        }
    } while (1);
}
void initSignUpScr()
{
    char usr[30], pass[30], name[50];

    string strUserName = "";
    string strPassWord = "";
    string strName = "";

    string tempPassWord = "";
    char *chTempPass;

    const int usrCur = 180, passCur = 280, nameCur = 430;
    bool isadmin;

begin:
    copyCharArr(strUserName, name, strUserName.length(), 30);
    copyCharArr(strPassWord, pass, strPassWord.length(), 30);
    copyCharArr(strName, name, strName.length(), 50);
    chTempPass = &tempPassWord[0];

    setbkcolor(9);
    cleardevice();

    setfillstyle(1, 15);
    setbkcolor(15);
    setcolor(15);
    rndConnerRect(5, 100, 595, 650, 5);
    floodfill(350, 350, 15);

    setcolor(0);
    setbkcolor(9);
    barWithTxt(5, 0, 595, 100, 5, "Register", 1);
    setbkcolor(15);
    barWithTxt(5, 100, 595, 150, 4, "Login information", 1);
    barWithTxt(15, 180, 100, 230, 2, "Username: ", 0);
    barWithTxt(15, 280, 100, 330, 2, "Password: ", 0);
    rndConnerRect(150, 180, 580, 230, 5);
    rndConnerRect(150, 280, 580, 330, 5);
    barWithTxt(5, 350, 595, 400, 4, "Login information", 1);
    barWithTxt(15, 430, 100, 480, 2, "Full name: ", 0);
    barWithTxt(15, 530, 100, 580, 2, "Account type: ", 0);
    barWithTxt(200, 530, 320, 580, 2, "admin", 2);
    circle(330, 555, 8);
    barWithTxt(350, 530, 440, 580, 2, "normal", 2);
    circle(450, 555, 8);

    button backBtn(15, 700, 75, 730, 15, 8);
    backBtn.setTitle("<<<", 0, 3);
    backBtn.display();
    button cfBtn(480, 600, 570, 630, LIGHTBLUE, 8);
    cfBtn.setTitle("Confirm", 15, 1);
    cfBtn.display();
    setbkcolor(15);

    setcolor(0);
    barWithTxt(160, 185, 570, 225, 2, &strUserName[0], 0, 1);
    barWithTxt(160, 285, 570, 325, 2, chTempPass, 0, 1);
    barWithTxt(175, 430, 570, 480, 2, &strName[0], 0, 1);

    int currentCur = usrCur;
    char ch;

    do
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int pos_x, pos_y;
            getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);

            bool backBtnClick = pos_x >= backBtn.left && pos_x <= backBtn.right && pos_y >= backBtn.top && pos_y <= backBtn.bottom;
            bool cfBtnClick = pos_x >= cfBtn.left && pos_x <= cfBtn.right && pos_y >= cfBtn.top && pos_y <= cfBtn.bottom;
            bool usrInput = pos_x >= 150 && pos_x <= 580 && pos_y >= 180 && pos_y <= 230;
            bool passInput = pos_x >= 150 && pos_x <= 580 && pos_y >= 280 && pos_y <= 330;
            bool nameInput = pos_x >= 175 && pos_x <= 595 && pos_y >= 430 && pos_y <= 480;
            bool radio1check = pos_x >= 330 - 8 && pos_x <= 330 + 8 && pos_y >= 550 - 8 && pos_y <= 550 + 8;
            bool radio2check = pos_x >= 450 - 8 && pos_x <= 450 + 8 && pos_y >= 550 - 8 && pos_y <= 550 + 8;

            if (backBtnClick)
            {
                initMngScr(gAcc);
            }
            else if (cfBtnClick)
            {
                bool yes = yesNoMessBox();
                if (yes)
                {
                    sndEffect("click");
                    account newAcc(usr, pass, name, isadmin);
                    if (signUp(newAcc) == 1)
                    {
                        setbkcolor(9);
                        setcolor(0);
                        barWithTxt(120, 680, 600, 750, 2, "Register successfully!", 2, 0);
                        delay(2000);
                    }
                    else if (signUp(newAcc) == 0)
                    {
                        setbkcolor(9);
                        setcolor(0);
                        barWithTxt(120, 680, 600, 750, 2, "Username is already exsit. Try another one!", 2, 0);
                        delay(2000);
                    }
                    else if (signUp(newAcc) == -1)
                    {
                        setbkcolor(9);
                        setcolor(0);
                        barWithTxt(120, 680, 600, 750, 2, "Something went wrong!", 2, 0);
                        delay(2000);
                    }
                    goto begin;
                    goto begin;
                }
                else
                {
                    sndEffect("click");
                    goto begin;
                }
            }
            else if (usrInput)
            {
                sndEffect("click");
                currentCur = usrCur;
            }
            else if (passInput)
            {
                sndEffect("click");
                currentCur = passCur;
            }
            else if (nameInput)
            {
                sndEffect("click");
                currentCur = nameCur;
            }
            else if (radio1check)
            {
                sndEffect("click");
                isadmin = true;
                setfillstyle(1, 15);
                bar(330 - 8, 555 - 8, 330 + 8, 555 + 8);
                bar(450 - 8, 555 - 8, 450 + 8, 555 + 8);
                setcolor(0);
                circle(330, 555, 8);
                circle(330, 555, 6);
                setfillstyle(1, 0);
                floodfill(330, 555, 0);
                circle(450, 555, 8);
            }
            else if (radio2check)
            {
                sndEffect("click");
                isadmin = false;
                setfillstyle(1, 15);
                bar(330 - 8, 555 - 8, 330 + 8, 555 + 8);
                bar(450 - 8, 555 - 8, 450 + 8, 555 + 8);
                setcolor(0);
                circle(450, 555, 8);
                circle(450, 555, 6);
                setfillstyle(1, 0);
                floodfill(450, 555, 0);
                circle(330, 555, 8);
            }
        }
        if (!kbhit())
        {
            delay(100);
            if (!kbhit())
            {
                if (currentCur == usrCur)
                {
                    setcolor(0);
                    line(160 + textwidth(&strUserName[0]), currentCur + 10, 160 + textwidth(&strUserName[0]), currentCur + 40);
                    setcolor(15);
                    delay(50);
                    line(160 + textwidth(&strUserName[0]), currentCur + 10, 160 + textwidth(&strUserName[0]), currentCur + 40);
                    setcolor(0);
                }
                else if (currentCur == passCur)
                {
                    setcolor(0);
                    line(160 + textwidth(chTempPass), currentCur + 10, 160 + textwidth(chTempPass), currentCur + 40);
                    setcolor(15);
                    delay(50);
                    line(160 + textwidth(chTempPass), currentCur + 10, 160 + textwidth(chTempPass), currentCur + 40);
                    setcolor(0);
                }
                else if (currentCur == nameCur)
                {
                    setcolor(0);
                    line(175 + textwidth(&strName[0]), currentCur + 10, 175 + textwidth(&strName[0]), currentCur + 40);
                    setcolor(15);
                    delay(50);
                    line(175 + textwidth(&strName[0]), currentCur + 10, 175 + textwidth(&strName[0]), currentCur + 40);
                    setcolor(0);
                }
            }
        }
        if (kbhit())
        {
            ch = getch();
            if (ch == 0)
            {
                ch = getch();
                if (ch == UP)
                {
                    if (currentCur == nameCur)
                    {
                        currentCur = passCur;
                    }
                    else if (currentCur == passCur)
                    {
                        currentCur = usrCur;
                    }
                }
                else if (ch == DOWN)
                {
                    if (currentCur == usrCur)
                    {
                        currentCur = passCur;
                    }
                    else if (currentCur == passCur)
                    {
                        currentCur = nameCur;
                    }
                }
            }
            else if (ch == TAB || ch == ENTER)
            {
                if (currentCur == nameCur)
                {
                    if (yesNoMessBox())
                    {
                        account newAcc(usr, pass, name, isadmin);
                        if (signUp(newAcc) == 1)
                        {
                            setbkcolor(9);
                            setcolor(0);
                            barWithTxt(120, 680, 600, 750, 2, "Register successfully!", 1, 0);
                            delay(2000);
                        }
                        else if (signUp(newAcc) == 0)
                        {
                            setbkcolor(9);
                            setcolor(0);
                            barWithTxt(120, 680, 600, 750, 2, "Username is already exsit!", 1, 0);
                            delay(2000);
                        }
                        else if (signUp(newAcc) == -1)
                        {
                            setbkcolor(9);
                            setcolor(0);
                            barWithTxt(120, 680, 600, 750, 2, "Something went wrong!", 1, 0);
                            delay(2000);
                        }
                        goto begin;
                    }
                    else
                    {
                        goto begin;
                    }
                }
                else if (currentCur == usrCur)
                {
                    currentCur = passCur;
                }
                else if (currentCur == passCur)
                {
                    currentCur = nameCur;
                }
            }
            else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '@' || ch == '.' || ch == ' ')
            {
                if (currentCur == usrCur && ch != ' ')
                {
                    strUserName.push_back(ch);
                }
                else if (currentCur == passCur && ch != ' ')
                {
                    strPassWord.push_back(ch);
                    tempPassWord.push_back('*');
                }
                if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == ' ')
                {
                    if (currentCur == nameCur)
                    {
                        strName.push_back(ch);
                    }
                }
            }
            else if (ch == BACKSPACE)
            {
                if (currentCur == usrCur && strUserName.length() > 0)
                {
                    strUserName.pop_back();
                }
                else if (currentCur == passCur && tempPassWord.length() > 0)
                {
                    strPassWord.pop_back();
                    tempPassWord.pop_back();
                }
                else if (currentCur == nameCur && strName.length() > 0)
                {
                    strName.pop_back();
                }
                else if ((currentCur == usrCur && strUserName.length() == 0) || (currentCur == passCur && strPassWord.length() == 0) || (currentCur == nameCur && strName.length() == 0))
                {
                    sndEffect("error");
                }
            }
            if (currentCur == usrCur)
            {
                copyCharArr(strUserName, usr, strUserName.length(), 30);
                setcolor(0);
                setfillstyle(1, 15);
                barWithTxt(160, 185, 570, 225, 2, &strUserName[0], 0, 1);
            }
            else if (currentCur == passCur)
            {
                copyCharArr(strPassWord, pass, strPassWord.length(), 30);
                chTempPass = &tempPassWord[0];
                setcolor(0);
                setfillstyle(1, 15);
                barWithTxt(160, 285, 570, 325, 2, chTempPass, 0, 1);
            }
            else if (currentCur == nameCur)
            {
                copyCharArr(strName, name, strName.length(), 50);
                setcolor(0);
                setfillstyle(1, 15);
                barWithTxt(175, 430, 570, 480, 2, &strName[0], 0, 1);
            }
        }
    } while (1);
}
void showAlertScr()
{
    setbkcolor(9);
    cleardevice();
    setcolor(0);
    barWithTxt(0, 300, 600, 350, 3, "Please turn off Vietnamese typing mode", 1);
    delay(3000);
}
void sndEffect(char *sound)
{
    string nameSnd;
    if (sound == "error")
    {
        nameSnd = "error_1.wav";
    }
    else if (sound == "click")
    {
        nameSnd = "mouse_click.wav";
    }
    else if (sound == "hold")
    {
        nameSnd = "moving_1.wav";
    }
    else
    {
        nameSnd = "systemSnd";
    }
    string dir = get_current_dir() + "\\Sound\\" + nameSnd;
    wstring wdir(dir.begin(), dir.end());
    const wchar_t *snd = wdir.c_str();

    PlaySoundW(snd, NULL, SND_ASYNC);
}
bool yesNoMessBox()
{
    char ch;
    bool yes = true;
    bool holding;
    putimage(100, 300, yesMessageBox, COPY_PUT);
    do
    {
        // getxy();
        if (ismouseclick(WM_MOUSEMOVE))
        {
            int pos_x, pos_y;
            getmouseclick(WM_MOUSEMOVE, pos_x, pos_y);
            if (pos_x >= 166 && pos_x <= 232 && pos_y >= 362 && pos_y <= 387 && holding == 0)
            {
                sndEffect("hold");
                holding = 1;
                yes = 1;
            }
            else if (pos_x >= 367 && pos_x <= 431 && pos_y >= 362 && pos_y <= 387 && holding == 0)
            {
                sndEffect("hold");
                holding = 1;
                yes = 0;
            }
            else if (pos_x < 166 || (pos_x > 232 && pos_x < 367) || pos_x > 431 || pos_y < 362 || pos_y > 378)
            {
                holding = 0;
            }
        }
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            sndEffect("click");
            int pos_x, pos_y;
            getmouseclick(WM_LBUTTONDOWN, pos_x, pos_y);
            if (pos_x >= 166 && pos_x <= 232 && pos_y >= 362 && pos_y <= 387)
            {
                return true;
            }
            else if (pos_x >= 367 && pos_x <= 431 && pos_y >= 362 && pos_y <= 387)
            {
                return false;
            }
        }
        if (kbhit())
        {
            ch = getch();
            if (ch == 0)
            {
                ch = getch();
                if (ch == LEFT && yes == 0)
                {
                    yes = 1;
                }
                else if (ch == RIGHT && yes == 1)
                {
                    yes = 0;
                }
            }
            else if (ch == ENTER)
            {
                if (yes)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        if (yes == 1)
        {
            putimage(100, 300, yesMessageBox, COPY_PUT);
        }
        else
        {
            putimage(100, 300, noMessageBox, COPY_PUT);
        }
    } while (1);
}
