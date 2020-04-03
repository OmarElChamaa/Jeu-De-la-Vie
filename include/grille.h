/**
* \file grille.h
* \brief header file grille.h
* \version 4.0
* \author El Chamaa Omar
*/


#ifndef __GRILLE_H
#define __GRILLE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
* \brief structure de la grille
* \param nbl \a int :nombre de lignes de la grille
* \param nbc \a int :nombre de colones de la grille
* \param cellules \a int** : tableau de tableau de la cellule
*/

typedef struct {int nbl; int nbc; int** cellules;} grille;

/**
* \brief fonction pour allouer la grille de taille l*c
* \param l \a int :lignes
* \param c \a int :colones
* \param *g \a Grille :pointeur sur la grille
*/

void alloue_grille (int l, int c, grille* g);

/**
* \brief fonction pour liberer une grille
* \param *g \a grille :pointeur sur la grille a liberer
*/

void libere_grille (grille* g);

/**
* \brief fonction pour allouer et initialiser la grille
* \param filename \a char : Nom du fichier à partir du quel la grille doit être initialisee
* \param *g  \a grille :pointeur sur la grille a initialiser
*/

void init_grille_from_file (char * filename, grille* g);

/** rend vivante la cellule (i,j) de la grille g */
static inline void set_vivante(int i, int j, grille g){g.cellules[i][j] = 1;}
/** rend morte la cellule (i,j) de la grille g */
static inline void set_morte(int i, int j, grille g){g.cellules[i][j] = 0;}
/** teste si la cellule (i,j) de la grille g est vivante*/
static inline int est_vivante(int i, int j, grille g){return g.cellules[i][j] >= 1;}

/** rend non viable la cellule (i,j) de la grille g */
static inline int set_non_viable(int i, int j, grille g){return g.cellules[i][j] = -1;}

/** teste si la cellule (i,j) de la grille g est non viable*/
static inline int est_non_viable(int i, int j, grille g){return g.cellules[i][j] == -1;}


/**
* \brief fonction pour copier ne grille sans allocation
* \param gs \a grille : grille que l'on souhaite copier
* \param gd \a grille :grille ou on souhaite copier
*/

void copie_grille (grille gs, grille gd);


/**
* \brief fonction pour tester la vacuite
* \param *g \a grille :pointeur sur la grille a tester
*/
int grilleVide(grille *g);




/**
* \brief teste l'egalite de 2 grilles
* \param gs \a grille : grille 1
* \param gd \a grille : grille 2
* \return int : 0 si elles sont egales 1 si elles ne le sont pas
*/

int grilleEg(grille g1,grille g2);

/**
* \brief test si une grille est oscillante
* \bug si la grille est oscillante , le test retoune "Oscillante au bout de "nb_evolutions courant, et non pas celui ou on obtient l'oscillation
* \bug si la grille n'est pas oscillante , le programme reste bloque dans la boucle
* \bug Donc la fonction fonctionne (a moitie) que si la grille est oscillante
* \bug Il faut faire evoluer la grille au moins 3/4 fois avant de declancher le test
* \param g \a grille : grille a tester oscillation
* \return retourne nb_evolutions pour obtenir oscillation si possible , -1 sinon
 */
int grilleOscillante(grille *g);


#endif
