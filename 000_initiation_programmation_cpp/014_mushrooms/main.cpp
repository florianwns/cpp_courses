//
// Created by Florian Rey on 13/02/2023.
//

#include <iostream>

using namespace std;

int main() {
    bool has_gills(false),              // a des lamelles
         has_ring(false),               // a un anneau
         has_convex_hat(false),         // a une chapeau convexe
         grow_in_forest(false);         // Pousse en forêt

    cout << "Pensez à un champignon : amanite tue-mouches, pied bleu, girolle," << endl
            << "cèpe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;

    cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
    cin >> has_ring;

    cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
    cin >> has_convex_hat;

    if(has_ring and has_convex_hat){
        cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
        cin >> grow_in_forest;
    }
    else if(!has_ring and !has_convex_hat){
        cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
        cin >> has_gills;
    }

    cout << "==> Le champignon auquel vous pensez est ";

    //    Seul le cèpe de Bordeaux possède des tubes, les autres champignons ayant des lamelles.
    //    Le coprin chevelu et l’agaric jaunissant poussent dans les prés, les autres dans la
    //    forêt.
    //    Les seuls à avoir un chapeau convexe sont l’agaric jaunissant, l’amanite tuemouches et le pied bleu.
    //    Enfin, les seuls à avoir un anneau sont l’agaric jaunissant, l’amanite tue-mouches
    //    et le coprin chevelu

                                                    // Forêt, Lamelles, Anneau, Convexe
    if(has_ring) {
        if(has_convex_hat){
            if(grow_in_forest){
                cout << "l'amanite tue-mouches";    // Oui,   Oui,      Oui,    Oui
            } else {
                cout << "l'agaric jaunissant";      // Non,   Oui,      Oui,    Oui
            }
        } else {
            cout << "le coprin chevelu";            // Non,   Oui,      Oui,    Non
        }
    }
    else{
        if(has_convex_hat){
            cout << "le pied bleu";                 // Oui,   Oui,      Non,    Oui
        } else {
            if(has_gills){
                cout << "la girolle";               // Oui,   Oui,      Non,    Non
            } else {
                cout << "le cèpe de Bordeaux";      // Oui,   Non,      Non,    Non
            }
        }
    }

    return 0;
}
