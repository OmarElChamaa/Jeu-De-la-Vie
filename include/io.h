/**
* \file io.h
* \brief header file io.h
* \version 4.0
* \author El Chamaa Omar
*/


#ifndef __IO_H
#define __IO_H

#include <stdio.h>
#include "grille.h"
#include "jeu.h"

/**
 * \brief affichage d'un trait horizontal
 * \param c \a int nombre de colonnes
 */

void affiche_trait (int c);

/**
* \brief affichage d'une ligne de la grille
* \param c \a int :nombre de colonnes
* \param l \a int :pointeur sur le nombre de lignes
*/

void affiche_ligne (int c, int* ligne);


/**
 * \brief affichage d'une grille
 * \param g \a grille : grille a afficher
 */

void affiche_grille (grille g);

/**
 * \brief efface une grille
 * \param g \a grille grille a effacer
 */

void efface_grille (grille g);

/**
 * \brief debute le jeu
 * \param g \a grille : grille choisie pour le jeu
 * \param gc \a grille : copie temporaire de la grille
 */

void debut_jeu(grille *g, grille *gc);

/**
* \brief compte ngr d'evolutions
*/
int nb_evolutions ;

/**
* \brief "booleen" pour tester si le vieillisement est active 0=vieillisement desactive , 1= active
*/
int vieux  ;

#endif
