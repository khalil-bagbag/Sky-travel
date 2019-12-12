#include <gtk/gtk.h>


typedef struct
{
int jour ;
int mois ;
int annee ;
}Date ;

typedef struct
{
char ville[50];
char hotel[50];
int etoile;
int prix;
int id ;
int nombre_de_nuit; 
int nombre_de_personne ;
Date dt_res ;
}ReservationHotel;

typedef struct
{
char chnom[30];
char chprenom[30];
char chnum[30];
char chemail[30];
char chcin[30];
char chpassword[30];
Date dt_n ;
int num;
}client;

typedef struct
{
int id;
char cin[50];
char hotel[50];
char ville[50];
int etoile;
Date dt ;
int nombre_de_nuit; 
int nombre_de_personne ;
int prix ;
}Reservation;



int verifier(char CIN[50],char mdp[50]);
int tableau_hotel_disponible(char nom_hotel[50][50],char ville[50],int nombre_de_nuit,int nombre_detoile);
int calcul_prix(char hotel[50],int nombre_de_nuit,int nombre_de_personne);
void modifier_nombre_de_nuit (char hotel[50],int nombre_de_nuit,char CIN[10]);
void reserver_hotel(Reservation c);
void afficher_reservation(GtkWidget *liste, char cin2[50]);
void supprimer_res(char ide[50]);
void modifier_res(char ide[50], int jour,int mois,int annee,int nombre_de_nuit,int nombre_de_personne, int prix);
int verifier_id_existe(char ide[50]);

