#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fn.h" 
#include <gtk/gtk.h>

/* cette fonction permet de verifier si un client existe dans le fichier client.txt */
int verifier(char CIN[50],char mdp[50])
{

int n=0;
client c;




FILE* f=fopen("client.txt","r");


if(f!=NULL)
{
   while(fscanf(f,"%s %s %s %s %s %s %d %d %d %d ",c.chnom,c.chprenom,c.chnum,c.chemail,c.chcin,c.chpassword,&c.dt_n.jour,&c.dt_n.mois,&c.dt_n.annee,&c.num)!=EOF)
    { 
       if (strcmp(c.chcin,CIN)==0 && strcmp(c.chpassword,mdp)==0 )
         { 
                   
                  n=1;                
         }
       
     }
}
fclose(f);
return n;
}




/* Fonction qui permet de recherhcer un hotel disponible selon le nombre detoile de lhotel la ville et nombre de nuit ( si il y a assez de place ou pas ) */

int tableau_hotel_disponible(char nom_hotel[50][50],char ville[50],int nombre_de_nuit,int nombre_detoile)
{
int i,nH=0;
ReservationHotel h;




FILE* f=fopen("hotelReserve.txt","r");


if(f!=NULL)
{
   while(fscanf(f,"%s %s %d %d %d %d",h.hotel,h.ville,&h.etoile,&h.prix,&h.id,&h.nombre_de_nuit)!=EOF)
    { 
       if (strcmp(h.ville,ville)==0 && h.nombre_de_nuit>nombre_de_nuit && h.etoile==nombre_detoile)
         { 
                  strcpy(nom_hotel[nH],h.hotel) ;
                  nH++;                
         }
       
     }
}
fclose(f);
return nH;
}


/* Fonction qui calcule le prix de n nuit de n personne dans un hotel choisis*/

int calcul_prix(char hotel[50],int nombre_de_nuit,int nombre_de_personne)
{ int prix , total ;
ReservationHotel h;




FILE* f=fopen("hotelReserve.txt","r");


if(f!=NULL)
{
   while(fscanf(f,"%s %s %d %d %d %d",h.hotel,h.ville,&h.etoile,&h.prix,&h.id,&h.nombre_de_nuit)!=EOF)
    { 
       if (strcmp(h.hotel,hotel)==0)
         { 
             prix=h.prix ;               
         }
 
     }
}
fclose(f);

 total=prix*nombre_de_nuit*nombre_de_personne ;


 return total ;
}

/* cette fonction permet de decrementer le nombre de nuit selectiones pour un hotel du fichier hotelreseerve.txt et de rajouter une reservation pour le client dans le fichier client.txt */



void modifier_nombre_de_nuit (char hotel[50],int nombre_de_nuit,char CIN[10])
{
ReservationHotel h;
client c;



FILE* f=fopen("hotelReserve.txt","r");
FILE* f1=fopen("tempo.txt","a+");


if(f!=NULL)
{
   while(fscanf(f,"%s %s %d %d %d %d",h.hotel,h.ville,&h.etoile,&h.prix,&h.id,&h.nombre_de_nuit)!=EOF)
    { 
       if (strcmp(h.hotel,hotel)==0)
         { 
       fprintf(f1,"%s %s %d %d %d %d \n",h.hotel,h.ville,h.etoile,h.prix,h.id,h.nombre_de_nuit=h.nombre_de_nuit-nombre_de_nuit);              
         }
     else
       fprintf(f1,"%s %s %d %d %d %d \n",h.hotel,h.ville,h.etoile,h.prix,h.id,h.nombre_de_nuit);
	}
     
}
fclose(f1);
fclose(f);
rename("tempo.txt","hotelReserve.txt");


FILE* f2=fopen("client.txt","r");
FILE* f3=fopen("tempo1.txt","a+");


if(f!=NULL)
{
   while(fscanf(f2,"%s %s %s %s %s %s %d %d %d %d ",c.chnom,c.chprenom,c.chnum,c.chemail,c.chcin,c.chpassword,&c.dt_n.jour,&c.dt_n.mois,&c.dt_n.annee,&c.num)!=EOF)
    { 
       if (strcmp(c.chcin,CIN)==0)
         { 
       fprintf(f3,"%s %s %s %s %s %s %d %d %d %d \n",c.chnom,c.chprenom,c.chnum,c.chemail,c.chcin,c.chpassword,c.dt_n.jour,c.dt_n.mois,c.dt_n.annee,c.num=c.num+1);              
         }
     else
       fprintf(f3,"%s %s %s %s %s %s %d %d %d %d \n",c.chnom,c.chprenom,c.chnum,c.chemail,c.chcin,c.chpassword,c.dt_n.jour,c.dt_n.mois,c.dt_n.annee,c.num);
	}
     
}
fclose(f2);
fclose(f3);
rename("tempo1.txt","client.txt");

}

/* Cette fonction permet d'ajouter une reservation dans un fichier reservation.txt */

void reserver_hotel(Reservation c)
{ int n=0 ;
  Reservation c1;
  
  FILE* f=fopen("reservation.txt","r");
  if(f!=NULL)
  {
   while(fscanf(f,"%d %s %s %s %d %d %d %d %d %d %d",&c1.id,c1.cin,c1.hotel,c1.ville,&c1.etoile,&c1.dt.jour,&c1.dt.mois,&c1.dt.annee,&c1.nombre_de_nuit,&c1.nombre_de_personne,&c1.prix)!=EOF)
{n++;}
   fclose(f);
   }
   n = c1.id + 1;
  FILE* f1=fopen("reservation.txt","a+");
  if(f!=NULL)
  {
   fprintf(f1,"%d %s %s %s %d %d %d %d %d %d %d \n",n,c.cin,c.hotel,c.ville,c.etoile,c.dt.jour,c.dt.mois,c.dt.annee,c.nombre_de_nuit,c.nombre_de_personne,c.prix);
   fclose(f1);
  }

}




enum{
ID,
CIN,
HOTEL,
VILLE,
NOMBREETOILE,
JOUR,
MOIS,
ANNEE,
NOMBRENUIT,
NOMBREPERSONNE,
PRIXTOTAL,
COLUMNS
};

/* cette fonction permet d'afficher a partir un fichier reservation.txt les resrvation dun client */
void afficher_reservation(GtkWidget *liste, char cin2[50])
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char id[30];
char cin[30];
char hotel [30];
char ville [30];
char nombre_etoile [30];
char jour [30];
char mois [30];
char annee[30];
char nombre_de_nuit[30];
char nombre_de_personne [30];
char prix_total [30];

store =NULL;




FILE *f;

store = gtk_tree_view_get_model(liste);

if (store == NULL) 
{

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Id",renderer, "text", ID, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("CIN",renderer, "text", CIN, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Hotel",renderer, "text", HOTEL, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Ville",renderer, "text", VILLE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nombre d'etoile",renderer, "text", NOMBREETOILE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Jour",renderer, "text", JOUR, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Mois",renderer, "text", MOIS, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Annee",renderer, "text", ANNEE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nombre de nuit",renderer, "text", NOMBRENUIT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nombre de personne",renderer, "text", NOMBREPERSONNE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Prix total",renderer, "text", PRIXTOTAL, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

f = fopen("reservation.txt", "r");

if(f==NULL)
{
return;
}
else
 {
	f = fopen("reservation.txt", "a+");
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s \n",id,cin,hotel,ville,nombre_etoile,jour,mois,annee,nombre_de_nuit, nombre_de_personne,prix_total)!=EOF)
{
          if (strcmp(cin,cin2)==0)
		{gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter,ID,id,CIN,cin, HOTEL,hotel, VILLE, ville, NOMBREETOILE,nombre_etoile,JOUR,jour,MOIS,mois,ANNEE,annee, NOMBRENUIT,nombre_de_nuit, NOMBREPERSONNE,nombre_de_personne, PRIXTOTAL, prix_total,-1);}

	}

	fclose(f);

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store)); 	
	g_object_unref(store);	
      }
}
}

void supprimer_res(char ide[50])
{
 Reservation c ;
 FILE *f;
 FILE *f2;
char id[50];

f=fopen("reservation.txt","r");
f2=fopen("reservation1.txt", "a+");

while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d \n",id,c.cin,c.hotel,c.ville,&c.etoile,&c.dt.jour,&c.dt.mois,&c.dt.annee,&c.nombre_de_nuit, &c.nombre_de_personne,&c.prix)!=EOF)
            
               if(strcmp(id,ide)!=0)

                         fprintf(f2,"%s %s %s %s %d %d %d %d %d %d %d \n",id,c.cin,c.hotel,c.ville,c.etoile,c.dt.jour,c.dt.mois,c.dt.annee,c.nombre_de_nuit, c.nombre_de_personne,c.prix);
                         
                               

                      
              
fclose(f2);
 fclose(f);
 rename("reservation1.txt","reservation.txt");

}

void modifier_res(char ide[50], int jour,int mois,int annee,int nombre_de_nuit,int nombre_de_personne, int prix)
{
Reservation c1;
char id[50];


FILE* f=fopen("reservation.txt","r");
FILE* f1=fopen("tempo.txt","a+");


if(f!=NULL)
{
   while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d",id,c1.cin,c1.hotel,c1.ville,&c1.etoile,&c1.dt.jour,&c1.dt.mois,&c1.dt.annee,&c1.nombre_de_nuit,&c1.nombre_de_personne,&c1.prix)!=EOF)
    { 
       if (strcmp(id,ide)==0)
         { 
       fprintf(f1,"%s %s %s %s %d %d %d %d %d %d %d \n",id,c1.cin,c1.hotel,c1.ville,c1.etoile,jour,mois,annee,nombre_de_nuit,nombre_de_personne,prix);              
         }
     else
       fprintf(f1,"%s %s %s %s %d %d %d %d %d %d %d \n",id,c1.cin,c1.hotel,c1.ville,c1.etoile,c1.dt.jour,c1.dt.mois,c1.dt.annee,c1.nombre_de_nuit,c1.nombre_de_personne,c1.prix);
	}
     
}
fclose(f1);
fclose(f);
rename("tempo.txt","reservation.txt");




}

int verifier_id_existe(char ide[50])
{

int n=0;
Reservation c1;
char id[50];


FILE* f=fopen("reservation.txt","r");


if(f!=NULL)
{
   while(fscanf(f,"%s %s %s %s %d %d %d %d %d %d %d",id,c1.cin,c1.hotel,c1.ville,&c1.etoile,&c1.dt.jour,&c1.dt.mois,&c1.dt.annee,&c1.nombre_de_nuit,&c1.nombre_de_personne,&c1.prix)!=EOF)
    { 
       if (strcmp(id,ide)==0 )
         { 
                   
                  n=1;                
         }
       
     }
}
fclose(f);
return n;
}






