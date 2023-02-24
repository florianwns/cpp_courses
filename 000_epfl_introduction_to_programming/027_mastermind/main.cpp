#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c)
{
    const string valid_chars = ".RGBCYM";
    return valid_chars.find(c) != string::npos;
}

// ======================================================================
bool verifier(const char c, char &r, int &score)
{
    const bool is_valid = (c == r);
    score += is_valid;
    if(is_valid){
        r = 'x';
    }
    return is_valid;
}

// ======================================================================
void apparier(const char c1,
              char &r1,
              char &r2,
              char &r3,
              int &score)
{
    verifier(c1, r1, score) or verifier(c1, r2, score) or verifier(c1, r3, score);
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{
    int valid_chars(0), nb_bien_placees(0), nb_mal_placees(0);

    valid_chars = verifier(c1, r1, nb_bien_placees);
    valid_chars += verifier(c2, r2, nb_bien_placees) * 2;
    valid_chars += verifier(c3, r3, nb_bien_placees) * 4;
    valid_chars += verifier(c4, r4, nb_bien_placees) * 8;

    if(not(valid_chars & 1)){
        apparier(c1, r2, r3, r4, nb_mal_placees);
    };

    if(not(valid_chars & 2)){
        apparier(c2, r1, r3, r4, nb_mal_placees);
    };

    if(not(valid_chars & 4)){
        apparier(c3, r1, r2, r4, nb_mal_placees);
    };

    if(not(valid_chars & 8)){
        apparier(c4, r1, r2, r3, nb_mal_placees);
    };


    afficher(nb_bien_placees, '#');
    afficher( nb_mal_placees, '+');
    afficher(4 - nb_bien_placees - nb_mal_placees, '-');
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
    return c1 == r1 and c2 == r2 and c3 == r3 and c4 == r4;
}

// ======================================================================
void jouer(int coup_max = 8)
{
    const char r1(tirer_couleur()),
         r2(tirer_couleur()),
         r3(tirer_couleur()),
         r4(tirer_couleur());

    bool a_gagne;
    int nb_coups(0);

    do{
        const char c1(lire_couleur()),
                   c2(lire_couleur()),
                   c3(lire_couleur()),
                   c4(lire_couleur());

        afficher_coup(c1, c2, c3, c4, r1, r2, r3, r4);
        a_gagne = gagne(c1, c2, c3, c4, r1, r2, r3, r4);
    } while(++nb_coups < coup_max and not a_gagne);

    if(a_gagne){
        message_gagne(nb_coups);
    } else {
        message_perdu(r1, r2, r3, r4);
    }
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}
