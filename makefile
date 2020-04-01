.PHONY: all clean

vpath %.c src
vpath %.h include
OPATH=obj


CFLAGS += -Og -g -Wall -Wextra
CPPFLAGS += -Iinclude -I/usr/include/cairo
LDFLAGS += -lcairo -lm -lX11

#all : bin/cairo bin/test 

ifeq (TEXTE,$(MODE))

bin/exe : $(addprefix $(OPATH)/, main.o io.o grille.o jeu.o)
		$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
        
$(OPATH)/main.o : main.c io.h grille.h jeu.h
$(OPATH)/io.o : io.c io.h grille.h jeu.h
$(OPATH)/jeu.o : jeu.c jeu.h grille.h
$(OPATH)/grille.o : grille.c grille.h
        
$(OPATH)/%.o : %.c | $(OPATH)
		$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


else


bin/cairo : $(addprefix $(OPATH)/, cairo.o io.o grille.o jeu.o)
		$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
        
$(OPATH)/cairo.o : cairo.c io.h grille.h jeu.h
$(OPATH)/io.o : io.c io.h grille.h jeu.h
$(OPATH)/jeu.o : jeu.c jeu.h grille.h
$(OPATH)/grille.o : grille.c grille.h
        
$(OPATH)/%.o : %.c | $(OPATH)
		$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

endif




clean:
	rm -f prog obj/*.o *.xz bin/exe bin/cairo 
	@echo Clean!
dist: 
	tar -J -cvf ElChamaaOmar-GoL-v2.0.tar.xz $(SRC)/*.c  makefile Doxyfile include/*.h 
commit:
	git commit -m "$m"
doxyfile:
	doxygen 
	


