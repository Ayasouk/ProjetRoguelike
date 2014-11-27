
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

main_o:
	mkdir -p $(ODIR)/$(SRCDIR)
	cd $(ODIR)/$(SRCDIR); $(CC) $(OPTIONS) -c ../../$(SRCDIR)/*.c

test: test_o
	$(CC) $(OPTIONS) $(ODIR)/$(TESTDIR)/*.o -o $(NAME)_test.exe

test_o:
	mkdir -p $(ODIR)/$(TESTDIR)
	cd $(ODIR)/$(TESTDIR); $(CC) $(OPTIONS) -c ../../$(TESTDIR)/*.c

run: main
	$(NAME).exe

clean:
	rm -rf $(ODIR)
	rm -f $(NAME).exe

docgen:
	rm -rf $(DOCDIR)
	mkdir $(DOCDIR)
	doxygen
