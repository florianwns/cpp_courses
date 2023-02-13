//
// Created by Florian Rey on 13/02/2023.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a(1.);
    const double b(1.2e3);

    cout << b << endl;

    cout << "1 / 2 = " << 1 / 2 << endl;
    cout << "3 / 2 = " << 3 / 2 << endl;
    cout << "1.0 / 2.0 = " << 1.0 / 2.0 << endl;
    cout << "1 / 2.0 = " << 1 / 2.0 << endl;

    int w(0);
    w += 5;     // 5
    w--;        // 4
    w /= 2;     // 2
    w *= 3;     // 6
    w %= 5;     // 1
    cout << "w = " << w << endl;

    int y(10);
    cout << "y = 10" << endl;
    cout << "--y = " << --y << endl;
    cout << "y-- = " << y-- << endl;
    cout << "y = " << y << endl;

    // Becareful if you try to divide int by int, here z equals 0;
    double z = 1 / 2;
    cout << z << endl;

    // % operator for double does no exists.
    // Instead use <cmath>
    //
    // 'remainder' uses round-to-nearest, and 'fmod' uses simple truncate.
    cout << "6.3489 % 6 = " << fmod(6.3489, 6) << endl;
    cout << "6.3489 % 6 = " << remainder(6.3489, 6) << endl;

    cout << pow(2.1, 2.1) << endl;
    cout << "M_PI = " << M_PI  << endl;
    cout << "M_E = " << M_E  << endl;


    // https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
    const uint8_t k(354);
    cout << "uint8_t(354) = " << (int)k << endl;
}