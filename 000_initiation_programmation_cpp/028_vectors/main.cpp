//
// Created by Florian REY on 22/02/2023.
//

#include <iostream>
#include <vector>

using namespace std;

void fill(vector<int> &vec, size_t size = 4);

int main() {
    vector<int> ages(5);
    fill(ages, ages.size());

    // Ajoute une element
    ages.push_back(123);
    // Retire un element
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


void fill(vector<int> &vec, size_t size) {
    // Vide le vecteur
    vec.clear();

    cout << "Saisie de " << size << " valeurs " << endl;
    while (vec.size() < size) {
        cout << "Age de l'étudiant n°" << vec.size() + 1 << " : ";
        int age;
        cin >> age;
        if (age < 0 and not vec.empty()) {
            vec.pop_back();
        } else if (age == 0) {
            vec.clear();
        } else if (age > 0) {
            vec.push_back(age);
        }
    }
}
