#include "verif.h"

bool verif::lettre_t(char *lettrechoisie)
{ 
    int i = 0;
    size_t taille = strlen(motchoisie.c_str());//taille du mot
    size_t taille2 = strlen(lettrechoisie);// taille des lettres choisie
        int y = 0;
        for (i = 0; i < taille; i++)
        {
            this_thread::sleep_for(chrono::milliseconds(10));
                if (lettrechoisie[taille2-1] == motchoisie[i])//si la dernière lettre choisie est égale a l'une des lettre du mot 
                {
                    y = 1;//mettre y a 1
                }

            }
        if (y == 1)
        {
            return true;// retourne la valeur true si y = 1
        }
        else
        {
            return false;// sinon retourné false
        }
}

bool verif::transfo_txt_to_asterisk(char *lettrechoisie)

{

    int win_cond = 0;//  victoire ou pas
    int i = 0;
    size_t taille = strlen(motchoisie.c_str()); //taille du mot
        for (i = 0; i < taille; i++)
    {
            this_thread::sleep_for(chrono::milliseconds(50));
        if (strchr(lettrechoisie, motchoisie[i]) && motchoisie[i] != 0) // si les lettres choisies ce trouve dans motchoisie 
        {
            win_cond = win_cond++; // ajout de point pour la victoire
            cout << motchoisie[i];// afichage des bonnes lettres
            
        }
        else if (!strchr(lettrechoisie, motchoisie[i]) && motchoisie[i] != 0)// si il trouve pas
        {
                   cout << "*";//marqué des asterisk
     
        }
    }

    if (win_cond == taille)
    {
            return true;// si la taille est égale au point de victoire alors c gagner
    }
    else
    {
            return  false;// sinon toujours pas
    }
    
}


string verif::lettre_utilisé(char lettrechoisie)
{
    char lettre[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; // alphabet pour les verification
    int i = 0;
    string tab2 = "";//contenant des lettres utiliser
    size_t taille = strlen(&lettre[26]) - 8;//taille des lettres
    char jenaimar = 0;
    jenaimar = toupper(lettrechoisie);// tout en majuscule
    for (i = 0; i < taille; i++)
    {   
        this_thread::sleep_for(chrono::milliseconds(10));
        
        if (strchr(&jenaimar, lettre[i]) && lettre[i] != 0)// si il trouve une lettre de l'alphabet
        {
            this_thread::sleep_for(chrono::milliseconds(10));
           tab2.push_back(lettre[i]);//il la met dans le tableau
        }
        else if (!strchr(&jenaimar, lettre[i]) && lettre[i] != 0)
        {
            this_thread::sleep_for(chrono::milliseconds(10));
            tab2.push_back(' ');//sinon laisser un espace

        }

    } 
    return tab2;//retourne le tableau
    }

void verif::set_motchoisie()
{
    this->motchoisie = mot->mothasard();// set du mot au hasard pour faire plusieur partie
}

void verif::get_motchoisie()
{
    string ui;
    ui = this->motchoisie;//get du mot au hasard si on perd
    cout << ui;
}

void verif::pendu(char difficulter, int coups)
{
    const char* pendu[20] = {                   // pendu en 16 partie divisable en 2, ,4 ,8

    "              \n"\
    "              \n"\
    "              \n"\
    "              \n"\
    "              \n"\
    "              \n"\
    "              \n"\
    "              \n"\
    "              \n"\
    "              \n"\
    "              \n"\
    "  ____________\n",

    "              \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |____________\n",

    "  _______     \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |____________\n",

    "  _______     \n"\
    " |       |    \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |____________\n",

    "  _______     \n"\
    " | /     |    \n"\
    " |/           \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |____________\n",

    "  _______     \n"\
    " | /     |    \n"\
    " |/           \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |\\          \n"\
    " | \\         \n"\
    " |__\\________\n",

    "  _______     \n"\
    " |  /    |    \n"\
    " |/      _    \n"\
    " |      / \\  \n"\
    " |      \\_/  \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |\\          \n"\
    " | \\         \n"\
    " |__\\________\n",

    "  _______     \n"\
    " |  /    |    \n"\
    " |/      _    \n"\
    " |      / \\  \n"\
    " |      \\_/  \n"\
    " |       |    \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |\\          \n"\
    " | \\         \n"\
    " |__\\________\n",

    "  _______     \n"\
    " |  /    |    \n"\
    " |/      _    \n"\
    " |      / \\  \n"\
    " |      \\_/  \n"\
    " |      _|_   \n"\
    " |            \n"\
    " |            \n"\
    " |            \n"\
    " |\\          \n"\
    " | \\         \n"\
    " |__\\________\n",

    "  _______     \n"\
    " |  /    |    \n"\
    " |/      _    \n"\
    " |      / \\  \n"\
    " |      \\_/  \n"\
    " |      _|_   \n"\
    " |      | |   \n"\
    " |            \n"\
    " |            \n"\
    " |\\          \n"\
    " | \\         \n"\
    " |__\\________\n",

    "  _______     \n"\
    " |  /    |    \n"\
    " |/      _    \n"\
    " |      / \\  \n"\
    " |      \\_/  \n"\
    " |      _|_   \n"\
    " |      | |   \n"\
    " |      |_|   \n"\
    " |            \n"\
    " |\\          \n"\
    " | \\         \n"\
    " |__\\________\n",

    "  _______     \n"\
    " |  /    |    \n"\
    " |/      _    \n"\
    " |      / \\  \n"\
    " |      \\_/  \n"\
    " |      _|_   \n"\
    " |     /| |   \n"\
    " |    / |_|   \n"\
    " |            \n"\
    " |\\          \n"\
    " | \\         \n"\
    " |__\\________\n",

    "  _______     \n"\
    " |  /    |    \n"\
    " |/      _    \n"\
    " |      / \\  \n"\
    " |      \\_/  \n"\
    " |      _|_   \n"\
    " |     /| |\\ \n"\
    " |    / |_| \\\n"\
    " |            \n"\
    " |\\          \n"\
    " | \\         \n"\
    " |__\\________\n",

    "  _______     \n"\
    " |  /    |    \n"\
    " |/      _    \n"\
    " |      / \\  \n"\
    " |      \\_/  \n"\
    " |      _|_   \n"\
    " |     /| |\\ \n"\
    " |    / |_| \\\n"\
    " |       ^    \n"\
    " |\\          \n"\
    " | \\         \n"\
    " |__\\________\n",

    "  _______     \n"\
    " |  /    |    \n"\
    " |/      _    \n"\
    " |      / \\  \n"\
    " |      \\_/  \n"\
    " |      _|_   \n"\
    " |     /| |\\ \n"\
    " |    / |_| \\\n"\
    " |       ^    \n"\
    " |\\    /     \n"\
    " | \\  /      \n"\
    " |__\\________\n",

    "  _______     \n"\
    " |  /    |    \n"\
    " |/      _    \n"\
    " |      / \\  \n"\
    " |      \\_/  \n"\
    " |      _|_   \n"\
    " |     /| |\\ \n"\
    " |    / |_| \\\n"\
    " |       ^    \n"\
    " |\\    / \\  \n"\
    " | \\  /   \\ \n"\
    " |__\\________\n",
    };
    // test de quel difficulter il sagit si diff = 1 pas besoin du pendu
    if (difficulter == '2')
    {
        cout << pendu[coups - 1];
    }
    if (difficulter == '3')
    {
        cout << pendu[coups * 2 - 1];
    }
    if (difficulter == '4')
    {
        cout << pendu[coups * 4 - 1];
    }
    if (difficulter == '5')
    {
        cout << pendu[coups * 8 -1]; // calcul pour que ca coresponde au nbr de coups associé a la difficulter
    }
}
// constructeur
verif::verif()
{
     mot = new lirefichier("mot.txt"); //def du nom/chemin du fichier
    this->motchoisie = mot->mothasard();// pioche un mot au hasard de manière auto
}
// destructeur
verif::~verif()
{
}
