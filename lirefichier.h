
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <ctime>
using namespace std;
 class lirefichier
{
private:
	string NomFichier;
public:
	void Ecrire(string mot);// ecrit un mot saisie par l''utilisateur dans un fichier définie
	void suppr(); // supprime une ligne qui a était choisie par l'utilisateur dans un fichier définie
	void afficher_mot(); // affiche les ligne une a une
	string mothasard(); // chosie aléatoirement une ligne dans un fichier définie puis stock le premier mot
	lirefichier(string NomFichier);//constructeur
	~lirefichier();//destructeur
};

