
.PHONY: all clean

vpath %.c src
vpath %.h include
OPATH=obj
LIBPATH=lib

CFLAGS += -Og -g -Wall -Wextra
CPPFLAGS += -Iinclude -I/usr/include/cairo
LDFLAGS += -lcairo -lm -lX11 -L lib/ -ljeu 

#all : bin/cairo bin/test 

ifeq (TEXTE,$(MODE))

bin/exe : $(addprefix $(OPATH)/, main.o io.o grille.o jeu.o) $(addprefix $(LIBPATH)/,libjeu.a)
		$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
        
$(OPATH)/main.o : main.c io.h grille.h jeu.h
$(OPATH)/io.o : io.c io.h grille.h jeu.h
$(OPATH)/jeu.o : jeu.c jeu.h grille.h
$(OPATH)/grille.o : grille.c grille.h
$(LIBPATH)/libjeu.a : 
	ar -crv lib/libjeu.a $(OPATH)/jeu.o $(OPATH)/grille.o
	ranlib lib/libjeu.a

	
$(OPATH)/%.o : %.c | $(OPATH)
		$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


else


bin/cairo : $(addprefix $(OPATH)/, cairo.o io.o grille.o jeu.o) $(addprefix $(LIBPATH)/,libjeu.a)
		$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
        
$(OPATH)/cairo.o : cairo.c io.h grille.h jeu.h
$(OPATH)/io.o : io.c io.h grille.h jeu.h
$(OPATH)/jeu.o : jeu.c jeu.h grille.h
$(OPATH)/grille.o : grille.c grille.h
$(LIBPATH)/libjeu.a :
	ar -crv lib/libjeu.a $(OPATH)/jeu.o $(OPATH)/grille.o
	ranlib lib/libjeu.a

        
$(OPATH)/%.o : %.c | $(OPATH)
		$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

endif




clean:
	rm -f prog obj/*.o *.xz bin/exe bin/cairo  lib/*.a
	@echo Clean!
dist: 
	tar -J -cvf ElChamaaOmar-GoL-v5.0.tar.xz src  makefile Doxyfile include
commit:
	git commit -m "$m"
doxyfile:
	doxygen 
	


