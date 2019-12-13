#include <stdio.h>
#include <string.h>
#include "fonction.h"
#include <gtk/gtk.h>

enum
{
	
        HOTEL,
        VILLE,
	ETOILE,
	PRIX,
        ID,
        RESV,
        COLUMNS
	
};

void ajouter_heber(heber p)
{

 FILE *f;
 f=fopen("heber.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %d %s %d\n",p.hotel,p.ville,p.etoile,p.prix,p.id,p.resv);
 fclose(f);
 }
else
printf("\n not found");

}

void afficher_heber(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;

GtkTreeIter iter;
GtkListStore *store;

char hotel [30];
char ville[30];
char etoile [30];
char prix [30];
char id [30];
char resv[30];

store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("hotel",renderer,"text",HOTEL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("ville",renderer,"text",VILLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("etoile",renderer,"text",ETOILE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prix",renderer,"text",PRIX,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
        renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("resv",renderer,"text",RESV,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
      
	f=fopen("heber.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("heber.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s\n",hotel,ville,etoile,prix,id,resv)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,HOTEL,hotel,VILLE,ville,ETOILE,etoile,PRIX,prix,ID,id,RESV,resv, -1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

void supprimer_heber(GtkWidget *liste)
{
 GtkTreeSelection *selection;
 GtkListStore *store;
 GtkTreeModel *model;
 GtkTreeIter iter;
  gchar *id;
selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(liste));
store=GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(liste)));
model=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(selection),&model,&iter))
{
 gtk_tree_model_get(model,&iter,ID,&id,-1);
 gtk_list_store_remove(store,&iter);
}
 heber p;
 FILE *f;
 FILE *f2;
 char prix[20];
 char resv[20];
       


 f=fopen("heber.txt","r");
    if(f==NULL)
    	{
	 return;
	}
    else
	{
         while(fscanf(f,"%s %s %s %s %s %s \n",p.hotel,p.ville,p.etoile,prix,p.id,resv)!=EOF)
		{
		 if(strcmp(id,p.id)!=0)
			{
			 f2=fopen("heber1.txt", "a+");
			 if (f2==NULL)
				{
			 	 return;
				}
		 	 else	
				{
				 fprintf(f2,"%s %s %s %s %s %s \n" ,p.hotel,p.ville,p.etoile,prix,p.id,resv);
				 fclose(f2);
				}
		
	    	}
	}
 fclose(f);
 remove("heber.txt");
 rename("heber1.txt","heber.txt");

}
}     


heber chercher_heber(char ide[])
{ 
    heber s ;
    FILE *f;
   
    
    
    f=fopen("heber.txt","r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %s %d\n",s.hotel,s.ville,s.etoile,&s.prix,s.id,&s.resv)!=EOF)
        {
            
            if (strcmp(s.id,ide)==0)
            {
                return(s);
            }
        }
    }
}

int verifier_id(char ids[])
{


heber s ;
    FILE *f;
    
    char hotel[20];
    char ville[20];
    char etoile[20];
    char prix[20];
    char id[20];
    char resv[20];
    int y=1;
    
    
    f=fopen("heber.txt","r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s\n",hotel,ville,etoile,prix,id,resv)!=EOF)
        {
            
            if (strcmp(id,ids)==0)
            {
                y=0;
            }
            else
{

 }
       }
    }


return (y);

}

void supprimer1_heber(char ide[])
{
char hotel[30];
char ville[30];
char etoile[30];
char prix[30];
char id[30];
char resv[30]; 
heber p;
FILE *f;
FILE *f2;
 
       


 f=fopen("heber.txt","r");
    if(f==NULL)
    	{
	 return;
	}
    else
	{
         while(fscanf(f,"%s %s %s %s %s %s \n",hotel,ville,etoile,prix,id,resv)!=EOF)
		{
		 if(strcmp(ide,id)!=0)
			{
			 f2=fopen("heber1.txt", "a+");
			 if (f2==NULL)
				{
			 	 return;
				}
		 	 else	
				{
				 fprintf(f2,"%s %s %s %s %s %s \n" ,hotel,ville,etoile,prix,id,resv);
				 fclose(f2);
				}
		
	    	}
	}
 fclose(f);
 remove("heber.txt");
 rename("heber1.txt","heber.txt");

}
}    














