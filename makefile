.PHONY: all clean

vpath %.c src
vpath %.h include
OPATH=obj


CFLAGS += -Og -g -Wall -Wextra




bin/exe : $(addprefix $(OPATH)/, main.o io.o grille.o jeu.o)
		$(CC) -o $@ $^ $(CFLAGS) 
        
$(OPATH)/main.o : main.c io.h grille.h jeu.h
$(OPATH)/io.o : io.c io.h grille.h jeu.h
$(OPATH)/jeu.o : jeu.c jeu.h grille.h
$(OPATH)/grille.o : grille.c grille.h
        
$(OPATH)/%.o : %.c | $(OPATH)
		$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f prog obj/*.o *.xz bin/exe 
	@echo Clean!
dist: 
	tar -J -cvf ElChamaaOmar-GoL-v2.0.tar.xz $(SRC)/*.c  makefile Doxyfile include/*.h 
commit:
	git commit -m "$m"
doxyfile:
	doxygen 
	


