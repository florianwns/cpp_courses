//
// Created by Florian Rey on 13/02/2023.
//

#include <iostream>
#include <ctime>

using namespace std;

int main() {
    int age;

    cout << "Tell me your age : ";
    cin >> age;

    const std::time_t now = time(nullptr);
    int current_year(gmtime(&now)->tm_year + 1900);

    int birth_year = current_year - age;

    cout << "You were born in " << birth_year << endl;
    return 0;
}