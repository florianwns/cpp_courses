//
// Created by Florian Rey on 13/02/2023.
//

#include <iostream>
#include <limits>

using namespace std;

int main() {

    cout << "======== Limits ========" << endl
         << numeric_limits<bool>::min() << " <= bool <= " << numeric_limits<bool>::max() << endl
         << (int) numeric_limits<uint8_t>::min() << " <= uint8_t <= " << (int) numeric_limits<uint8_t>::max() << endl
         << (int) numeric_limits<char>::min() << " <= char <= " << (int) numeric_limits<char>::max() << endl
         << numeric_limits<uint16_t>::min() << " <= uint16_t <= " << numeric_limits<uint16_t>::max() << endl
         << numeric_limits<uint32_t>::min() << " <= uint32_t <= " << numeric_limits<uint32_t>::max() << endl
         << numeric_limits<float>::min() << " <= float <= " << numeric_limits<float>::max() << endl
         << numeric_limits<double>::min() << " <= double <= " << numeric_limits<double>::max() << endl
         << numeric_limits<long double>::min() << " <= long double <= " << numeric_limits<long double>::max() << endl;
    return 0;
}
