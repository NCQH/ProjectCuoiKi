#include "account.h"

account::account()
{
}
account::account(char username[30], char password[30])
{
    copyCharArr(username, this->username, 30);
    copyCharArr(password, this->password, 30);
}
account::account(char username[30], char password[30], char fullname[50], bool isadmin)
{
    copyCharArr(username, this->username, 30);
    copyCharArr(password, this->password, 30);
    copyCharArr(fullname, this->fullname, 50);
    this->isadmin = isadmin;
}
void account::signInInfo(char username[30], char password[30])
{
    copyCharArr(username, this->username, 30);
    copyCharArr(password, this->password, 30);
}
string account::getUsrname()
{
    return string(username);
}
string account::getPasswd()
{
    return string(password);
}
string account::getName()
{
    return string(fullname);
}
bool account::getPermission()
{
    return isadmin;
}
void account::setUsrname(char username[30])
{
    copyCharArr(username, this->username, 30);
}
void account::setPasswd(char password[30])
{
    copyCharArr(password, this->password, 30);
}
void account::setPermission(bool isadmin)
{
    this->isadmin = isadmin;
}
void account::setFullname(string name)
{
    copyCharArr(name, fullname, name.length(), 50);
}
account::~account()
{
}
