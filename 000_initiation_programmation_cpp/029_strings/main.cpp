//
// Created by Florian REY on 22/02/2023.
//

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    string first_name, last_name, full_name;

    first_name = "Florian";
    last_name = "Rey";

    // Iterator style
    transform(last_name.begin(), last_name.end(), last_name.begin(), ::toupper);

    //C++11 style
    for (auto & c: last_name) c = toupper(c);

    full_name = first_name + " " + last_name;

    full_name.insert(0, ">> ");
    full_name.insert(full_name.size(), " << ||");

    full_name.replace(0, 1, "|| >");


    cout << full_name << endl;

    cout << "Florian start at " << full_name.find("Florian") << endl;

    cout << "'Pouet' a t il était trouvé ? " << (full_name.find("Pouet") == string::npos ? "Non" : "Oui" ) << endl;

    cout << "Les 3 première lettre du prénom sont : " << first_name.substr(0, 3) << endl;

    return 0;
}
