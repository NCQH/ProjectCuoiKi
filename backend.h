#if !defined(_BACKEND_H_)
#define _BACKEND_H_

#include "prjHeader.h"

int signUp(account &acc);
int signIn(account &acc);

int writeData(string name, string age, string address, bool isF0);
void openlist();
#endif // _BACKEND_H_
