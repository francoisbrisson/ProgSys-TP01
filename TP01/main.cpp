#include <iostream>
#include "arbrebinaire.h"

int main()
{
	ArbreBinaire<int> arbre;
	arbre.Ajouter(8);
	arbre.Ajouter(3);
	arbre.Ajouter(1);
	arbre.Ajouter(6);
	arbre.Ajouter(4);
	arbre.Ajouter(7);
	arbre.Ajouter(10);
	arbre.Ajouter(14);
	arbre.Ajouter(13);
	arbre.AfficherCroissant();

	std::cout << (arbre.Contient(6) ? "true" : "false") << std::endl;

	arbre.Vider();
	arbre.AfficherCroissant();

	std::cout << (arbre.Contient(6) ? "true" : "false") << std::endl;


	system("pause");
}
