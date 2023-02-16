#include <iostream>
using namespace std;

int main()
{
  int debut(0);
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin(0);
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/

    for (int i(debut); i <= fin; ++i) {
      int k = 0;
      int m = i;
      while (m > 0) {
        if (m % 3 == 0) {
          m += 4;
        } else if (m % 4 == 0) {
          m /= 2;
        } else {
          --m;
        }
        ++k;
      }
      cout << i << " -> " << k << endl;
    }

  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}
