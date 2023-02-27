//
// Created by Florian Rey on 27/02/2023.
//
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    std::cout << "मस्ते שָׁלוֹם" << std::endl;
    cout << "\342\230\272" << endl;
    vector<string> specialchars{"😁", "🔍", "🦑", "😁"};
    for (const auto &f : specialchars) {
        cout << f << endl;
    }
}