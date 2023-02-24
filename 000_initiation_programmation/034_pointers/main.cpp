//
// Created by Florian Rey on 23/02/2023.
//
#include <iostream>
#include <memory>

using namespace std;

unique_ptr<double> f(double val) {
    return unique_ptr<double>(new double(val));
}

int main() {
    // Allocation statique, désallouée automatiquement en dehors de la portée
    {
        int x(5);
        int &y(x);

        y = 6;

        int *px(&x);

        cout << "x : " << x << endl;
        cout << "y : " << y << endl;
        cout << "*px : " << *px << endl;
        cout << "px : " << px << endl;
        cout << "&x : " << &x << endl;
        cout << "*&x : " << *&x << endl;
    }


    // Allocation dynamique, à désaouller manuellement
    {
        int *pi(new int(5));

        int *pj(new int);
        *pj = 123;

        cout << "pi : " << pi << endl;
        cout << "*pi : " << *pi << endl;

        cout << "pj : " << pj << endl;

        delete pi; // désalloue manuellement la zone mémoire pointée par pi
        cout << "after deletion : *pi : " << *pi << endl;
        *pi = 10;
        cout << "after modification : *pi : " << *pi << endl;
        pi = nullptr; // met le pointeur à nullptr;

        delete pi; // pas d'erreur mais inutile
    }


    // ========= Smart Pointers => Garbage Collector =========

    // unique_ptr
    {
        // un seul pointeur pour une mémoire allouée. protection de la mémoire. ne peut pas être copié.
        unique_ptr<int> pw(new int(5));
        // unique_ptr<int> pw2(pw); // ==> l'affection ne marche pas ici
        cout << *pw << endl;
        pw.reset();

        unique_ptr<double> pd(new double(6));
        cout << *pd << endl;
        pd = unique_ptr<double>(new double(10));
        cout << *pd << endl;
        pd = f(11);  // unique_ptr utilise la move_semantic pour le retour de fontion, ou la copie
        cout << *pd << endl;
        // pd = pw; // la copie est ici interdit
    }

    return 0;
}