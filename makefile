vpath %.c src
vpath %.h include
OPATH=obj
SRC=src


exe : $(addprefix $(OPATH)/, main.o io.o grille.o jeu.o)

exe:main.o grille.o io.o jeu.o
	gcc -Wall -g -o exe main.o grille.o io.o jeu.o
$(OPATH)/main.o : main.c
	gcc -Wall -g -c $(SRC)/main.c
$(OPATH)/grille.o : grille.c 
	gcc -Wall -g -c $(SRC)/grille.c
$(OPATH)/io.o : io.c
	gcc -Wall -g -c $(SRC)/io.c
$(OPATH)/jeu.o : jeu.c 
	gcc -Wall -g -c $(SRC)/jeu.c
clean:
	rm -f prog *.o *.xz
	@echo Clean!
dist: 
	tar -J -cvf Jeu_De_La_Vie.tar.xz $(SRC)/*.c  makefile
commit:
	git commit -m "$m"
doxyfile:
	doxygen Doxyfile
	


