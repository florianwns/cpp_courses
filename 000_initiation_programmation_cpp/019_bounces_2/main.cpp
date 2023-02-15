//
// Created by Florian Rey on 15/02/2023.
//

#include <iostream>
#include <cmath>

using namespace std;


int main() {
    // Ask for values -----------------------------------------
    double height;
    do {
        cout << "Initial Height : ";
        cin >> height;
    } while (height <= 0.);

    double limit_height;
    do {
        cout << "Limit Height : ";
        cin >> limit_height;
    } while (limit_height <= 0. or limit_height >= height);

    double bounce_factor;
    do {
        cout << "Bounce factor: ";
        cin >> bounce_factor;
    } while (bounce_factor <= 0. or bounce_factor >= 1.);

    // Variable declaration -----------------------------------
    constexpr double gravity(9.81);
    double speed(sqrt(2 * height * gravity)),
            final_height;
    int num_bounce(0);

    // Computing loop -----------------------------------------
    do {
        speed *= bounce_factor;
        final_height = speed * speed / (2 * gravity);
        num_bounce++;
    } while (final_height > limit_height);

    // Display results ----------------------------------------
    cout << "Final height : " << final_height << endl
         << "After " << num_bounce << " bounces" << endl;

    return 0;
}
