//
// Created by Florian Rey on 15/02/2023.
//

#include <iostream>
#include <cmath>

using namespace std;


int main() {

    double speed, height, last_height, bounce_factor, gravity(9.81);
    int num_bounce;

    cout << "Initial Height : ";
    cin >> height;

    cout << "Bounce factor: ";
    cin >> bounce_factor;

    cout << "Number of bounces : ";
    cin >> num_bounce;

    speed = sqrt(2 * height * gravity);
    for(int(i) = 0; i < num_bounce; ++i){
        speed *= bounce_factor;
    }
    last_height = speed * speed / (2 * gravity);
    cout << "Last height after " << num_bounce
         << " bounces : " << last_height
         << endl;

    return 0;
}
