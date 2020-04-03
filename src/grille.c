/**
* \file grille.c
* \brief fichier src grille.c
* \version 5.0
* \author El Chamaa Omar
*/



#include "../include/grille.h"


void alloue_grille(int l, int c, grille *g)
{

 g->cellules=(int**)malloc((c*sizeof(int*)));

for(int i = 0 ;i<c; i ++ )
    {
        g->cellules[i]=(int*)malloc(l*sizeof(int));
    }
    for(int j = 0 ; j<l ; j++)
    {

        for (int x = 0 ; x<c ;x++)
            {
            g->cellules [x][j]= 0 ;
        }
    }
    g->nbc=c ;
    g->nbl=l ;


}

void libere_grille(grille *g) {
for(int i = 0 ; i<g->nbl;i++)
    {
        free(g->cellules[i]);
    }
    free(g->cellules);

}


void init_grille_from_file (char * filename, grille* g){
	FILE * pfile = NULL;
	pfile = fopen(filename, "r");
	assert (pfile != NULL);

	int i,j,n,l,c,vivantes,nonViables=0;

	fscanf(pfile, "%d", & l);
	fscanf(pfile, "%d", & c);

	alloue_grille(l,c,g);

	fscanf(pfile, "%d", & vivantes);
	for (n=0; n< vivantes; ++n){
		fscanf(pfile, "%d", & i);
		fscanf(pfile, "%d", & j);
		set_vivante(i,j,*g);
	}
	fscanf(pfile, "%d", &nonViables);
		for (n=0; n < nonViables; ++n){
			fscanf(pfile, "%d", & i);
			fscanf(pfile, "%d", & j);
			set_non_viable(i,j,*g);
		}

	fclose (pfile);
	return;
}


void copie_grille (grille gs, grille gd){
	int i, j;
	for (i=0; i<gs.nbl; ++i) for (j=0; j<gs.nbc; ++j) gd.cellules[i][j] = gs.cellules[i][j];
	return;
}


int grilleVide(grille *g)
{

    int i, j;
	for (i = 0; i < g->nbl; i++) {
		for (j = 0; j < g->nbc; j++) {
			if (g->cellules[i][j] > 0) {
				return 0;
			}
		}
	}
	return 1;


}




int grillesEg(grille *g1, grille *g2) {
	int i, j;
	for (i = 0; i < g1->nbl; i++) {
		for (j = 0; j < g1->nbc; j++) {
			if (g1->cellules[i][j] != g2->cellules[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}


int grilleOscillante(grille *g)
{


    int temps = 0;
	grille g1,g2,g3,g4,gt,gs;
	if (grilleVide(g))
	{
        return 0 ;
	}
	else
	{

        int max = 30; // on essaye au plus 30 evolutons avant de dire que la grille ne peut pas etre oscillante
        int delais =10 ; // delais de 10
        int i=0 ;

        while(i<delais){


            while (temps < max) {

                alloue_grille (g->nbl, g->nbc, &gt); //copie temporaire
                copie_grille(*g, gt);



                alloue_grille (g->nbl, g->nbc, &g1); //grille initiale
                copie_grille(*g, g1);


                alloue_grille (g->nbl, g->nbc, &gs); //copie a faire evoluer
                copie_grille(g1, gs);


                evolue(&gs,&gt);


                alloue_grille (g->nbl, g->nbc, &g2); //evolution suivante
                copie_grille(gs, g2);


                evolue(&gs,&gt);


                alloue_grille (g->nbl, g->nbc, &g3);
                copie_grille(gs, g3);


                evolue(&gs,&gt);


                alloue_grille (g->nbl, g->nbc, &g4);
                copie_grille(gs, g4);



                if( (grillesEg(&g1,&g3)==1 )  && (grillesEg(&g2,&g4)==1)   && grillesEg(&g1,&g2)==0 && grillesEg(&g2,&g3)==0)
                    {
                        return temps;
                    }
                else
                    {
                       temps = temps + 3 ;

                    }

                }

                evolue(&g1,&gt);
                i++;
            }



	}
            libere_grille(&g1);
            libere_grille(&g2);
            libere_grille(&g3);
            libere_grille(&g4);
            libere_grille(&gt);
            libere_grille(&gs);
	return -1;


}
