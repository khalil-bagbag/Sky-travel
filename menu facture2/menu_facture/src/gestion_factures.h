#include<gtk/gtk.h>
typedef struct
{
    char id_fact[20];
    char nom[20];
    char prenom[20];
    int jour;
    int mois;
    int annee;
    char reservation[20];
    char montant_total[20];
    char montant_ttc[20];


}fact;
/*typedef struct
{
    char id_vol[30];
    char id_client[30];
    char id_res_vol[30];
    int nb_per;
}reservation_vol;
typedef struct
{
    char num[5];
    char region[30];
    int nb_nuit;
    int nb_personnes;
}ReservationHotel;
typedef struct
{
    char Ville_depart[40];
    char Ville_arrive[40];
    char Date_depart[40];
    char Duree_vol[5];
    char Classe[40];
    char Nbre_voyageurs[3];
    float Prix_vol;
    char Id_vol[40];

}vols;
typedef struct
{
    char ville[20];
    char hotel[20];
    char etoile[30];
    float prix;
    char id_hotel[30];
}heber;
typedef struct
{
  char chnom[30];
  char chprenom[30];
  char chnum[30];
  char chcin[10];
  char chpassword[30];
  char num[5];

}client;
fact facture_vol(vols v ,reservation_vol rv);
fact facture_hotel(heber h,reservation_hotel rh);*/
void ajouter_facture(fact f);
void supprimer_facture(char supp[30]);
void modifier_facture(fact f);
void afficher_facture(GtkWidget *liste);
int verifier (char login[30], char password[30]);
