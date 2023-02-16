#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/

  // ===== PARTIE 1 =====
  // Saisie des populations initiales

  do {
    cout << "Combien de renards au départ (>= 2) ? ";
    cin >> renards_i;
  } while (renards_i < 2.);

  do {
    cout << "Combien de lapins au départ  (>= 5) ? ";
    cin >> lapins_i;
  } while (lapins_i < 5.);

  // ===== PARTIE 2 =====
  // Première simulation

  cout << endl << "***** Le taux d'attaque vaut " << taux_attaque * 100 << "%" << endl;
  double num_renards(renards_i), num_lapins(lapins_i);
  for (int i(1); i <= duree; ++i) {
    const double prev_num_renards(num_renards), prev_num_lapins(num_lapins);

    num_lapins *= (1.0 + taux_croissance_lapins - taux_attaque * prev_num_renards);
    if (num_lapins < 0) {
      num_lapins = 0;
    }

    num_renards *= (1.0 + taux_attaque * prev_num_lapins * taux_croissance_renards - taux_mortalite);
    if (num_renards < 0) {
      num_renards = 0;
    }

    cout << "Après " << i << " mois, il y a "
         << num_lapins << " lapins et "
         << num_renards << " renards" << endl;
  }

  // ===== PARTIE 3 =====
  // Variation du taux d'attaque

  cout << endl;

  double taux_attaque_debut(0.0);
  do {
      cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";
      cin >> taux_attaque_debut;
  } while (taux_attaque_debut < 0.5 or taux_attaque_debut > 6);
  taux_attaque_debut /= 100;

  double taux_attaque_fin(0.0);
  do {
      cout << "taux d'attaque à la fin  en % (entre 1 et 6) ? ";
      cin >> taux_attaque_fin;
  } while (taux_attaque_fin < 1 or taux_attaque_debut > 6);
  taux_attaque_fin /= 100;

  for (double taux_attaque(taux_attaque_debut); taux_attaque <= taux_attaque_fin; taux_attaque += 0.01) {
    cout << endl << "***** Le taux d''attaque vaut " << taux_attaque * 100 << "%" << endl;

    num_renards = renards_i;
    num_lapins = lapins_i;
    bool lapins_decroient(false), renards_decroient(false);

    int i(0);
    for (; i < duree; ++i) {
      const double prev_num_renards(num_renards), prev_num_lapins(num_lapins);

      // Calcule les lapins
      num_lapins *= (1.0 + taux_croissance_lapins - taux_attaque * prev_num_renards);
      if (num_lapins < 5 and !lapins_decroient) {
          lapins_decroient = true;
      }

      if (num_lapins < 2) {
          num_lapins = 0;
      }

      if (num_renards == 0 and num_lapins == 0) {
          break;
      }

      // Calcule les renards
      num_renards *= (1.0 + taux_attaque * prev_num_lapins * taux_croissance_renards - taux_mortalite);

      if (num_renards < 5 and !renards_decroient) {
          renards_decroient = true;
      }

      if (num_renards < 2) {
          num_renards = 0;
      }
    }

    cout << "Après " << i << " mois, il y a "
         << num_lapins << " lapins et "
         << num_renards << " renards" << endl;

    if (renards_decroient) {
      cout << "Les renards ont été en voie d'extinction" << endl;
      if (num_renards == 0) {
        cout << "et les renards ont disparu :-(" << endl;
      } else {
        cout << "mais la population est remontée ! Ouf !" << endl;
      }
    }

    if (lapins_decroient) {
      cout << "Les lapins ont été en voie d'extinction" << endl;
      if (num_lapins == 0) {
        cout << "et les lapins ont disparu :-(" << endl;
      } else {
        cout << "mais la population est remontée ! Ouf !" << endl;
      }
    }

    if (!lapins_decroient && !renards_decroient) {
        cout << "Les lapins et les renards ont des populations stables." << endl;
    }
  }

  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}
