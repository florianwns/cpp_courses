//
// Created by Florian Rey on 24/02/2023.
//
#include <iostream>
using namespace std;

int main() {
    auto avg = [](auto x, auto y) { return 0.5 * (x + y); };
    cout << "avg(3,50) = " << avg(3.654, 50) << endl;
    return 0;
}