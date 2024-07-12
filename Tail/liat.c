#include "liat.h"

char* allocation() {

	char *tab = NULL;
	tab = malloc(200*sizeof(char));
	if (tab == NULL)
	{
		printf("Erreur d'allocation");
	}
	return tab;
	
}

int compteurligne(FILE *fichier, char *chemin, char *tab) 
{
	int i = 0;
	if(fichier == NULL) 
	{
		printf("Erreur d'ouverture du fichier");
		exit(1);
	}
	while(!feof(fichier)) 
	{	
		fgets(tab, 200, fichier);
		i++;
	}
		
	rewind(fichier);
	
	return i;
}

void tail_n(FILE* fichier, int nombreligne, int nombre, char *tab)
{

	int i = 0;
	while(!feof(fichier)) 
	{	
		fgets(tab, 200, fichier);
		if(i >= nombreligne-nombre-1 && i < nombreligne-1)
		{
			printf("%s", tab);
		}
		i++;
	}
	
}

void tail_v(char *chemin, FILE* fichier, int nombreligne, int nombre, char *tab)
{

	printf("==> %s <==\n", chemin);
	tail_n(fichier, nombreligne, nombre, tab);	
	
}

void tail_c(FILE* fichier, int nombreligne, int nombre, char *tab)
{

	int a = 0;
	int b = 0;
	int nombrecaractere = 0;
	while(!feof(fichier)) 
	{	
		a = fgetc(fichier);
		nombrecaractere++;
	}
	rewind(fichier);
	while(!feof(fichier)) 
	{	
		a = fgetc(fichier);
		if(b >= nombrecaractere-nombre-1 && b < nombrecaractere-1)
		{
			printf("%c", a);
		}
		b++;
	}
}

void tail_f(char *chemin, int nombreligne, int nombre, char *tab)
{

	while(1)
	{
		FILE* fichier = fopen(chemin, "r");
		int n = compteurligne(fichier, chemin, tab);
		tail_n(fichier, n, nombre, tab);
		fclose(fichier);
		system("sleep 1; clear");
		rewind(fichier);
	}
	
}

void argument(int argc, char *argv[], char *chemin, FILE* fichier, int nombreligne, int nombre, char *tab) 
{	
	
	int nombrearg = argc;
	for(int i = 1; i < nombrearg; i++) 
	{
		if(strcmp(argv[i], "-n") == 0)
		{
			nombre = atoi(argv[i+1]);
			tail_n(fichier, nombreligne, nombre, tab);
		}
		else if(strcmp(argv[i], "-c") == 0)
		{
			nombre = atoi(argv[i+1]);
			tail_c(fichier, nombreligne, nombre, tab);
		}
		else if(strcmp(argv[i], "-f") == 0)
		{
			nombre = atoi(argv[i+1]);
			tail_f(chemin, nombreligne, nombre, tab);
		}
		else if(strcmp(argv[i], "-v") == 0)
		{
			nombre = atoi(argv[i+1]);
			tail_v(chemin, fichier, nombreligne, nombre, tab);
		}
		
	}
	
}

void version(char *argv[], int argc) 
{
	int i = 0;
	for(i = 0; i < argc; i++)
	{
		if(strcmp(argv[i], "--version") == 0)
		{
			printf("Copyright ©© by Ny Aina Nirina\n");
			exit(0);
		}
		else if(strcmp(argv[i], "--help") == 0)
		{
			printf("Utilisation : executable [OPTION]... [FICHIER]...\n");
			printf("Afficher les 10 dernieres lignes de chaque FICHIER sur la sortie standard.\n");
			printf("Les arguments disponible :\n");
			printf("-c N,       afficher les N derniers octets ; -c +N peut aussi\n");
			printf("                            être utilise pour afficher les octets a partir du\n");
			printf("                            Nieme de chaque fichier\n");
			printf(" -f, ");
			printf("                         afficher les donnees ajoutees au fur et a mesure\n");
			printf("                             que le fichier grandit ; sans argument, c’est\n");
			printf("                             equivalent a 'descriptor'\n");
			printf(" -n N,         afficher les N dernieres lignes, au lieu des 10\n");
			printf("                             dernieres, -n +N pour afficher a partir de la Nieme\n");
			printf(" -v, --verbose            afficher toujours les en-têtes des noms de fichier\n");
			printf("     --help     afficher l'aide et quitter\n");
			printf("--version  afficher des informations de version et quitter\n\n");
		}
	}
	
}

