/**
* \file jeu.h
* \brief Header file de jeu.h
* \version 4.0
* \author El Chamaa Omar
*/


#ifndef __JEU_H
#define __JEU_H

#include "grille.h"
#include "io.h"

/**
* \brief modulo modifié pour traiter correctement  dans le calcul des voisins avec bords cycliquesles bords i=0 et j=0
* \param compte le nombre de voisins vivants de la cellule (i,j) les bords sont cycliques.
*/

static inline int modulo(int i, int m) {return (i+m)%m;}

/**
* \brief pointeur sur compte voisins vivants cyclique
* \param i, j \a cellule
* \param  g \a grille
*/

int (*compte_voisins_vivants)(int, int, grille);

/**
* \brief Compte nb de voisins vivantscyclique .
* \param i,j \a cellule
* \param g \a grille
* \return Nombre des voisins vivants cyclique
*/

int compte_voisins_vivants_cyclique (int i, int j, grille g);


/**
* \brief Compte voisins non cyliques
*\param i,j \a cellule
*\param g \a grille
* \return Nombre de voisins vivants non cyclique
*/
int compte_voisins_vivants_non_cyclique(int i, int j , grille g);

/**
* \brief fonction pour evoluer la grille d'un pas
* \param  g \a grille :grille initiale
* \param gc \a grille : copie temporaire de la grille
* \return nouvelle grille evoluee
*/

void evolue (grille *g, grille *gc);


/**
* \brief "booleen" pour verifier si cyclique est active ou pas 0= oui 1 = non
*/
int cyclique ;

#endif
