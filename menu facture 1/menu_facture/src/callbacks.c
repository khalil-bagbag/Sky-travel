#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "gestion_factures.h"


void
on_abdousupprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *abdouwindow2;
GtkWidget *abdouwindow3;


abdouwindow2=lookup_widget(objet,"abdouwindow2");

gtk_widget_destroy(abdouwindow2);
abdouwindow3=lookup_widget(objet,"abdouwindow3");
abdouwindow3=create_abdouwindow3();

gtk_widget_show(abdouwindow3);

}

void
on_abdouprecedent_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *abdouwindow1,*abdouwindow2;

abdouwindow2=lookup_widget(objet,"abdouwindow2");
abdouwindow1=lookup_widget(objet,"abdouwindow1");
gtk_widget_destroy(abdouwindow2);
abdouwindow1=create_abdouwindow1();
gtk_widget_show(abdouwindow1);
}


void
on_abdoumodifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *abdouwindow2;
GtkWidget *abdouwindow4;


abdouwindow2=lookup_widget(objet,"abdouwindow2");

gtk_widget_destroy(abdouwindow2);
abdouwindow4=lookup_widget(objet,"abdouwindow4");
abdouwindow4=create_abdouwindow4();

gtk_widget_show(abdouwindow4);
}








void
on_abdoufacture_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *abdouwindow1;
GtkWidget *abdouwindow2;
GtkWidget *abdoutreeview1;

abdouwindow1=lookup_widget(objet,"abdouwindow1");

gtk_widget_destroy(abdouwindow1);
abdouwindow2=lookup_widget(objet,"abdouwindow2");
abdouwindow2=create_abdouwindow2();

gtk_widget_show(abdouwindow2);

abdoutreeview1=lookup_widget(abdouwindow2,"abdoutreeview1");

afficher_facture(abdoutreeview1);
}


void
on_abdouconfirmer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input;
char supp[30];
input=lookup_widget(objet,"abdousupp");
strcpy(supp,gtk_entry_get_text(GTK_ENTRY(input)));
supprimer_facture(supp);
}


void
on_abdouvalider_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
fact f;
int Jour,Mois,Annee;
GtkWidget window4;
GtkWidget *input1,*output1,*output2,*output3,*output4,*output5,*output6,*jour,*mois,*annee;

char id [30];


output1=lookup_widget(objet,"abdounid");
output2=lookup_widget(objet,"abdounnom");
output3=lookup_widget(objet,"abdounprenom");
output4=lookup_widget(objet,"abdounreservation");
output5=lookup_widget(objet,"abdounmontant_total");
output6=lookup_widget(objet,"abdounmontant_ttc");
input1=lookup_widget(objet,"abdouid");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
jour=lookup_widget(objet,"abdounjour");
mois=lookup_widget(objet,"abdounmois");
annee=lookup_widget(objet,"abdounannee");
FILE *p;
	p=fopen("/home/msx/Projects/menu_facture/src/factures.txt","r");
	if(p!=NULL)
{
while(fscanf(p,"%s %s %s %d %d %d %s %s %s\n",f.id_fact,f.nom,f.prenom,&f.jour,&f.mois,&f.annee,f.reservation,f.montant_total,f.montant_ttc)!=EOF)
{
	if (strcmp(f.id_fact,id)==0)
{
gtk_entry_set_text (GTK_ENTRY (output1),f.id_fact);
gtk_entry_set_text (GTK_ENTRY (output2),f.nom);
gtk_entry_set_text (GTK_ENTRY (output3),f.prenom);
gtk_entry_set_text (GTK_ENTRY (output4),f.reservation);
gtk_entry_set_text (GTK_ENTRY (output5),f.montant_total);
gtk_entry_set_text (GTK_ENTRY (output6),f.montant_ttc);
Jour=f.jour;
Mois=f.mois;
Annee=f.annee;
}
}
fclose(p);
}
gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour),Jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(mois),Mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee),Annee);


}


void
on_abdoumodifierr_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
fact f;
GtkWidget *window4;
GtkWidget *input1,*input2,*input3,*input4,*jour,*mois,*annee,*input5,*input6;

window4=lookup_widget(objet,"abdouwindow4");
char id [30];

input1=lookup_widget(objet,"abdounid");
input2=lookup_widget(objet,"abdounnom");
input3=lookup_widget(objet,"abdounprenom");
input4=lookup_widget(objet,"abdounreservation");
input5=lookup_widget(objet,"abdounmontant_total");
input6=lookup_widget(objet,"abdounmontant_ttc");
jour=lookup_widget(objet,"abdounjour");
mois=lookup_widget(objet,"abdounmois");
annee=lookup_widget(objet,"abdounannee");
strcpy(f.id_fact,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(f.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(f.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
f.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
f.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
f.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(f.reservation,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(f.montant_total,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(f.montant_ttc,gtk_entry_get_text(GTK_ENTRY(input6)));


modifier_facture(f);


}





void
on_abdouprecedent1_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *abdoutreeview1;
GtkWidget *abdouwindow3,*abdouwindow2;

abdouwindow3=lookup_widget(objet,"abdouwindow3");

gtk_widget_destroy(abdouwindow3);
abdouwindow2=create_abdouwindow2();
gtk_widget_show(abdouwindow2);
abdoutreeview1=lookup_widget(abdouwindow2,"abdoutreeview1");
afficher_facture(abdoutreeview1);
}


void
on_abdouafficher1_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *abdouwindow2;
GtkWidget *abdouwindow5;


abdouwindow2=lookup_widget(objet,"abdouwindow2");

gtk_widget_destroy(abdouwindow2);
abdouwindow5=lookup_widget(objet,"abdouwindow5");
abdouwindow5=create_abdouwindow5();

gtk_widget_show(abdouwindow5);
}





void
on_abdou0_clicked                         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *abdoutreeview1;
GtkWidget *abdouwindow4,*abdouwindow2;

abdouwindow4=lookup_widget(objet,"abdouwindow4");

gtk_widget_destroy(abdouwindow4);
abdouwindow2=create_abdouwindow2();
gtk_widget_show(abdouwindow2);
abdoutreeview1=lookup_widget(abdouwindow2,"abdoutreeview1");

afficher_facture(abdoutreeview1);


}

void
on_abdouajoute_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
fact f;
GtkWidget *input1,*input2,*input3,*input4,*jour,*mois,*annee,*input5,*input6;

GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
GtkWidget *output6;


char empty[]="\0";
GtkWidget *abdouwindow5;

abdouwindow5=lookup_widget(objet,"abdouwindow5");


output6=lookup_widget(objet,"abdouerreur6");
output5=lookup_widget(objet,"abdouerreur5");
output4=lookup_widget(objet,"abdouerreur4");
output3=lookup_widget(objet,"abdouerreur3");
output2=lookup_widget(objet,"abdouerreur2");
output1=lookup_widget(objet,"abdouerreur1");
input1=lookup_widget(objet,"abdouid");
input2=lookup_widget(objet,"abdounom");
input3=lookup_widget(objet,"abdouprenom");
input4=lookup_widget(objet,"abdoureservation");
input5=lookup_widget(objet,"abdoumontant_total");
input6=lookup_widget(objet,"abdoumontant_ttc");
jour=lookup_widget(objet,"abdoujour");
mois=lookup_widget(objet,"abdoumois");
annee=lookup_widget(objet,"abdouannee");
strcpy(f.id_fact,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(f.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(f.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
f.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
f.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
f.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(f.reservation,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(f.montant_total,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(f.montant_ttc,gtk_entry_get_text(GTK_ENTRY(input6)));
if(strcmp(f.id_fact,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output1),"erreur vide"); 
}
else if(strcmp(f.nom,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output2),"erreur vide");
}
else if(strcmp(f.prenom,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output3),"erreur vide");
}
else if(strcmp(f.reservation,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output4),"erreur vide");
}
else if(strcmp(f.montant_total,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output5),"erreur vide");
}
else if(strcmp(f.montant_ttc,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output6),"erreur vide");
}

else
{
ajouter_facture(f);
}
}


void
on_abdouprecedent2_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *abdoutreeview1;
GtkWidget *abdouwindow5,*abdouwindow2;

abdouwindow5=lookup_widget(objet,"abdouwindow5");

gtk_widget_destroy(abdouwindow5);
abdouwindow2=create_abdouwindow2();
gtk_widget_show(abdouwindow2);
abdoutreeview1=lookup_widget(abdouwindow2,"abdoutreeview1");

afficher_facture(abdoutreeview1);
}


void
on_abdoulogin_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int x;
char username[100];
char password[100];

GtkWidget *input1;
GtkWidget *input2;

GtkWidget *output2;
input1=lookup_widget(objet_graphique,"abdouloginentry");
input2=lookup_widget(objet_graphique,"abdoumotdepasse");

output2=lookup_widget(objet_graphique,"abdouerreuruser");
strcpy(username,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(input2)));
x=verifier(username,password);
if (x==1)
{


GtkWidget *abdouwindow1,*abdouwindow6;

abdouwindow1=lookup_widget(objet_graphique,"abdouwindow1");
abdouwindow6=lookup_widget(objet_graphique,"abdouwindow6");

abdouwindow1=create_abdouwindow1();
gtk_widget_show(abdouwindow1);
gtk_widget_hide(abdouwindow6);



}
if(x!=1) 
{
gtk_label_set_text(GTK_LABEL(output2),"login ou mot de passe errone");
}
}


void
on_abdoudeconnecter_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *abdouwindow1,*abdouwindow6;

abdouwindow1=lookup_widget(objet,"abdouwindow1");

gtk_widget_destroy(abdouwindow1);
abdouwindow6=create_abdouwindow6();
gtk_widget_show(abdouwindow6);
}


void
on_abdouretour_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}

