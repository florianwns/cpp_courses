//
// Created by Florian Rey on 23/02/2023.
//
#include <iostream>

using namespace std;


int main(){
    int x(5);
    int& y(x);

    y = 6;

    int* px(&x);

    cout << "x : " << x << endl;
    cout << "y : " << y << endl;
    cout << "*px : " << *px << endl;
    cout << "px : " << px << endl;
    cout << "&x : " << &x << endl;
    cout << "*&x : " << *&x << endl;


    return 0;
}