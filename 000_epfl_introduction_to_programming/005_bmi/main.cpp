//
// Created by Florian Rey on 13/02/2023.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double weight, size;

    cout << "Enter a weight (in Kg) : ";
    cin >> weight;

    cout << "Enter a size (in m) : ";
    cin >> size;

    double bmi(weight / (size * size));

    cout << "For "      << weight
         << " kg et "   << size
         << " m, the BMI (body mass index) is " << bmi
         << endl;

    return 0;
}