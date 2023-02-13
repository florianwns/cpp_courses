//
// Created by Florian Rey on 13/02/2023.
//

#include <iostream>

using namespace std;

int main() {
    if (-1 and 5) { // OK
        cout << "the expression '(-1 and 5)' returns  " << (-1 and 5) << endl;
    }
    int a(5), b(7);
    cout << "(a = b) returns " << (a = b) << endl;

    // Becareful here c++ is different than python
    cout << "(0 <= a <= 2) returns " << (0 <= a <= 2) << endl;
    cout << "((0 <= a) <= 2) returns " << ((0 <= a) <= 2) << endl;

    cout << "not(7) returns " << not(7) << endl;
    cout << "not(0) returns " << not(0) << endl;

    return 0;
}
