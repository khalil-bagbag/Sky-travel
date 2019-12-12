#include<stdio.h>
#include<string.h>
#include "gestion_factures.h"
#include<gtk/gtk.h>
/*fact facture_vol(vols v ,reservation_vol rv)
{
    fact f;

    f.montant_total=v.Prix_vol*rv.nb_per;
    f.montant_TTC=f.montant_total+f.montant_total*0.06;


        return(f);
}
fact facture_hotel(heber h,reservation_hotel rh)
{
    fact f;
    f.montant_total=h.prix*rh.nb_nuit*rh.nb_personnes;
    f.montant_TTC=f.montant_total+f.montant_total*0.06;
    return(f);
}*/
void ajouter_facture(fact f)
{
    FILE*p;
    p=fopen("/home/msx/Projects/menu_facture/src/factures.txt","a+");
    if(p!=NULL)
    fprintf(p,"%s %s %s %d %d %d %s %s %s\n",f.id_fact,f.nom,f.prenom,f.jour,f.mois,f.annee,f.reservation,f.montant_total,f.montant_ttc);
   fclose(p);
}
enum
  {
     ID_FACT,
     NOM,
     PRENOM,
     JOUR,
     MOIS,
     ANNEE,
     RESERVATION,
     MONTANT_TOTAL,
     MONTANT_TTC,
     COLUMNS  
  };
void afficher_facture(GtkWidget *liste)
{
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;
    char id_fact[10];
    char nom[20];
    char prenom[20];
    char jour[10];
    char mois[10];
    char annee[10];
    char reservation[10];
    char montant_total[20];
    char montant_ttc[20];
 store=NULL;
FILE*p;
store=gtk_tree_view_get_model(liste); 
if(store==NULL)
 {
   renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id_fact",renderer,"text",ID_FACT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
   renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
 renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column); renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column); renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("reservation",renderer,"text",RESERVATION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("montant_total",renderer,"text",MONTANT_TOTAL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("montant_ttc",renderer,"text",MONTANT_TTC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
p=fopen("/home/msx/Projects/menu_facture/src/factures.txt","r");

	if(p==NULL)
	{
		return;
	}
	else
	
	{ 
	p=fopen("/home/msx/Projects/menu_facture/src/factures.txt","a+");
		while(fscanf(p,"%s %s %s %s %s %s %s %s %s \n",id_fact,nom,prenom,jour,mois,annee,reservation,montant_total,montant_ttc)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ID_FACT,id_fact,NOM,nom,PRENOM,prenom,JOUR,jour,MOIS,mois,ANNEE,annee,RESERVATION,reservation,MONTANT_TOTAL,montant_total,MONTANT_TTC,montant_ttc,-1);
		}
	   fclose(p);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
 } 
}
void supprimer_facture(char supp[30] )
{
FILE *p;
FILE *p1;
fact f;
p=fopen("/home/msx/Projects/menu_facture/src/factures.txt","r");
p1=fopen("/home/msx/Projects/menu_facture/src/file.txt","a+");
while(fscanf(p,"%s %s %s %d %d %d %s %s %s\n",f.id_fact,f.nom,f.prenom,&f.jour,&f.mois,&f.annee,f.reservation,f.montant_total,f.montant_ttc)!=EOF)
{
	if (strcmp(f.id_fact,supp)!=0)	
	fprintf(p1,"%s %s %s %d %d %d %s %s %s  \n",f.id_fact,f.nom,f.prenom,f.jour,f.mois,f.annee,f.reservation,f.montant_total,f.montant_ttc);
}
fclose(p);
fclose(p1);
remove("/home/msx/Projects/menu_facture/src/factures.txt");
rename("/home/msx/Projects/menu_facture/src/file.txt","/home/msx/Projects/menu_facture/src/factures.txt");
}
void modifier_facture(fact f)
{
    char id_fact1[10];
    char nom1[20];
    char prenom1[20];
    int jour1;
    int mois1;
    int annee1;
    char reservation1[10];
    char montant_total1;
    char montant_ttc1;


FILE *p;
FILE *p1;
int test=-1;



p=fopen("/home/msx/Projects/menu_facture/src/factures.txt","r");
p1=fopen("/home/msx/Projects/menu_facture/src/file.txt","a+");
while(fscanf(p,"%s %s %s %d %d %d %s %s %s\n",id_fact1,nom1,prenom1,&jour1,&mois1,&annee1,reservation1,montant_total1,montant_ttc1)!=EOF)
{
	if (strcmp(f.id_fact,id_fact1)==0)	
	{fprintf(p1,"%s %s %s %d %d %d %s %s %s  \n",f.id_fact,f.nom,f.prenom,f.jour,f.mois,f.annee,f.reservation,f.montant_total,f.montant_ttc);
}
/*else if(strcmp(f.id_fact,id_fact1)!=0){
fprintf(p1,"%s %s %s %d %d %d %s %s %s\n",id_fact1,nom1,prenom1,jour1,mois1,annee1,reservation1,montant_total1,montant_ttc1);	
}*/
}
fclose(p);
fclose(p1);
remove("/home/msx/Projects/menu_facture/src/factures.txt");
rename("/home/msx/Projects/menu_facture/src/file.txt","/home/msx/Projects/menu_facture/src/factures.txt");
}
int verifier (char login[30], char password[30])
{
	FILE* f;
	char prenom[30],date_recrut[30],id[20],domaine[30];
	char nom[30];
	char motdepasse[30];
	int t=0;
	f=fopen("agent.txt","r");
	if(f !=NULL)
	{
		while(fscanf(f,"%s %s %s %s %s %s \n",nom,prenom,date_recrut,motdepasse,id,domaine)!=EOF)
		{
			if(strcmp(login,nom)==0&&strcmp(password,motdepasse)==0)
			{
				
						t=1;
					
			}
		}
		fclose(f);
		
	}
return(t);
}
