//
// Created by Florian Rey on 01/03/2023.
//

#include <iostream>
#include "boost/date_time/gregorian/gregorian.hpp"

using namespace std;
using namespace boost::gregorian;

int main()
{
    date last_year{2022, 3, 1};
    cout << last_year << endl;

    auto utc_today = day_clock::universal_day();
    cout << utc_today << endl;

    auto today = day_clock::local_day();;
    cout << today << endl;

    date_duration diff = today-last_year;
    cout << diff << " days between " << last_year << " and " << today << endl;
}