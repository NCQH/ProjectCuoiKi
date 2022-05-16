#include "backend.h"

extern const string ACCOUNT = get_current_dir() + "\\Data\\account.dat";
extern const string PEOPLE = get_current_dir() + "\\Data\\people.csv";

using namespace std;

int signUp(account &acc)
{
    ifstream rf(ACCOUNT, ios::binary);
    if (!rf)
    {
        return -1;
    }
    rf.seekg(0, ios::end);
    int filesize = rf.tellg();
    rf.seekg(0, ios::beg);

    if (filesize > 0)
    {
        int numberAcc = filesize / sizeof(account);
        account *accs = new account[numberAcc];

        for (int i = 0; i < numberAcc; i++)
        {
            rf.read((char *)&accs[i], sizeof(account));
            if (!rf.good())
            {
                rf.close();
                return -1;
            }
        }
        for (int i = 0; i < numberAcc; i++)
        {
            if (acc.getUsrname() == accs[i].getUsrname())
            {
                rf.close();
                return 0;
            }
        }
    }
    rf.close();
    ofstream wf(ACCOUNT, ios::binary | ios::app);
    if (!wf)
    {
        return -1;
    }

    wf.write((char *)&acc, sizeof(account));

    wf.close();
    if (!wf.good())
    {
        return -1;
    }
    return 1;
}
int signIn(account &acc)
{
    ifstream rf(ACCOUNT, ios::binary);
    if (!rf)
    {
        return -1;
    }
    rf.seekg(0, ios::end);
    int filesize = rf.tellg();
    rf.seekg(0, ios::beg);

    if (filesize > 0)
    {
        int numberAcc = filesize / sizeof(account);
        account *accs = new account[numberAcc];

        for (int i = 0; i < numberAcc; i++)
        {
            rf.read((char *)&accs[i], sizeof(account));
            if (!rf.good())
            {
                rf.close();
                return -1;
            }
        }
        for (int i = 0; i < numberAcc; i++)
        {
            if (acc.getUsrname() == accs[i].getUsrname())
            {
                if (acc.getPasswd() == accs[i].getPasswd())
                {
                    acc.setFullname(accs[i].getName());
                    acc.setPermission(accs[i].getPermission());
                    rf.close();
                    return 1;
                }
            }
        }

        delete[] accs;
        rf.close();
        return 0;
    }
    else
    {
        char usr[30] = "admin", pass[30] = "1", name[50] = "ADMIN";
        account acc(usr, pass, name, 1);
        signUp(acc);
        
        return -1;
    }
}
int writeData(string name, string age, string address, bool isF0)
{
    ofstream wf(PEOPLE, ios::app);
    if (!wf)
    {
        return -1;
    }
    wf.seekp(0, ios::end);
    int filesize = wf.tellp();

    if (filesize <= 1)
    {
        wf << "Full name" << ',' << "Age" << ',' << "Address" << ',' << "Status" << endl;
    }
    wf << name << ',' << age << ',' << address << ',' << ((isF0) ? "F0" : "F1") << endl;
    wf.close();
    if (!wf.good())
    {
        return -1;
    }
    return 1;
}
void openlist()
{
    string run = "C:\\Program Files (x86)\\Microsoft Office\\root\\Office16\\EXCEL.EXE " + PEOPLE;
    WinExec(run.c_str(), 1);
}
