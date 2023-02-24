//
// Created by Florian Rey on 15/02/2023.
//

#include <iostream>

using namespace std;


int main() {
    // Don't do that
    int j(123);
    cout << "j : " << j << endl;
    {
        int j(321);
        cout << "j : " << j << endl;
    }
    j += 100;
    cout << "j : " << j << endl;

    // To avoid confusion, don't use variables with same names
    // in different blocs of instructions
    int i(654);
    for(int i(0); i < 2; ++i){
        cout << "i : " << i << endl;
    }
    cout << "i : " << i << endl;
    return 0;
}
