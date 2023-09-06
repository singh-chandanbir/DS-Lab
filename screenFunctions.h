#ifndef SCREEN_FUNCTION_H
#define SCREEN_FUNCTION_H

#include<iostream>
// #include<conio.h>
#include<cstdlib>

using namespace std;

void clearScreen(){
    // system("cls");
    system("clear");
}

void  holdScreen(){
    cout << endl <<"Press any key to continue...";
    // getch();
    system("pause");

}

#endif