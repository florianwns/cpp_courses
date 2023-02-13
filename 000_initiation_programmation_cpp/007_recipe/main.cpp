//
// Created by Florian Rey on 13/02/2023.
//

#include <iostream>

using namespace std;

int main() {
    const int BASE(4);
    const double cheese(800.),
                 water(2.),
                 garlic(2.),
                 bread(400.);

    int num_guests;
    cout << "How many guests have you invited ? ";
    cin >> num_guests;

    cout << "To make the 'fondue fribourgeoise' recipe, you need : " << endl
            << "- " << (cheese * num_guests / BASE) << " gr of cheese" << endl
            << "- " << (water * num_guests / BASE) << " dl of water" << endl
            << "- " << (garlic * num_guests / BASE) << " pieces of garlic" << endl
            << "- " << (bread * num_guests / BASE) << " gr of bread" << endl
            << "- lot of pepper ;)" << endl;
    return 0;
}
3