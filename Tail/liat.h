char* allocation();
int compteurligne(FILE *fichier, char *chemin, char *tab) ;
void tail_n(FILE* fichier, int nombreligne, int nombre, char *tab);
void tail_v(char *chemin, FILE* fichier, int nombreligne, int nombre, char *tab);
void tail_c(FILE* fichier, int nombreligne, int nombre, char *tab);
void tail_f(char *chemin, int nombreligne, int nombre, char *tab);
void argument(int argc, char *argv[], char *chemin, FILE* fichier, int nombreligne, int nombre, char *tab);
void version(char *argv[], int argc);

