//
// Created by Florian REY on 22/02/2023.
//

#include <iostream>
#include <array>
#include <vector>

using namespace std;


struct Date {
    int day;
    int month;
    int year;
};

struct Student {
    string name;
    double average;
};

struct Particule {
    array<double, 3> position;
    array<double, 3> speed;
    double mass;
};


int main() {

    Date now = {22, 22, 2023};

    Date yesterday = now;
    yesterday.day--;

    // or
    yesterday = {now.day - 1, now.month, now.year};

    cout << now.day << endl;
    cout << yesterday.day << endl;

    // use struc inside vector
    vector<Date> dates = {
            {22, 22, 2023},
            {21, 22, 2023},
            now,
    };
    cout << dates[0].year << endl;


    // with C arrays
    Date date_range[2] = {yesterday, now};
    cout << date_range[0].year << endl;

    // or
    Date date_range_v2[2] = {
            22, 23, 2999,
            23, 2, 2888
    };
    cout << date_range_v2[0].year << endl;

    // or with std array
    array<Date, 2> date_range_v3 = {now, yesterday};
    cout << date_range_v3[0].year << endl;

    return 0;
}