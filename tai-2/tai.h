/*  Prenom NOM 
 */
/* Base: TAI release 2 (25/03/2014) */
#ifndef __tai_h_
#define __tai_h_

#include <stddef.h>
#include "limace.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Fonction a appeler en debut de main pour initialiser la gestion des erreurs */
extern char *InitMesg(char *argv[]);

/* Affichage d'un message formate sur stderr */
extern void Mesg(const char *Msg, ...);

/* Affichage de la syntaxe d'appel d'un operateur sur stderr */
extern void Usage(char *Syntaxe);

/* Affichage d'un message d'erreur sur stderr */
extern void Erreur(char *Msg);

/*
 * Inversion d'une image binaire ou de niveaux de gris
 * Entree : image initiale (en niveaux de gris ou binaire)
 * Sortie : Image resultat
 */
extern Image Inversion(Image Im);

/*
 * Representation d'un histogramme sous forme d'une image
 * Entrees : histogramme et nombre de lignes de l'image resultat
 * Sortie : image resultat
 */
extern Image Hist2Im(Matrix Hist, int NbLig);

/* --> Ajoutez ici les en-tetes des fonctions de la bibliothèque */






#ifdef __cplusplus
}
#endif


#endif /* !__tai_h_ */
