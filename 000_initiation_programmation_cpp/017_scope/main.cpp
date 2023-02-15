//
// Created by Florian Rey on 15/02/2023.
//

#include <iostream>

using namespace std;


int main() {
    // Don't do that
    int j(123);
    cout << "j is " << j << endl;
    {
        int j(321);
        cout << "j is " << j << endl;
    }
    j += 100;
    cout << "j is " << j << endl;

    return 0;
}
