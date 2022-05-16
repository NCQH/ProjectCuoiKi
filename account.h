#if !defined(_ACCOUNT_H_)
#define _ACCOUNT_H_

#include "prjHeader.h"
using namespace std;
class account
{
private:
    char username[30];
    char password[30];
    char fullname[50];
    bool isadmin;
public:
    account();
    account(char username[30], char password[30]);
    account(char username[30], char password[30], char fullname[50], bool isadmin);

    void signInInfo(char username[30], char password[30]);
    string getUsrname();
    string getPasswd();
    string getName();
    void setUsrname(char username[30]);
    void setPasswd(char password[30]);
    bool getPermission();
    void setFullname(string fullname);
    void setPermission(bool permission);
    
    ~account();
};
#endif // _ACCOUNT_H_
