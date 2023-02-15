//
// Created by Florian Rey on 15/02/2023.
//

#include <iostream>
#include <random>

using namespace std;


int random(int min = 0, int max = 255) {
    random_device dev;
    mt19937 range(dev());
    uniform_int_distribution<mt19937::result_type> dist(min, max);
    return dist(range);
}

int main() {
    int min(0), max(255),
            number_to_find(random(0, 255)),
            num_attempts(0),
            user_answer;
    bool is_invalid;

    cout << "Find a number between "
         << min << " and " << max
         << endl;

    do {
        cout << "? ";
        cin >> user_answer;
        is_invalid = number_to_find != user_answer;
        if (is_invalid) {
            cout << ">> Too "
                 << ((user_answer > number_to_find) ? "High" : "Low")
                 << " <<" << endl;
        }
        ++num_attempts;
    } while (is_invalid);

    cout << ">>> Bravo, you find the number in "
         << num_attempts
         << " attempts <<< " << endl;

    return 0;
}
