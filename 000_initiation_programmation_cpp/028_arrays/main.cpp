//
// Created by Florian REY on 22/02/2023.
//

#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int> ages(5);

    for (auto &age : ages) {
        do {
            cout << "Age de l'étudiant : ";
            cin >> age;
        } while (age <= 0);
    }

    // calcul de la moyenne
    double sum(0.0);
    for (size_t i(0); i < ages.size(); ++i) {
        sum += ages[i];
    }
    const double avg(sum / ages.size());

    cout << "la moyenne d'age est de : " << avg << endl;

    return 0;
}
