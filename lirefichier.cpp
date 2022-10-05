#include "lirefichier.h"

void lirefichier::Ecrire(string mot)
{
    FILE* ptr_fichier ; //pointeur de fichier                                         

     fopen_s(&ptr_fichier,NomFichier.c_str(), "a");     //ouverture du fichier en mode écriture       
     if (ptr_fichier)
     {
         fwrite(mot.c_str(), 1, mot.length(), ptr_fichier);    // ecrire le mot saisie     

         fwrite("\n", 1, 1, ptr_fichier); //sauter des lignes a chaque mot different                       
    
    fclose(ptr_fichier);//fermeture du fichier
     }
 }
void lirefichier::suppr()
{
    int deleteline = 0;// ligne a suprimer
    string Buffer = ""; //Variable contenant le texte à réécrire dans le fichier
    ifstream ReadFile(NomFichier);// ouverture d fichier en mode lecture
    if (ReadFile) //Si le fichier est trouvé
    {
        
        cout << "quel mot veut tu supprimer [num de la ligne]?" << endl <<" 0 pour annuler (plus que ce qui est disponible retourne au meme)" << endl;
        cin >> deleteline;// ligne a suprimer
        if (deleteline != 0)
        {
            string line;
            int Line = 0;
            while (std::getline(ReadFile, line)) //on parcours le fichier et on initialise line à la ligne actuelle
            {
                Line++;
                if (Line != deleteline) //Si la ligne atteinte est différente de la ligne à supprimer...
                    Buffer += line + "\n"; //On ajoute le contenu de la ligne dans le contenu à réécrire

            }
        }
        }
        ReadFile.close(); //On ferme le fichier en lecture
        if (deleteline != 0)
        {
            ofstream WriteFile(NomFichier); //On ouvre ce même fichier en écriture
            if (WriteFile) //Si le fichier est trouvé
            {
                string line;
                int Line = 0;
                while (std::getline(ReadFile, line)) //on parcours le fichier et on initialise line à la ligne actuelle
                {
                    if (!line.empty()) {             // truc qui est censé suppr les lignes vides
                        WriteFile << line << endl;
                    }
                }
            }
            WriteFile << Buffer; //On écris le texte dedans
            WriteFile.close(); //et on ferme le fichier
        }
}

 

    


void lirefichier::afficher_mot()
{
    int d = 1;
    ifstream fichier(NomFichier , ios::in);  // on ouvre en lecture

    if (fichier)
    {
        string ligne;
        while (getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
            cout << d++ << ". " << ligne << endl;  // on l'affiche
        }
    }
    else
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
    fichier.close();
}

string lirefichier::mothasard()
{
    srand(time(NULL));// remet le (temps) a zero
    int MIN = 0;//choix du minimum possible
    int nombre_mot = 0;// nombre de mot dans le fichier
    int i = 0;
    ifstream fichier(NomFichier, ios::in);  // on ouvre en lecture
    string ligne;
    if (fichier)
    {
        
        while (getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
            nombre_mot++;
        }
    }
    
    fichier.close();
    int numMotChoisi = (rand() % (nombre_mot ));// ligne du mot choisie aléatoirement
    ifstream fichier2(NomFichier, ios::in);
 while (i != numMotChoisi)  // si i = numchoisie alors
 {
    i++;// limite
    getline(fichier2, ligne);// recup ligne par ligne dans ligne
 }
 fichier2.close();

    return ligne;// retourne le string du mot choisie
}

lirefichier::lirefichier(string NomFichier)
{
    this->NomFichier = NomFichier;// quel fichier on veut ouvrir
}

lirefichier::~lirefichier()
{
}
