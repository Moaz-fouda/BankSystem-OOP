#include <iostream>
#include"clsLogin.h"

int main()

{
    while (true) {
        if (!clsLogin::ShowLoginScreen())
            break;
       
    }

    system("pause>0");
    return 0;
}