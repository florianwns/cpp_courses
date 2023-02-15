#include <iostream>
using namespace std;

int main()
{
    cout << "Donnez l'heure de début de la location (un entier) : ";
    int debut;
    cin >> debut;

    cout << "Donnez l'heure de fin de la location (un entier) : ";
    int fin;
    cin >> fin;

    /*****************************************************
     * Compléter le code à partir d'ici
     *****************************************************/

    if(debut < 0 or debut > 24 or fin < 0 or fin > 24){
        cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
    }
    else if (debut == fin){
        cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" << endl;
    }
    else if(debut > fin) {
        cout << "Bizarre, le début de la location est après la fin ..." << endl;
    }
    else{
        cout << "Vous avez loué votre vélo pendant" << endl;

        int total_price = 0;
        int num_hours[] = {0, 0};
        constexpr int hourly_prices[] = {1, 2};

        for (int h(debut); h < fin; ++h) {
            num_hours[(h >= 7 and h < 17)]++;
        }

        for(int i(0); i < 2; ++i){
            if(num_hours[i] > 0){
                cout << num_hours[i] << " heure(s) au tarif horaire de " << hourly_prices[i] << " franc(s)" << endl;
                total_price += num_hours[i] * hourly_prices[i] ;
            }
        }

        cout << "Le montant total à payer est de " << total_price << " franc(s)." << endl;
    }

    /*******************************************
     * Ne rien modifier après cette ligne.
     *******************************************/

    return 0;
}
