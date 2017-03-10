/*  Prenom NOM 
 */
/* Base: TAI release 2 (25/03/2014) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "limace.h"
#include "tai.h"


#define DEBOGAGE

#ifdef DEBOGAGE
#define DEBUG fprintf(stderr,"Fichier %s, ligne %d\n",__FILE__,__LINE__);
#else
#define DEBUG
#endif

/*
 * Fonction a appeler en debut de main pour initialiser la gestion des erreurs 
 */
char *InitMesg(char *argv[])
{
  static char *Prog=NULL;
  
  if (Prog==NULL)
  {
    if ((Prog=strrchr(argv[0],'/')))
      Prog++;
    else
      Prog=argv[0];
  }
  return Prog;
}

/*
 * Affichage d'un message formate sur stderr
 */
void Mesg(const char *Msg, ...)
{
  va_list Params;

  va_start(Params, Msg);
  vfprintf(stderr, Msg, Params);
  va_end(Params);
}

/*
 * Affichage de la syntaxe d'appel d'un operateur sur stderr
 */
void Usage(char *Syntaxe)
{
  char *Ligne, *Copie;

  Copie=malloc(strlen(Syntaxe)+1);
  strcpy(Copie,Syntaxe);
  Mesg("SYNTAXE\n");
  Ligne=strtok(Copie,"\n");
  while (Ligne!=NULL)
  {
    Mesg("\t%s %s\n",InitMesg(NULL),Ligne);
    Ligne=strtok(NULL,"\n");
  }
  free(Copie);
}

/*
 * Affichage d'un message d'erreur sur stderr
 */
void Erreur(char *Msg)
{
  Mesg("[%s] %s\n",InitMesg(NULL),Msg);
}


/*
 * Inversion d'une image binaire ou de niveaux de gris
 * Entree : image initiale (en niveaux de gris ou binaire)
 * Sortie : Image resultat
 */
Image Inversion(Image Im)
{
	Image Res;
	unsigned char **I,**R;
	int i,j,l,c;
	
	if (ImType(Im)!=BitMap && ImType(Im)!=GrayLevel) return NULL;
	l=ImNbRow(Im); c=ImNbCol(Im);
        I=ImGetI(Im);
	if (ImType(Im)==BitMap)
	{
		Res=ImCAlloc(BitMap,l,c);
		if (Res==NULL) return NULL;
                R=ImGetI(Res);
		for (i=0;i<l;i++)
                       for (j=0;j<c;j++)
                              R[i][j]=!I[i][j];
	}
	else
	{
		Res=ImCAlloc(GrayLevel,l,c);
		if (Res==NULL) return NULL;
                R=ImGetI(Res);
		for (i=0;i<l;i++)
                       for (j=0;j<c;j++)
                              R[i][j]=255-I[i][j];
	}
	return Res;
}

/*
 * Representation d'un histogramme sous forme d'une image
 * Entrees : histogramme et nombre de lignes de l'image resultat
 * Sortie : image resultat
 */
Image Hist2Im(Matrix Hist, int NbLig)
{
	unsigned char **I;
	int *h,i,j,Max=0,NbCol=256;
	Image Resultat;
	
	if (MatType(Hist)!=Int) return NULL;
	Resultat=ImCAlloc(GrayLevel,NbLig,NbCol);
	h=*MatGetInt(Hist);
	for (j=0;j<NbCol;j++)
		if (h[j]>Max) Max=h[j];
	I=ImGetI(Resultat);
	for (j=0;j<256;j++)
		for (i=NbLig-1;i>=(NbLig-NbLig*h[j]/Max);i--)
		    I[i][j]=255;
	return Resultat;	
}
