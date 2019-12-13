#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "agent.h"
#include <string.h>
void
cmon_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

agent p;
GtkWidget *input1,*input2,*input3,*input4,*input5;
GtkWidget *cmfenetre_ajout;
GtkWidget *cmcombobox1;
cmfenetre_ajout=lookup_widget(objet,"cmfenetre_ajout");
input1=lookup_widget(objet,"cmnom");
input2=lookup_widget(objet,"cmprenom");
input3=lookup_widget(objet,"cmdate");
input4=lookup_widget(objet,"cmcin");
input5=lookup_widget(objet,"cmid");
cmcombobox1=lookup_widget(objet,"cmcombobox1");
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(p.date_recrut,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(p.cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input5)));
char domaine[30];
strcpy(p.domaine,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cmcombobox1)));

ajouter_agent(p);

}



void
cmon_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *cmfenetre_ajout;
GtkWidget *cmfenetre_afficher;
GtkWidget *cmtreeview1;

cmfenetre_ajout=lookup_widget(objet,"cmfenetre_ajout");


gtk_widget_destroy(cmfenetre_ajout);
cmfenetre_afficher=lookup_widget(objet,"cmfenetre_afficher");
cmfenetre_afficher=create_cmfenetre_afficher();
gtk_widget_show(cmfenetre_afficher);
cmtreeview1 =lookup_widget(cmfenetre_afficher,"cmtreeview1");
afficher_agent(cmtreeview1);
}


void
cmon_retour_clicked                      (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *cmfenetre_ajout,*cmfenetre_afficher;
cmfenetre_afficher=lookup_widget(objet,"cmfenetre_afficher");

gtk_widget_destroy(cmfenetre_afficher);
cmfenetre_ajout=create_cmfenetre_ajout();
gtk_widget_show(cmfenetre_ajout);
}


void
cmon_supprimer_clicked                   (GtkWidget      *objet,
                                        gpointer         selection)
{
GtkWidget *cmfenetre_afficher;
GtkWidget *cmtreeview1;
cmfenetre_afficher=lookup_widget(objet,"cmfenetre_afficher");
cmtreeview1 =lookup_widget(cmfenetre_afficher,"cmtreeview1");
supprimer(cmtreeview1);
}


void
cmon_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *cmwindow3;
GtkWidget *cmfenetre_afficher;

cmfenetre_afficher=lookup_widget(objet,"cmfenetre_afficher");
gtk_widget_hide(cmfenetre_afficher);

cmwindow3=lookup_widget(objet,"cmwindow3");
cmwindow3=create_cmwindow3();
gtk_widget_show(cmwindow3);

}




void
cmon_button7_clicked                     (GtkWidget     *objet,
                                        gpointer         user_data)
{
GtkWidget *cmwindow3;
GtkWidget *cmfenetre_afficher;

cmfenetre_afficher=lookup_widget(objet,"cmfenetre_afficher");
cmwindow3=lookup_widget(objet,"cmwindow3");
GtkWidget *input1,*input2,*input3,*input4,*input5 ;
GtkWidget *cmcombobox2;
char nom[100];
char prenom[100];
char date[100];
char cin[100];
char cid[100];
char domaine[100];









input1=lookup_widget(objet,"cmnnom");
input2=lookup_widget(objet,"cmnprenom");
input3=lookup_widget(objet,"cmndate");
input4=lookup_widget(objet,"cmncin");
input5=lookup_widget(objet,"cmnid");
cmcombobox2=lookup_widget(objet,"cmcombobox2");
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(date,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(cid,gtk_entry_get_text(GTK_ENTRY(input5)));
char cmdomaine[30];
strcpy(domaine,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cmcombobox2)));
modifier_agent( nom, prenom, date, cin, cid,domaine);


}



void
cmon_button8_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *cmwindow3;
GtkWidget *cmfenetre_afficher;
GtkWidget *cmtreeview1;
cmfenetre_afficher=lookup_widget(objet,"cmfenetre_afficher");
cmwindow3=lookup_widget(objet,"cmwindow3");
gtk_widget_hide(cmwindow3);


cmfenetre_afficher=create_cmfenetre_afficher();
gtk_widget_show(cmfenetre_afficher);
cmtreeview1 =lookup_widget(cmfenetre_afficher,"cmtreeview1");
afficher_agent(cmtreeview1);}


void
cmon_button10_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *cmwindow4;
GtkWidget *chwindowsup;
GtkWidget *chtreeview11;
chwindowsup=lookup_widget(objet,"chwindowsup");
cmwindow4=lookup_widget(objet,"cmwindow4");

gtk_widget_hide(cmwindow4);
chwindowsup=create_chwindowsup();
gtk_widget_show(chwindowsup);
chtreeview11 =lookup_widget(chwindowsup,"chtreeview11");
affiche_client(chtreeview11);

}


void
cmon_button9_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *cmwindow4;
GtkWidget *cmfenetre_ajout;
cmfenetre_ajout=lookup_widget(objet,"cmfenetre_ajout");
cmwindow4=lookup_widget(objet,"cmwindow4");
gtk_widget_hide(cmwindow4);
cmfenetre_ajout=create_cmfenetre_ajout();
gtk_widget_show(cmfenetre_ajout);
}

/*
void
cmon_ajouter_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
cmon_afficher_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
cmon_supprimer_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
cmon_modifier_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
cmon_retour_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
cmon_button8_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
cmon_button7_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
cmon_button9_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
cmon_button10_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}
*/

void
on_cmbutton2_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *cmwindow4;
GtkWidget *cmfenetre_ajout;
cmfenetre_ajout=lookup_widget(objet,"cmfenetre_ajout");
cmwindow4=lookup_widget(objet,"cmwindow4");
gtk_widget_hide(cmfenetre_ajout);


cmwindow4=create_cmwindow4();
gtk_widget_show(cmwindow4);
}



void
on_chbutsup_clicked                    (GtkWidget       *objet,
                                        gpointer         selection)
{

GtkWidget *chwindowsup;
GtkWidget *chtreeview11;
chwindowsup=lookup_widget(objet,"chwindowsup");
chtreeview11 =lookup_widget(chwindowsup,"chtreeview11");
supprimer1(chtreeview11);
}


void
on_chbutret_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *cmwindow4;
GtkWidget *chwindowsup;
chwindowsup=lookup_widget(objet,"chwindowsup");
cmwindow4=lookup_widget(objet,"cmwindow4");
gtk_widget_hide(chwindowsup);


cmwindow4=create_cmwindow4();
gtk_widget_show(cmwindow4);
}


