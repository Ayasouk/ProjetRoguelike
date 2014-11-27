
#le compilateur c utilisé
CC = gcc

#les options à la compilations
OPTIONS = -Wall -Wextra

#le nom du programme
NAME = roguelike

#le nom du dossier contenant les fichiers .o générés lors de la compilation
ODIR = o

#le nom du dossier contenant les sources
SRCDIR = src

#le nom du dossier contenant les sources des tests
TESTDIR = test

#le nom du dossier contenant la documentation
DOCDIR = doc


main: main_o
	$(CC) $(OPTIONS) $(ODIR)/$(SRCDIR)/*.o -o $(NAME).exe

main_o: $(ODIR) $(ODIR)/$(SRCDIR)
	mkdir -p $(ODIR)/$(SRCDIR)
	cd $(ODIR)/$(SRCDIR); $(CC) $(OPTIONS) -c ../../$(SRCDIR)/*.c

run: main
	$(NAME).exe

clean:
	rm -f $(ODIR)/$(SRCDIR)/*.o;
	rm -f $(NAME).exe

docgen:
	mkdir -p $(DOCDIR)
	rmdir $(DOCDIR)/* --ignore-fail-on-non-empty
	doxygen

all: clean main docgen
