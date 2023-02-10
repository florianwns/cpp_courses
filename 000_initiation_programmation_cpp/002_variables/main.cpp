//
// Created by Florian Rey on 10/02/2023.
//
#include <iostream>

using namespace std;

int main() {
    int l(4), m(2);
    const double n(1.0);

    l += 4;

    cout << l << " | type " << typeid(l).name() << " | size " << sizeof(l) << endl;
    cout << m << " | type " << typeid(m).name() << " | size " << sizeof(m) << endl;
    cout << n << " | type " << typeid(n).name() << " | size " << sizeof(n) << endl;
    return 0;
}