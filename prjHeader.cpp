#include "prjHeader.h"

// Set current diretory, lay duong dan hien tai
string get_current_dir()
{
    char buff[FILENAME_MAX];
    getcwd(buff, FILENAME_MAX);
    string current_working_dir(buff);
    return current_working_dir;
}
void copyCharArr(char exsitArr[], char newArr[], int n)
{    
    for (int i = 0; i < n; i++)
    {
        newArr[i] = exsitArr[i];
    }
}
void copyCharArr(string exsitStr, char newArr[], int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        newArr[i] = '\00';
    }
    for (int i = 0; i < n; i++)
    {
        newArr[i] = exsitStr[i];
    }
}
