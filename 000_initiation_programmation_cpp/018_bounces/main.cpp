//
// Created by Florian Rey on 15/02/2023.
//

#include <iostream>
#include <cmath>

using namespace std;


int main() {
    constexpr double gravity(9.81);
    double speed, height, final_height, bounce_factor;
    int num_bounce;

    do{
        cout << "Initial Height : ";
        cin >> height;
    } while(height <= 0.);

    do{
        cout << "Bounce factor: ";
        cin >> bounce_factor;
    } while(bounce_factor <= 0. or bounce_factor >= 1.);

    do{
        cout << "Number of bounces : ";
        cin >> num_bounce;
    } while(num_bounce < 0);

    speed = sqrt(2. * height * gravity);
    for(int(i) = 0; i < num_bounce; ++i){
        speed *= bounce_factor;
    }
    final_height = speed * speed / (2 * gravity);
    cout << "Final height after " << num_bounce
         << " bounces : " << final_height
         << endl;

    return 0;
}
