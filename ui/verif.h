#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <string.h>
#include "lirefichier.h"
using namespace std;
class verif 
{
private:
	char* motchoisie;// mot a trouver
	
public:
	bool lettre_t(char* lettrechoisie);// si oui ou non la lettre qu'on utilise est bonne ou pas
	lirefichier* mot;// ajout de manière dinamique et publique de la classe lire fichier
	bool transfo_txt_to_asterisk( char* lettrechoisie);// montre a quel emplacement il manque des lettre 
	string lettre_utilisé(char lettrechoisie);// montre quel lettre on était utilisé
	void set_motchoisie();// choisie un nouveau mot
	void get_motchoisie();// recupère le mot choisie
	void pendu(char difficulter, int coups);// affiche le pendu
	verif();
	~verif();
};

