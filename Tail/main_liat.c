#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "liat.c"

int main(int argc, char *argv[])
{

	char *tab = NULL;
	char *chemin = NULL;
	version(argv, argc);
    FILE *fichier = NULL;
	tab = allocation();
	chemin = allocation();
    strcpy(chemin, argv[argc-1]);
    fichier = fopen(chemin, "r");
    int nombre = 10;
    int nombreligne = 0;
	nombreligne = compteurligne(fichier, chemin, tab);

	argument(argc, argv, chemin, fichier, nombreligne, nombre, tab); 
	
	fclose(fichier);
	
	free(tab);
	free(chemin);
   
    return (0);
}

