#include "../include/jeu.h"

/**
* \file jeu.c
* \brief fichier src jeu.c
* \version 2.0
* \author El Chamaa Omar
*/


int compte_voisins_vivants_cyclique (int i, int j, grille g){
	int v = 0, l=g.nbl, c = g.nbc;
	v+= est_vivante(modulo(i-1,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i-1,l),modulo(j,c),g);
	v+= est_vivante(modulo(i-1,l),modulo(j+1,c),g);
	v+= est_vivante(modulo(i,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i,l),modulo(j+1,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j-1,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j,c),g);
	v+= est_vivante(modulo(i+1,l),modulo(j+1,c),g);

	return v;
}

int compte_voisins_vivants_non_cyclique(int i, int j , grille g)
{
 int v=0;
	if (i==0 && j==0)
	{
		v+= est_vivante(i+1,j,g);
		v+= est_vivante(i+1,j+1,g);
		v+= est_vivante(i,j+1,g);
	}
	else if (i==0 && j==g.nbc-1)
	{
		v+= est_vivante(i,j-1,g);
		v+= est_vivante(i+1,j-1,g);
		v+= est_vivante(i+1,j+1,g);
	}
	else if (i==g.nbl-1 && j==g.nbc-1)
	{
		v+= est_vivante(i-1,j,g);
		v+= est_vivante(i-1,j-1,g);
		v+= est_vivante(i,j-1,g);
	}
	else if (i==g.nbl-1 && j==0)
	{
		v+= est_vivante(i,j+1,g);
		v+= est_vivante(i-1,j+1,g);
		v+= est_vivante(i-1,j,g);
	}
	else if (i==0 && j<g.nbc-1)
	{
		v+= est_vivante(i,j-1,g);
		v+= est_vivante(i+1,j-1,g);
		v+= est_vivante(i+1,j,g);
		v+= est_vivante(i+1,j+1,g);
		v+= est_vivante(i,j+1,g);
	}
	else if (i<g.nbl-1 && j==g.nbc-1)
	{
		v+= est_vivante(i-1,j,g);
		v+= est_vivante(i-1,j-1,g);
		v+= est_vivante(i,j-1,g);
		v+= est_vivante(i+1,j-1,g);
		v+= est_vivante(i+1,j,g);
	}
	else if (i==g.nbl-1 && j<g.nbc-1)
	{
		v+= est_vivante(i,j+1,g);
		v+= est_vivante(i-1,j+1,g);
		v+= est_vivante(i-1,j,g);
		v+= est_vivante(i-1,j-1,g);
		v+= est_vivante(i,j-1,g);
	}
	else if (i<g.nbl-1 && j==0)
	{
		v+= est_vivante(i+1,j,g);
		v+= est_vivante(i+1,j+1,g);
		v+= est_vivante(i,j+1,g);
		v+= est_vivante(i-1,j+1,g);
		v+= est_vivante(i-1,j,g);
	}
	else
	{
		v+= est_vivante(i-1,j-1,g);
		v+= est_vivante(i-1,j,g);
		v+= est_vivante(i-1,j+1,g);
		v+= est_vivante(i,j+1,g);
		v+= est_vivante(i+1,j+1,g);
		v+= est_vivante(i+1,j,g);
		v+= est_vivante(i+1,j-1,g);
		v+= est_vivante(i,j-1,g);
	}
	return v;

}


int (*compte_voisins_vivants)(int, int, grille)= compte_voisins_vivants_cyclique;

void evolue (grille *g, grille *gc){
	copie_grille (*g,*gc); // copie temporaire de la grille
	int i,j,l=g->nbl, c = g->nbc,v;
	for (i=0; i<l; i++)
	{
		for (j=0; j<c; ++j)
		{
                v = compte_voisins_vivants (i, j, *gc);

                if (est_vivante(i,j,*g))
                { // evolution d'une cellule vivante
                        if (v!=2 && v!=3) {set_morte(i,j,*g);}
                        else if (vieux==1) g->cellules[i][j]++;
                        else g->cellules[i][j]=1;

                        if(vieux==1 && g->cellules[i][j]>8) set_morte(i,j,*g);
                }
                else
                { // evolution d'une cellule morte
                    if ( v==3 ) set_vivante(i,j,*g);
                }
            }
		}

	if (cyclique==0)
	{
	compte_voisins_vivants=compte_voisins_vivants_cyclique;
	}
	else
	{
        compte_voisins_vivants=compte_voisins_vivants_non_cyclique;
	}


	return;
}
