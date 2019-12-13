#include <gtk/gtk.h>

typedef struct
{
char hotel[20];
char ville[20];
char etoile[30];
int prix;
char id[20];
int resv;


}heber;

void ajouter_heber(heber p);
void supprimer1_heber(char ide[]);
void afficher_heber(GtkWidget *liste);
void supprimer_heber(GtkWidget *liste);
heber chercher_heber(char ide[]);
int verifier_id(char ide[]);


