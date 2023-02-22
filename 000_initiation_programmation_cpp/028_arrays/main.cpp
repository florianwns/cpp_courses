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

    // Ajoute une element
    ages.push_back(123);
    //retire un element
    ages.pop_back();

    // calcul de la moyenne
    double sum(0.0);
    for (size_t i(0); i < ages.size(); ++i) {
        sum += ages[i];
    }
    const double avg(sum / ages.size());

    cout << "la moyenne d'age est de : " << avg << endl;

    // Ajoute une element
    cout << "Premier élément : " << ages.front() << endl;
    cout << "Dernier élément : " << ages.back() << endl;
    cout << "Est vide : " << ages.empty() << endl;

    // Supprime tous les éléments
    ages.clear();

    return 0;
}
