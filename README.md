# *Je De La Vie* 


Ce Projet est base sur "Conway's Game of Life". [WIKI](https://fr.wikipedia.org/wiki/Jeu_de_la_vie)


## Fonctionalites Makefile 

- Pour compiler en mode texte, tapez "make MODE=TEXTE".

- Pour compiler, tapez "make".

- Pour generer la documentation doxygen, tapez "doxygen" ou "make doxyfile" , la documentation se trouvera dans le fichier doc .

- Pour generer l'archive , tapez "make dist" .

- Pour 'nettoyer' , tapez "make clean".

## Execution 
- Pour executer en mode texte, tapez "./bin/exe "chemin de la grille souhaitee "".
- Pour executer en mode graphique, tapez "./bin/cairo "chemin de la grille souhaitee "".

## Usage
- Touche "n": permet de charger une nouvelle grille depuis le fichier Grilles.

- Touche "Entree" (mode texte) ou "Clic Droit" (mode Graphique) : permet de faire evoluer la grille.
.
- Touche "v" : Descative/active le vieillissement des cellules. 

- Touche "c" : Desactive/active le voisinage cyclique.

- Touche "o" : Active le test d'oscillation.

#### Bugs 

- Un bug d'affichage mineur a lieu si le terminal n'est pas en plein ecran dans le mode texte.

- Dans le mode graphique, quand on veut rentrer une nouvelle grille avec la touche "n" ,
certaines grilles s'inistialisent pas de la bonne facon.

- Dans le mode graphique, le test d'oscillation marche pas seulement pour la grille 6.


######
NB: Si le code a ete recupere a l'aide de l'archive , apres l'avoir extraite, veuillez bien creer des repertoires vides lib,obj, et doc.






