//
// Created by Florian Rey on 13/02/2023.
//

#include <iostream>
#include <cmath>

using namespace std;

string nan_to_undefined(double x, double (*f)(double)) {
    const double res = f(x);
    return isnan(res) ? "Undefined" : to_string(res);
}

int main() {
    double x(0.);

    cout << "Enter a value for 'x' : ";
    cin >> x;

    cout << nan_to_undefined(x, [](double x) {
        return x / (1 - exp(x));
    }) << endl;

    cout << nan_to_undefined(x, [](double x) {
        return x * log(x) * exp(2 / (x - 1));
    }) << endl;

    cout << nan_to_undefined(x, [](double x) {
        return (-x - sqrt(x * x - 8 * x)) / (2 - x);
    }) << endl;

    cout << nan_to_undefined(x, [](double x) {
        return sqrt((sin(x) - x / 20) * log(x * x - (1 / x)));
    }) << endl;

    return 0;
}
