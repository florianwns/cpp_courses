//
// Created by Florian Rey on 15/02/2023.
//

#include <iostream>

using namespace std;

int main() {
    double note, sum(0.);
    int num_notes;
    bool is_invalid;

    do {
        cout << "Entrez le nombre de notes : ";
        cin >> num_notes;
        is_invalid = num_notes <= 0;
        if(is_invalid){
            cout << "Le nombre de notes doit être positif" << endl;
        }
    } while (is_invalid);

    for (int i(1); i <= num_notes; ++i) {
        cout << "Entrez la note n° " << i << " : ";
        cin >> note;
        sum += note;
    }

    cout << "Average : " << sum / num_notes << endl;

    return 0;
}