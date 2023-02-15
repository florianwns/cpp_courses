//
// Created by Florian Rey on 15/02/2023.
//

#include <iostream>

using namespace std;

int main() {
    int num;
    do {
        cout << "Give me a number : ";
        cin >> num;
    } while (num <= 0);

    // Print the triangle
    for (int i(num - 1), j(1); i >= 0; --i, j += 2) {
        cout << string(i, ' ')
             << string(j, '*')
             << string(i, ' ')
             << endl;
    }

    return 0;
}