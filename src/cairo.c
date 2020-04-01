
#include <stdio.h>
#include <stdlib.h>
#include <cairo.h>
#include <cairo-xlib.h>
#include <X11/Xlib.h>
#include "grille.h"
#include "jeu.h"
#include "io.h"

#define SIZEX 600
#define SIZEY 750

/**
* \file cairo.c
* \brief fichier src cairo.c
* \version 4.0
* \author El Chamaa Omar
*/




void paint(cairo_surface_t *surface, grille g)
{
	// create cairo mask
	cairo_t *cr;
	cr=cairo_create(surface);

	// background
	cairo_set_source_rgb (cr, 1.0, 1.0, 1.0);
	cairo_paint(cr);

	//texte
	cairo_set_source_rgb(cr, 0.1, 0.1, 0.1);
	cairo_select_font_face(cr, "Open Sans", CAIRO_FONT_SLANT_NORMAL,
      CAIRO_FONT_WEIGHT_BOLD);
	cairo_set_font_size(cr, 30);

	cairo_move_to(cr, 200, 40);
	cairo_show_text(cr, "Jeu de la vie");

	cairo_set_font_size(cr, 15);
	cairo_move_to(cr, 10, 100);
	if(cyclique==1 )
    {
        cairo_show_text(cr, "Mode cyclique activé");
    }

	else
    {
        cairo_show_text(cr, "Mode cyclique désactivé");
    }


	cairo_move_to(cr, 350, 100);
	if(vieux==1)
		cairo_show_text(cr, "Vieillissement activé");
	else
		cairo_show_text(cr, "Vieillissement désactivé");


    char temps[200];
    cairo_move_to(cr,200,140);
    sprintf(temps,"Temps evolutions : %d ",nb_evolutions);
    cairo_show_text(cr,temps);


	/*// line
	cairo_set_source_rgb (cr, 1.0, 0.0, 0.0);
	cairo_move_to (cr, 150.0, 160.0);
	cairo_line_to(cr, 150.0, 150.0);
	cairo_set_line_width (cr, 10);
	cairo_stroke (cr);
*/

	// rectangle
	cairo_rectangle(cr,0,200,600,600);
	cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
	cairo_fill(cr);


	// filled rectangle
	int x, y, width, height;
	width = (SIZEX-5)/g.nbc-5;
	height = (SIZEY-205)/g.nbl-5;
	for (int i=0;i < g.nbl;i++){
		for (int j=0;j<g.nbc;j++){
			x=5+j*(width+5);
			y=205+i*(height+5);
			cairo_rectangle(cr, x, y, width, height);
			if(g.cellules[i][j]==0)
				cairo_set_source_rgb (cr, 0.75, 0.75, 0.75);

			else if(g.cellules[i][j]>1){
				cairo_set_source_rgb(cr, 0.06, 0.18, 0.35);


				}

			else if (g.cellules[i][j]==-1)
				cairo_set_source_rgb (cr, 1.0, 0.0, 0.0);

			else
				cairo_set_source_rgb (cr, 0.47, 0.54, 0.65);

			cairo_fill(cr);
		}
    }





	cairo_destroy(cr); // destroy cairo mask
}





int main (int argc, char *argv[]){
	// X11 display
	Display *dpy;
	Window rootwin;
	Window win;
	XEvent e;
	int scr;

	// init grille
    if (argc != 2 ){
		printf("usage : main <fichier grille>");
		return 1;
	}

	grille g;
	grille gc;
	init_grille_from_file(argv[1],&g);
	alloue_grille (g.nbl, g.nbc, &gc);

	//int (*compte_voisins_vivants)(int,int,grille) = compte_voisins_vivants_cyclique;





	// init the display
	if(!(dpy=XOpenDisplay(NULL))) {
		fprintf(stderr, "ERROR: Could not open display\n");
		exit(1);
	}

	scr=DefaultScreen(dpy);
	rootwin=RootWindow(dpy, scr);

	win=XCreateSimpleWindow(dpy, rootwin, 1, 1, SIZEX, SIZEY, 0,
			BlackPixel(dpy, scr), BlackPixel(dpy, scr));

	XStoreName(dpy, win, "jeu de la vie");
	XSelectInput(dpy, win, ExposureMask|KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask);

	XMapWindow(dpy, win);

	// create cairo surface
	cairo_surface_t *cs;
	cs=cairo_xlib_surface_create(dpy, win, DefaultVisual(dpy, 0), SIZEX, SIZEY);




	// run the event loop
	while(1) {
		XNextEvent(dpy, &e);
		if(e.type==Expose && e.xexpose.count<1) {
			paint(cs,g);
		}
		else if(e.type==ButtonPress){
			     if(e.xbutton.button==1){
			       evolue(&g,&gc);
			       efface_grille(g);
			       nb_evolutions ++ ;
				   paint(cs,g);
				   affiche_grille(g);
			     }
			     if(e.xbutton.button==3){
					 break;
			     }
		}

		if(e.type==KeyPress){
			if(e.xkey.keycode==XKeysymToKeycode(dpy,'n')){
				// touche "n" pour ouvrir une nouvelle grille

                    printf("Entrez le chemin de la nouvelle grille: ");
                    char new_grille[50];
                    scanf("%s",new_grille);

					init_grille_from_file(new_grille, &g);
					alloue_grille (g.nbl, g.nbc, &gc);
					nb_evolutions = 0 ;
					while (getchar()!='\n');
					paint(cs,g);
					affiche_grille(g);

			}
			else
            {

			if(e.xkey.keycode==XKeysymToKeycode(dpy,'c')){
				// touche "c" pour activer/désactiver le voisinage cyclique

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


            }
                if(e.xkey.keycode==XKeysymToKeycode(dpy,'v'))
                {
				// touche "v" pour activer ou désactiver le vieillissement
					if (vieux==0){

                                vieux=1;

					}
					else{
                                vieux = 0;
					}

                }



                }



		}
	}



    libere_grille(&g);
    libere_grille(&gc);


	cairo_surface_destroy(cs); // destroy cairo surface
	XCloseDisplay(dpy); // close the display
	return 0;
}
