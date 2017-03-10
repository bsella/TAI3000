# Prenom NOM 
# Description des dependances du mini-projet de la partie TAI de AII3D
#
# Pour lancer les compilations, tapez :
# make
# Pour effacer tous les fichiers objets et executables, tapez :
# make clean
# Pour prendre en compte un nouvel operateur, ajoutez-le aux 4 endroits designes par -->
# ci-dessous.

# Ne modifiez pas cette partie 
# Exception : en cas de refus de l'option -Wpedantic, la remplacer par -pedantic
CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c90 -Wpedantic
LDFLAGS= $(CFLAGS)
LDLIBS=-lm
RM=rm -f

# --> ci-dessous, ajoutez a la suite les noms des fichiers objets de vos operateurs 
# separes par un espace
OBJECTS=limace.o tai.o inversion.o hist2im.o 

# --> ci-dessous, ajoutez a la suite les noms des fichiers executables de vos operateurs 
# separes par un espace
EXE=inversion hist2im 

# Ne modifiez pas cette partie
.PHONY: all
all: $(EXE)

# Dependances non implicites des executables
OBJ=limace.o tai.o
inversion: $(OBJ) inversion.o 
hist2im: $(OBJ) hist2im.o
# --> ajoutez ici une ligne par operateur


# Dependances non implicites des objets
HEAD= limace.h tai.h
limace.o: limace.h
tai.o: $(HEAD)
inversion.o: $(HEAD)
hist2im.o: $(HEAD)
# --> ajoutez ici une ligne par operateur


# Ne modifiez pas cette partie
clean:
	$(RM) $(OBJECTS) $(EXE)
