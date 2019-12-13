#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"
#include <string.h>
#include <stdio.h>


void
tbon_ajouter_v_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Comboboxv;
GtkWidget *spinbutton1;
GtkWidget *entryi;
GtkWidget *spinbutton3;

GtkWidget *Comboboxh;
GtkWidget *Comboboxe;
GtkWidget *sortie;
GtkWidget *sortie1;
heber p;
char ids[10];
int k;


Comboboxv=lookup_widget(objet_graphique,"tbcomboboxv");
sortie=lookup_widget(objet_graphique,"tblabel_7");
sortie1=lookup_widget(objet_graphique,"tblabel9km");
spinbutton1=lookup_widget(objet_graphique,"tbspinbutton1");
entryi=lookup_widget(objet_graphique,"tbentryi");
strcpy(ids,gtk_entry_get_text(GTK_ENTRY(entryi)));
spinbutton3=lookup_widget(objet_graphique,"tbspinbutton3");

Comboboxh=lookup_widget(objet_graphique,"tbcomboboxh");
Comboboxe=lookup_widget(objet_graphique,"tbcomboboxe");
p.prix=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton1));
strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(entryi)));
p.resv=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton3));

strcpy(p.ville,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxv)));


strcpy(p.hotel,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxh)));

strcpy(p.etoile,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Comboboxe)));
k=verifier_id(ids);
if(k==0)
{
gtk_label_set_text(GTK_LABEL(sortie1),"veuiller choisir un autre id");
return(0);
}
if(k!=0)
{
ajouter_heber(p);
gtk_label_set_text(GTK_LABEL(sortie),"ajoutation réussite");
}
}


void
tbon_modifier_v_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
heber p;

GtkWidget *input2;
 GtkWidget *comboboxv;
 GtkWidget *comboboxh;
 GtkWidget *comboboxe;
 GtkWidget *prix;
 GtkWidget *resv;
 GtkWidget *window1;
GtkWidget *sortie;
 


char Id[30];

window1=lookup_widget(objet,"tbwindow1");


prix=lookup_widget(objet, "tbspinbutton1");
resv=lookup_widget(objet, "tbspinbutton3");

sortie=lookup_widget(objet,"tblabel_7");

comboboxv=lookup_widget(objet,"tbcomboboxv");
comboboxh=lookup_widget(objet,"tbcomboboxh");
comboboxe=lookup_widget(objet,"tbcomboboxe");
input2=lookup_widget(objet,"tbentryi");
 strcpy(Id,gtk_entry_get_text(GTK_ENTRY(input2)));
 strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input2)));



p.prix=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (prix));
p.resv=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (resv));


strcpy(p.ville,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxv)));
strcpy(p.hotel,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxh)));
strcpy(p.etoile,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxe)));
supprimer1_heber(Id);
ajouter_heber(p);
gtk_label_set_text(GTK_LABEL(sortie),"modification réussite");


}


void
tbon_afficher_v_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *window2;
GtkWidget *treeview1;

window1=lookup_widget(objet,"tbwindow1");

gtk_widget_destroy(window1);
window2=lookup_widget(objet,"tbwindow2");
window2=create_tbwindow2();

gtk_widget_show(window2);

treeview1=lookup_widget(window2,"tbtreeview1");

afficher_heber(treeview1);
}




void
tbon_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1,*window2;

window2=lookup_widget(objet,"tbwindow2");

gtk_widget_destroy(window2);
window1=create_tbwindow1();
gtk_widget_show(window1);
}





void
tbon_button_supprimer_clicked            (GtkWidget       *objet,
                                        gpointer         selection)
{


GtkWidget *window2;

GtkWidget *treeview1;
 
 
 window2=lookup_widget(objet,"tbwindow2");
 



treeview1=lookup_widget(window2,"tbtreeview1");

supprimer_heber(treeview1);



}





void
tbon_buttonrch_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *output1; 
GtkWidget *output2; 
GtkWidget *output3;
GtkWidget *output4; 
GtkWidget *output5;
GtkWidget *output6;
GtkWidget *window1;
heber p;
char ide[100];
char hotel[100];
char ville[100];
char etoile[100];
char prix[100];
char id[100];
char resv[100];
window1=lookup_widget(objet,"tbwindow1");
input=lookup_widget(objet,"tbentry1998");
output1=lookup_widget(objet,"tbentry2005");
output2=lookup_widget(objet,"tbentry2006");
output3=lookup_widget(objet,"tbentry2007");
output4=lookup_widget(objet,"tbentry2008");
output5=lookup_widget(objet,"tbentry2009");
output6=lookup_widget(objet,"tbentry2010");

strcpy(ide,gtk_entry_get_text(GTK_ENTRY(input)));

FILE *f;
  f=fopen("heber.txt","r"); 
   if (f!=NULL)
   {
    while (fscanf(f,"%s %s %s %s %s %s  \n",hotel,ville,etoile,prix,id,resv)!=EOF)
    {
   if (strcmp(id,ide)==0)
   {
     
     gtk_entry_set_text (GTK_ENTRY (output1), ville);
     gtk_entry_set_text (GTK_ENTRY (output2), hotel);
     gtk_entry_set_text (GTK_ENTRY (output3), etoile);
     gtk_entry_set_text (GTK_ENTRY (output4), prix);
     gtk_entry_set_text (GTK_ENTRY (output5), id);
     gtk_entry_set_text (GTK_ENTRY (output6), resv);
}
}
}




}








