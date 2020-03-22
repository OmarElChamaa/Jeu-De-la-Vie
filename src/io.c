#include "../include/io.h"
/**
* \file io.c
* \brief fichier src io.c
* \version 3.0
* \author El Chamaa Omar
*/



void affiche_trait (int c){
	int i;
	for (i=0; i<c; ++i) printf ("|---");
	printf("|\n");
	return;
}

void affiche_ligne (int c, int* ligne){
int i;
	if (vieux==1) {
		for (i=0; i<c; ++i) {
			if (ligne[i] == 0 ) printf ("|   ");
			else if (ligne[i] == -1) printf("| X "); // Non-viable
			else printf ("| %d ", ligne[i]);
		}
	} else {
		for (i=0; i<c; ++i) {
			if (ligne[i] == 0 ) printf ("|   ");
			else if (ligne[i] == -1) printf("| X "); // Non-viable
			else printf ("| 0 ");
		}
	}
	printf("|\n");
	return;
}

void affiche_grille (grille g){
	int i, l=g.nbl, c=g.nbc;
	printf("\n");
	affiche_trait(c);
	for (i=0; i<l; ++i) {
		affiche_ligne(c, g.cellules[i]);
		affiche_trait(c);
	}
	printf("\n");
	printf("Temps d'evolution : %d ",nb_evolutions);
	if(cyclique==1)
				{
                    printf("|| Voisinage cyclique Active ");
				}
				else
				{
                    printf("|| Voisinage cyclique Descative ");
				}
    if(vieux==0)
                {
                    printf("|| Vieillisement Desactive ");

                }
                else
                {
                    printf("|| Vieillisement Active");

                }

	return;
}

void efface_grille (grille g){
	printf("\n\e[%dA",g.nbl*2 + 5);
}

void debut_jeu(grille *g, grille *gc){
	char c = getchar();
	while (c != 'q') // touche 'q' pour quitter
	{
		switch (c) {
			case '\n' :
			{ // touche "entree" pour évoluer

				evolue(g,gc);
				efface_grille(*g);
				nb_evolutions ++ ;
				affiche_grille(*g);
				break;
			}
			case 'n':
			{
				 printf("Entrez le chemin de la nouvelle grille: ");

                 char new_grille[50];
                 scanf("%s",new_grille);
                 printf("<%s>\n",new_grille);
				 init_grille_from_file(new_grille , g );
				 alloue_grille(g->nbl , g->nbc , gc );
				 nb_evolutions = 0 ;
				 affiche_grille(*g);
				 while (getchar()!='\n');
               break ;

			}
			case 'c': //touche pour activer/desactiver voisinage cyclique
            {
                 if(compte_voisins_vivants==compte_voisins_vivants_cyclique)
                 {
                    compte_voisins_vivants=compte_voisins_vivants_non_cyclique;
                    cyclique =0 ;

                 }
                 else
                 {
                     compte_voisins_vivants=compte_voisins_vivants_cyclique;
                     cyclique =1;

                 }
                 break ;

            }
            case 'v': //active/desactive vieillisement
            {
                if(vieux==0)
                {
                    vieux=1;

                }
                else
                {
                    vieux=0;

                }
                break;
            }


			default :
			{ // touche non traitée
				printf("\n\e[1A");
				break;
			}
		}
		c = getchar();
	}

	return;
}
