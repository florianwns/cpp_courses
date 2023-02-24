//
// Created by Florian REY on 22/02/2023.
//

#include <iostream>
#include <vector>

using namespace std;

char decale(char c, const char debut, int decalage);

char code(char c, const int d);

string code(string s, const int d);

string decode(string s, const int d);


int main() {
    {
        string secret("Fuyez manants");

        vector<int> decalages = {4, 6, -4};

        for (auto d: decalages) {
            cout << code(secret, d) << " : " << decode(code(secret, d), d) << endl;
        }
    }

    {
        string secret("Avez-vous vu mes 3 chats et mes 2 chiens ?");

        vector<int> decalages = {4};

        for (auto d: decalages) {
            cout << code(secret, d) << " : " << decode(code(secret, d), d) << endl;
        }
    }
    return 0;
}

char decale(char c, char debut, int decalage) {
    while (decalage < 0) {
        decalage += 26;
    }
    return debut + (((c - debut) + decalage) % 26);
}


char code(char c, int d) {
    if (c >= 'a' and c <= 'z') {
        return decale(c, 'a', d);
    }
    if (c >= 'A' and c <= 'Z') {
        return decale(c, 'A', d);
    }
    return c;
}


string code(string s, const int d) {
    for (auto &c : s) {
        c = code(c, d);
    }
    return s;
}

string decode(string s, const int d) {
    return code(s, -d);
}