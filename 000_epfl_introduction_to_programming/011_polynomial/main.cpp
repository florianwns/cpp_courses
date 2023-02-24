//
// Created by Florian Rey on 13/02/2023.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a(0.), b(0.), c(0.);

    cout << "Enter a value for 'a' : ";
    cin >> a;
    if (a == 0.) {
        cerr << "Error : 'a' cannot be equal to 0.0 :-(" << endl;
        return 1;
    }

    cout << "Enter a value for 'b' : ";
    cin >> b;
    cout << "Enter a value for 'c' : ";
    cin >> c;

    const double delta(b * b - 4 * a * c);

    if (delta < 0.) {
        cout << "There is no real solutions." << endl;
    } else if (delta > 0.) {
        cout << "There are two solutions : "
             << (-b - sqrt(delta)) / (2. * a)
             << ' and '
             << (-b + sqrt(delta)) / (2. * a)
             << endl;
    } else {
        cout << "One solution : " << -b / (2. * a) << endl;
    }

    return 0;
}
