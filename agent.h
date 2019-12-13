#include<gtk/gtk.h>

typedef struct 
{
 
 char nom[20];
 char prenom[30];
 char date_recrut[30];
 char cin[20];
 char id[20];
 char domaine[30];

} 
agent;
typedef struct ///////
{ 
 int jour;
 int mois;
 int annee;
}Date;
typedef struct//////////
{
 char chnom[30];
 char chprenom[30];
 char chnum[30];
 char chemail[30];
 char chcin[10];
 char chpassword[30];
 
 Date dt_n;
 int num;
}client;

void ajouter_agent(agent p);
void afficher_agent(liste);
void supprimer(liste);

void modifier_agent(char nom[],char prenom[],char date[],char cin[],char cid[],char domaine[]);
void affiche_client(liste);
void supprimer1(liste);
