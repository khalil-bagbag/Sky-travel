#include <string.h>
#include "agent.h"
#include <stdio.h>
#include<gtk/gtk.h>






void ajouter_agent(agent p)
{

 FILE*f;
 f=fopen("/home/chayma/Projects/project6/src/agent.txt","a");
 if (f!=NULL);
  {
   fprintf(f,"%s %s %s %s %s %s \n",p.nom,p.prenom,p.date_recrut,p.cin,p.id,p.domaine);
   fclose(f);
}}
void afficher_agent(GtkWidget *liste)
{
enum
{
	
	NOM,
	PRENOM,
	DATE,
	CIN,
	ID,
        DOMAINE,
	
	COLUMNS
};
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore *store;

	char nom[30];
	char prenom[30];
	char date[30];
	char cin[30];
	char id[30];
	char domaine[30];
        
	store=NULL;
	FILE*f;
	
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	 {
		renderer=gtk_cell_renderer_text_new ();
       		column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
        	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        	renderer=gtk_cell_renderer_text_new ();
        	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
        	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        	renderer=gtk_cell_renderer_text_new ();
        	column=gtk_tree_view_column_new_with_attributes("date_recrut",renderer,"text",DATE,NULL);
        	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        	renderer=gtk_cell_renderer_text_new ();
        	column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
        	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        	renderer=gtk_cell_renderer_text_new ();
        	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
        	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		renderer=gtk_cell_renderer_text_new ();
        	column=gtk_tree_view_column_new_with_attributes("domaine",renderer,"text",DOMAINE,NULL);
        	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
                renderer=gtk_cell_renderer_text_new ();
        	
       }
        store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
        f = fopen("agent.txt","r");
        if(f==NULL)
        {
            return;
        }
        else
        {f = fopen("agent.txt","a+");
                while(fscanf(f,"%s %s %s %s %s %s \n",nom,prenom,date,cin,id,domaine)!=EOF)
            {

        gtk_list_store_append(store,&iter);
        gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,DATE,date,CIN,cin,ID,id,DOMAINE,domaine,-1);
            }
            fclose(f);
        gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref (store);
        }
}
void supprimer(GtkWidget *liste)

{
enum
{
	
	NOM,
	PRENOM,
	DATE,
	CIN,
	ID,
        DOMAINE,
	
	COLUMNS
};
 GtkTreeSelection *selection; 
 GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;
  gchar *cin;
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(liste));
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
model = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), 
         &model, &iter)) {
    
    gtk_tree_model_get(model,&iter,CIN,&cin,-1);
    gtk_list_store_remove(store, &iter);

 }

FILE *f;
FILE *ftemp;
ftemp=fopen("ftemp.txt","w");
f=fopen("agent.txt","r");
agent p;

if(f!=NULL)
 {
  if(ftemp!=NULL)
{
 while(fscanf(f,"%s %s %s %s %s %s  \n",p.nom,p.prenom,p.date_recrut,p.cin,p.id,p.domaine)!=EOF)
{
 if (strcmp(cin,p.cin)!=0)
{
fprintf(ftemp,"%s %s %s %s %s %s \n",p.nom,p.prenom,p.date_recrut,p.cin,p.id,p.domaine);

 
}}
fclose(ftemp);}
fclose(f);}

      remove("agent.txt");
      rename("ftemp.txt","agent.txt");

}


  
void modifier_agent(char nom[],char prenom[],char date[],char cin[],char cid[],char domaine[])
{
   FILE *f;
   FILE *ftemp;
   agent m;
   
   
   
 


ftemp=fopen("ftemp.txt","w");
f=fopen("agent.txt","r");

if(f!=NULL){
if(ftemp!=NULL)

{
while(fscanf(f,"%s %s %s %s %s %s  \n",m.nom,m.prenom,m.date_recrut,m.cin,m.id,m.domaine)!=EOF)
{
 if (strcmp(cid,m.id)==0)
{
fprintf(ftemp,"%s %s %s %s %s %s  \n",nom,prenom,date,cin,cid,domaine);}
 else

fprintf(ftemp,"%s %s %s %s %s %s  \n",m.nom,m.prenom,m.date_recrut,m.cin,m.id,m.domaine);
}
}
fclose(f);}
fclose(ftemp);
remove("agent.txt");
rename("ftemp.txt","agent.txt");
}



void affiche_client(GtkWidget *liste)
{
  enum
{
	
	NOM,
	PRENOM,
	NUMPASS,
	EMAIL,
	CIN,
        MOTDEPASSE,	
	NUM,
	COLUMNS
};
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter  iter;
	GtkListStore *store;

	char nom[30];
	char prenom[30];
	char numpass[30];
	char email[30];
	char cin[30];
	char motdepasse[30];
	char num[30];
        char jour[30];
        char mois[30];
         char annee[30];
        
	store=NULL;
	FILE*f;
	
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	 {
		renderer=gtk_cell_renderer_text_new ();
       		column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
        	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        	renderer=gtk_cell_renderer_text_new ();
        	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
        	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        	renderer=gtk_cell_renderer_text_new ();
        	column=gtk_tree_view_column_new_with_attributes("numpass",renderer,"text",NUMPASS,NULL);
        	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        	renderer=gtk_cell_renderer_text_new ();
        	column=gtk_tree_view_column_new_with_attributes("email",renderer,"text",EMAIL,NULL);
        	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        	renderer=gtk_cell_renderer_text_new ();
        	column=gtk_tree_view_column_new_with_attributes("cin",renderer,"text",CIN,NULL);
                gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new ();
        	column=gtk_tree_view_column_new_with_attributes("motdepasse",renderer,"text",MOTDEPASSE,NULL);
        	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

                renderer=gtk_cell_renderer_text_new ();
        	column=gtk_tree_view_column_new_with_attributes("num",renderer,"text",NUM,NULL);
        	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
                
        	
       }
        store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
        f = fopen("client.txt","r");
        if(f==NULL)
        {
            return;
        }
        else
        {f = fopen("client.txt","a+");
                while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s \n",nom,prenom,numpass,email,cin,motdepasse,jour,mois,annee,num)!=EOF)
            {

        gtk_list_store_append(store,&iter);
        gtk_list_store_set(store,&iter,NOM,nom,PRENOM,prenom,NUMPASS,numpass,EMAIL,email,CIN,cin,MOTDEPASSE,motdepasse,NUM,num,-1);
            }
            fclose(f);
        gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        g_object_unref (store);
        }
}
void supprimer1(GtkWidget *liste)
{
  enum
{
	
	NOM,
	PRENOM,
	NUMPASS,
	EMAIL,
	CIN,
        MOTDEPASSE,	
	NUM,
	COLUMNS
};
 GtkTreeSelection *selection; 
 GtkListStore *store;
  GtkTreeModel *model;
  GtkTreeIter  iter;
   gchar *cin;
selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(liste));
store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
model = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection), 
         &model, &iter)) {
    
    gtk_tree_model_get(model,&iter,CIN,&cin,-1);
    gtk_list_store_remove(store, &iter);

 }

FILE *f;
FILE *ftemp;
ftemp=fopen("ftemp.txt","w");
f=fopen("client.txt","r");
client p;
Date dt_n;

if(f!=NULL)
 {
  if(ftemp!=NULL)
{
 while(fscanf(f,"%s %s %s %s %s %s %d %d %d %d \n",p.chnom,p.chprenom,p.chnum,p.chemail,p.chcin,p.chpassword,&p.dt_n.jour,&p.dt_n.mois,&p.dt_n.annee,&p.num)!=EOF)
{
 if (strcmp(cin,p.chcin)!=0)
{
fprintf(ftemp,"%s %s %s %s %s %s %d %d %d %d \n",p.chnom,p.chprenom,p.chnum,p.chemail,p.chcin,p.chpassword,p.dt_n.jour,p.dt_n.mois,p.dt_n.annee,p.num);

 
}

}
fclose(ftemp);}
fclose(f);}

      remove("client.txt");
      rename("ftemp.txt","client.txt");

}

