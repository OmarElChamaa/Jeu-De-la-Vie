/**
* \author El Chamaa Omar
* \version 4.0
* \date 26/02/2020
* \mainpage Jeu de la vie
* \section intro_sec Introduction
*   Ce code est base sur "Conway's game of life" , ou jeu de la vie . \n
*   On peut simuler le jeu sur des grilles composees de differentes tailles et parametres.
* \section exec_sec Compilation
*   Pour compiler en mode texte : make MODE=TEXTE . \n
*   Pour compiler en mode graphique : make .
*  \section  Execution
*   Pour executer ce programme en mode text , veuillez taper "./bin/exe grilles/grille(nbr grille).txt " \n
*   Pour ececuter ce programme en mode gaphique , veuillez taper  "./bin/cairo grilles/grille(nbr grille).txt " \n
*  \section Documentation
*   Pour generer la documentation : make doxyfile , le dossier html se trouvera dans le fichier doc
*  \bug Quand on rentre une nouvelle grille en executant avec cairo, quelques grilles s'initialises mal
*/



#include <stdio.h>
#include "../include/grille.h"
#include "../include/io.h"
#include "../include/jeu.h"




int main (int argc, char ** argv) {

	if (argc != 2 )
	{
		printf("usage : main <fichier grille>");
		return 1;
	}

	grille g, gc;
	init_grille_from_file(argv[1],&g);
	alloue_grille (g.nbl, g.nbc, &gc);
	affiche_grille(g);

	debut_jeu(&g, &gc);

	libere_grille(&g);
	libere_grille(&gc);
	return 0;
}
