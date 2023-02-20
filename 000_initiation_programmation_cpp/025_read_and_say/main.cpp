#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre)
{
    nombre = nombre * 10 + chiffre;
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre)
{
    ajouter_chiffre_droit(nombre, repetitions_chiffre);
    ajouter_chiffre_droit(nombre, chiffre);
}

int lire_et_dire(int nombre)
{
    int res(0),
        repetitions_chiffre(1),
        chiffre(separer_chiffre_gauche(nombre));

    do{
        const int chiffre_suivant(separer_chiffre_gauche(nombre));
        if(chiffre_suivant == chiffre){
            repetitions_chiffre++;
        } else {
            dire_chiffre(res, repetitions_chiffre, chiffre);
            repetitions_chiffre = 1;
            chiffre = chiffre_suivant;
        }
    }while(chiffre > 0);

    return res;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}
