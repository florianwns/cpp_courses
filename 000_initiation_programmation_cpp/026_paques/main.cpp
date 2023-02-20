//
// Created by Florian Rey on 20/02/2023.
//
#include <iostream>

using namespace std;

int demander_annee();

void affiche_date(int annee, int nb_jours);

int date_Paques(int annee);


int main() {
    int annee(demander_annee());
    int nb_jours(date_Paques(annee));
    affiche_date(annee, nb_jours);
    return 0;
}

int demander_annee() {
    int annee(0);
    do {
        cout << "Entrez une annee (1583-4000) : ";
        cin >> annee;
    } while (annee < 1583 or annee > 4000);
    return annee;
}

void affiche_date(int annee, int nb_jours) {
    cout << "Date de Paques en " << annee << " : ";
    if (nb_jours <= 31) {
        cout << nb_jours << " mars" << endl;
    } else {
        nb_jours -= 31;
        cout << nb_jours << " avril" << endl;
    }
}

int date_Paques(int annee) {
    const int siecle = annee / 100;
    const int p = (13 + 8 * siecle) / 25;
    const int q = siecle / 4;
    const int M = (15 - p + siecle - q) % 30;
    const int N = (4 + siecle - q) % 7;
    const int d = (M + 19 * (annee % 19)) % 30;
    const int e = (2 * (annee % 4) + 4 * (annee % 7) + 6 * d + N) % 7;
    int jour = e + d + 22;
    if (e == 6 and (d == 29 or (d == 28 and 11 * (M + 1) % 30 < 19))) {
        jour -= 7;
    }
    return jour;
}
