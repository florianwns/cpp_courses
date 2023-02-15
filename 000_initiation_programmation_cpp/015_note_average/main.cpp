//
// Created by Florian Rey on 15/02/2023.
//

#include <iostream>
using namespace std;

int main(){
    double note, sum(0.);
    int num_notes(4);

    for(int i(0); i < num_notes; ++i){
        cout << "Entrez la note n° " << i << " : ";
        cin >> note;
        sum += note;
    }

    cout << "Average : " << sum / num_notes << endl;

    return 0;
}