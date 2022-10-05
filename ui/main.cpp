#include <iostream>
#include "verif.h"
#include<windows.h>

using namespace std;
int main()
{
	bool stop = false;
	verif* ui = new verif();//alouage dynamique de l'objet ui

		cout << "------------------------------------------BIENVENUE SUR LE JEU DU PENDU------------------------------------------" <<
			endl << "regle a respecter" <<
			endl << "1 !!!les accents aisi que les chiffres sont interdit sinon ca va faire bugger le jeu!!!" <<
			endl << "2 il faut marquer une lettre (si vous en marquer plusieur la premiere sera la seul compter" <<
			endl << "3 quand vous ajoutez des mots il ne faut pas mettre des accent ou des espaces" << endl << endl;

		this_thread::sleep_for(chrono::milliseconds(1000));

		cout << "------------------------------------------AMUSER VOUS BIEN------------------------------------------" <<
			endl <<endl <<endl <<endl;

		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << endl << "------------------------------------------listing des mot------------------------------------------" << endl;
		this_thread::sleep_for(chrono::milliseconds(50));
		ui->mot->afficher_mot();
	while (stop == false)// eteindre ou pas le programme
	{

			int y = 0;
			int f = 0;
			int d = 0;
			char mode = '0';//mode a selec
			char lettre[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

		cout << endl;

		this_thread::sleep_for(chrono::milliseconds(1000));

		while (y == 0)
		{
			char rejouer = '1';//recomencer une partie
			f = 0;

			this_thread::sleep_for(chrono::milliseconds(10));
			
			cout << "------------------------------------------menu------------------------------------------" << endl;
			cout << "1 ecrire des nouveaux mots" << endl << endl;
			cout << "2 suprimer des mots" << endl << endl;
			cout << "3 reafficher les mots" << endl << endl;
			cout << "4 jouer" << endl << endl;
			cout << "5 fermer le jeu" << endl << endl;

			cin >> mode;// entrer le mode

			if (mode == '3')
			{
				y = 1;
				cout << endl << "------------------------------------------listing des mot------------------------------------------" << endl;
				ui->mot->afficher_mot();
			}
			else if (mode == '1')
			{
				cout << "3 regle importante" << endl
					<< "1. PAS D'ACCENT :)" << endl
					<< "2. une lettre n'est pas un mot :)" << endl
					<< "3. pas plus de 99 lettre (pas d'espace aussi)" << endl;

				y = 1;
				int i = 0;
				float x = 0;
				string ajout;

				cout << "mot a ajouter :";

				cin >> ajout;
				size_t taille = strlen(ajout.c_str());
				for (y = 0; y < taille; y++)
				{
					for (i = 0; i < 26; i++)
					{
						if (toupper(ajout[y]) != lettre[i])
						{
							x++;
						}
					}
				}
				if (x/25 > taille ) // test par rapport a ce que je veut
				{
					cout << "pas d accent ou d'espace:( " << endl;
				}
				else if (taille == 1)
				{
					cout << "un mot pas une lettre" << endl;
				}
				else if (taille > 99)
				{
					cout << "\"-_-, vraiment + de "<< taille <<" lettre le mot" << endl;
				}
				else
				{
					ui->mot->Ecrire(ajout);
				}
				ui->mot->afficher_mot();
			}
			else if (mode == '2')
			{
				y = 1;

				ui->mot->suppr();
			}
			else if (mode == '5')
			{
				y = 1;

				stop = true;// retouner 0
			}
			else if (mode == '4')
			{
				y = 1;
				
				while (rejouer == '1')//rejouer si 0 retour au menu
				{

					this_thread::sleep_for(chrono::milliseconds(10));
					int u = 0;
					int nbr_coups = 0;
					int diff_nbr_coups = 0;
					int g = 0;
					int coup_restant = 0;
					char difficulter = 0;
					char su[100] = { 0 };
					char* su2 = new char[1];
					string result = "";
					string result2 = "                         ";
					bool tmp = false;
					bool tmp2 = false;
					int p = 0;
					int i = 0;
					int f = 0;
					int d = 0;

					
					
					while (d == 0)
					{
						cout << "choisie une difficulter:" << endl;
						cout << "1-INRATABLE(nombre de coups infini)" <<
							endl << "2-FACILE(nombre de coups = 16)" <<
							endl << "3-CLASSIQUE(nombre de coups = 8)" <<
							endl << "4-DIFFICILE(nombre de coups = 4)" <<
							endl << "5-IMPOSSIBLE(nombre de coups = 2)" <<
							endl;

						cin >> difficulter;

						if (difficulter == '1')
						{
							d = 1;
							diff_nbr_coups = -1;//infinie
						}
						else if (difficulter == '2')
						{
							d = 1;
							diff_nbr_coups = 16;
						}
						else if (difficulter == '3')
						{
							d = 1;
							diff_nbr_coups = 8;
						}
						else if (difficulter == '4')
						{
							d = 1;
							diff_nbr_coups = 4;
						}
						else if (difficulter == '5')
						{
							d = 1;
							diff_nbr_coups = 2;
						}
						else
						{
							d = 0;
						}
						ui->set_motchoisie();
						coup_restant = diff_nbr_coups;

					}
					cout << "mot a trouver" << endl;
					ui->transfo_txt_to_asterisk(su);
					cout << endl;
					while (f == 0)
					{
						string stp;
						g = 0;

						this_thread::sleep_for(chrono::milliseconds(10));

						if (difficulter == '1')
						{
							cout << "nombre de coups  " << nbr_coups << endl;
						}
						else
						{
							cout << "nombre de coups  " << nbr_coups << "   coups restant   " << coup_restant << "  coups max   " << diff_nbr_coups << endl;
						}
						if (nbr_coups >= 1)
						{
							ui->pendu(difficulter, nbr_coups);
						}
					
						cout << endl << "taper une lettre" << endl;

						while (g == 0)//test de si c'est autre chose que une lettre de notre alphabet
						{

							cin >> su[p];

							for (i = 0; i < 26; i++)
							{
								if (toupper(su[p]) == lettre[i])
								{
									g = 1;
								}
							}
						}
						*su2 = su[p];
						p = p++;
						tmp = ui->transfo_txt_to_asterisk(su);
						tmp2 = ui->lettre_t(su);
					
						if (tmp2 == true)
						{
							cout << endl << "lettre trouver " << endl;
						}
						else
						{
							coup_restant--;
							nbr_coups++;

							cout << endl << "pas encore" << endl;

							
						}

						result = (ui->lettre_utilisé(*su2));
						int pos = result.find_first_not_of(" ");
						stp = result[pos];

						result2.replace(pos, 1, stp);// ca permet de stocké les lettre utiliser et de toute les afficher en plus de remettre au meme endroit celle déjas utilisé

						cout << result2 << endl;

						if (tmp == true || coup_restant == 0)
						{

							if (coup_restant == 0)
							{		
								ui->pendu(difficulter, nbr_coups);
								f = 1;

								cout << endl << "perdu vous avez utiliser vos " << nbr_coups << " coups" << endl;
								cout << "le mot était ";
								ui->get_motchoisie();
								cout << endl;
								coup_restant--;
								nbr_coups++;
							}
							else
							{
								if (nbr_coups >= 1)
								{
									ui->pendu(difficulter, nbr_coups);
								}
								

								f = 1;

								cout << endl << "GG, tu as win en" << nbr_coups << "coups" << endl;
							}
							while (u == 0)
							{
								this_thread::sleep_for(chrono::milliseconds(10));
								cout << "rejouer ?" << endl << "0 = non      1 = oui" << endl;

								cin >> rejouer;

								if (rejouer != '0' && rejouer != '1')
								{
									u = 0;
								}
								else
								{
									u = 1;
								}
							}
						}
					}
				}
			}
			else
			{
			y = 0;
			}
		}
	}
	
	return 0;
}

