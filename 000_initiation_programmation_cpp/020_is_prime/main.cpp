//
// Created by Florian Rey on 15/02/2023.
//

#include <iostream>
#include <cmath>

using namespace std;


int main() {
    // Ask for a number
    int n;
    bool is_prime(true);
    int divider(1);

    do {
        cout << "Give a number : ";
        cin >> n;
    } while (n <= 1);

    if (n % 2 == 0) {
        if (n != 2) {
            is_prime = false;
            divider = 2;
        }
    } else {
        const int div_max(sqrt(n));

        for (int i(3); is_prime and i <= div_max; i += 2) {
            if (n % i == 0) {
                is_prime = false;
                divider = i;
            }
        }
    }

    if (is_prime) {
        cout << n << " is prime" << endl;
    } else {
        cout << n << " is not prime, because it can be divided by "
             << divider << endl;
    }
    
    return 0;
}
