//
// Created by Florian Rey on 27/02/2023.
//
#include <iostream>

using namespace std;

int main() {

    cout << "Quel âge as-tu ?";

    unsigned int age{0};
    if (cin >> age) {
        if (age < 5u) {
            cout << "Tu es très jeune" << endl;
        } else if (age < 18u) {
            cout << "Bientôt la majorité" << endl;
        } else {
            cout << "Salut bonhomme !" << endl;
        }
    }

    return 0;
}