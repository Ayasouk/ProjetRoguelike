
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


main: main_o
	$(CC) $(OPTIONS) $(ODIR)/$(SRCDIR)/*.o -o $(NAME).exe

main_o: $(ODIR) $(ODIR)/$(SRCDIR)
	cd $(ODIR)/$(SRCDIR); $(CC) $(OPTIONS) -c ../../$(SRCDIR)/*.c

$(ODIR)/$(SRCDIR):
	cd $(ODIR); mkdir $(SRCDIR)

$(ODIR):
	mkdir $(ODIR)

run: main
	$(NAME).exe

clean:
	rm $(ODIR)/$(SRCDIR)/*.o;
	rm $(NAME).exe
