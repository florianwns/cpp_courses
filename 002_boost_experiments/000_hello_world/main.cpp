//
// Created by Florian Rey on 24/02/2023.
//

#include "boost/version.hpp"

#include <iostream>

using namespace std;

int main() {
    cout << "Using Boost "
          << BOOST_VERSION / 100000 << "."      // major version
          << BOOST_VERSION / 100 % 1000 << "."  // minor version
          << BOOST_VERSION % 100                // patch level
          << endl;
    return 0;
}