#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include<string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "gestion_factures.h"
#include "vol.h"


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
on_abdouretour_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{

}
void
on_Prestation_vol_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *abdouwindow1;
GtkWidget *rbfwindow;


abdouwindow1=lookup_widget(objet,"abdouwindow1");
rbfwindow=lookup_widget(objet,"rbfwindow");

gtk_widget_destroy(abdouwindow1);

rbfwindow=create_rbfwindow();

gtk_widget_show(rbfwindow);

}
////////////////////////////code rana ///////////////////////////


void
rbfon_ajout_clicked (GtkWidget *objet, gpointer user_data)
{
            GtkWidget *window;
            GtkWidget *window1;


             window=lookup_widget(objet, "rbfwindow");
             window1 = create_rbfwindow1 ();
             gtk_widget_show(window1);
             gtk_widget_hide(window);

}


void
rbfon_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	Vol p;
	GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8;

	GtkWidget *window1;

	window1=lookup_widget(objet,"rbfwindow1");

	input4=lookup_widget(objet,"rbfDuree_vol");
	input6=lookup_widget(objet,"rbfNbre_voyageurs");
	input7=lookup_widget(objet,"rbfPrix_vol");
	input8=lookup_widget(objet,"rbfId_vol");

	GtkWidget *spinbutton1;
	GtkWidget *spinbutton2;
	GtkWidget *spinbutton3;

	GtkWidget *combobox1;
	GtkWidget *combobox2;
	GtkWidget *combobox3;

	spinbutton1=lookup_widget(objet, "rbfJour");
	spinbutton2=lookup_widget(objet, "rbfMois");
	spinbutton3=lookup_widget(objet, "rbfAnnee");

	combobox1=lookup_widget(objet, "rbfcombobox1");
	combobox2=lookup_widget(objet, "rbfcombobox2");
	combobox3=lookup_widget(objet, "rbfcombobox3");

	int JJ=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton1));
	int MM=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton2));
	int AA=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton3));

	char ville_depart[20];
	strcpy(p.Ville_depart,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
	char ville_arrivee[20];
	strcpy(p.Ville_arrivee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
	char classe_vol[20];
	strcpy(p.Classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));

	
p.Jour=JJ;
p.Mois=MM;
p.Annee=AA;

	strcpy(p.Duree_vol,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(p.Nbre_voyageurs,gtk_entry_get_text(GTK_ENTRY(input6)));
	strcpy(p.Prix_vol,gtk_entry_get_text(GTK_ENTRY(input7)));
	strcpy(p.Id_vol,gtk_entry_get_text(GTK_ENTRY(input8)));
	ajouter_vol(p);
}

void
rbfon_afficher_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *window;
	GtkWidget *windowaffichage;
	GtkWidget *treeview1;

	window=lookup_widget(objet, "rbfwindow");

	gtk_widget_destroy(window);
	windowaffichage=lookup_widget(objet,"rbfwindowaffichage");
	windowaffichage=create_rbfwindowaffichage();

	gtk_widget_show(windowaffichage);
	gtk_widget_hide(window);

	treeview1=lookup_widget(windowaffichage,"rbftreeview1");
	afficher_vol(treeview1);
}

void 
rbfon_retour_clicked (GtkWidget *objet, gpointer user_data)
{
	GtkWidget *windowaffichage;
	GtkWidget *window;

	windowaffichage=lookup_widget(objet,"rbfwindowaffichage");
	
	gtk_widget_destroy(windowaffichage);
	window=create_rbfwindow();
	gtk_widget_show(window);
}







void
rbfon_modifier_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window4;

window=lookup_widget(objet,"rbfwindow");
window4=create_rbfwindow4();
gtk_widget_show(window4);
gtk_widget_hide(window);

}



/*
void
on_confirmer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Ville_depart, *Ville_arrivee, *Jour, *Mois, *Annee, *Duree_vol, *Classe, *Nbre_voyageurs, *Prix_vol, *Id_vol, *current, *window2, *window3, *liste;
	char Ville_departy[40], Ville_arriveey[40], Duree_voly[40],Classey[40], Nbre_voyageursy[40], Prix_voly[40], Id_voly[40];
	int Joury,Moisy,Anneey;
	Ville_depart=lookup_widget(objet,"combobox4");
	Ville_arrivee=lookup_widget(objet,"combobox5");
	
	Jour=lookup_widget(objet,"spinbutton1");
	Mois=lookup_widget(objet,"spinbutton2");
	Annee=lookup_widget(objet,"spinbutton3");
	
	Duree_vol=lookup_widget(objet,"entry1");
	Classe=lookup_widget(objet,"combobox6");
	Nbre_voyageurs=lookup_widget(objet,"entry2");
	Prix_vol=lookup_widget(objet,"entry3");
	Id_vol=lookup_widget(objet,"entry4");

	strcpy(Ville_departy,gtk_combo_box_get_active_text(GTK_COMBO_BOX(GTK_ENTRY(Ville_depart))));
	strcpy(Ville_arriveey,gtk_combo_box_get_active_texdt(GTK_COMBO_BOX(GTK_ENTRY(Ville_arrivee))));
	Joury = gtk_spin_button_get_value_as_int(Jour);
	Moisy = gtk_spin_button_get_value_as_int(Mois);
	Anneey = gtk_spin_button_get_value_as_int(Annee);
	strcpy(Duree_voly,gtk_entry_get_text(GTK_ENTRY(Duree_vol)));
	strcpy(Classey,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Classe)));
	strcpy(Nbre_voyageursy,gtk_entry_get_text(GTK_ENTRY(Nbre_voyageurs)));
	strcpy(Prix_voly,gtk_entry_get_text(GTK_ENTRY(Prix_vol)));
	strcpy(Id_voly,gtk_entry_get_text(GTK_ENTRY(Id_vol)));
	
	confirmer(Ville_departy, Ville_arriveey, Joury, Moisy, Anneey, Duree_voly, Classey, Nbre_voyageursy, Prix_voly, Id_voly);
	window2=create_rbfwindow2();
	gtk_widget_show (window2);
	current=lookup_widget(objet,"window3");
	gtk_widget_hide(current);
	liste=lookup_widget(window2,"treeview1");
	afficher_vol(liste);
}
*/



void
rbfon_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window4;

window=lookup_widget(objet,"rbfwindow");
window4=create_rbfwindow4();
gtk_widget_show(window4);
gtk_widget_hide(window);
}


void
rbfon_supprr_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input120;
 Vol p;

            char ch1[50];
            FILE *f1 ;
            FILE *ftempvol;
input120=lookup_widget(objet,"rbfentrysupmod");
            strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input120)));
ftempvol=fopen ("tempvol.txt","a+");
f1=fopen("uservol.txt","a+");
char pVille_depart[20], pVille_arrivee[20], pJour[20], pMois[20], pAnnee[20], pDuree_vol[20], pClasse[20], pNbre_voyageurs[20], pPrix_vol[20], pId_vol[20];


                       while (fscanf(f1,"%s %s %s %s %s %s %s %s \n",pVille_depart, pVille_arrivee, pJour, pDuree_vol, pClasse, pNbre_voyageurs, pPrix_vol, pId_vol)!=EOF)
{ 
if (strcmp(ch1,pId_vol)!=0)
{
fprintf(ftempvol,"%s %s %s %s %s %s %s %s\n",pVille_depart, pVille_arrivee, pJour, pDuree_vol, pClasse, pNbre_voyageurs, pPrix_vol, pId_vol);
}
} 
fclose(ftempvol);
fclose(f1);
remove ("uservol.txt");
rename ("tempvol.txt","uservol.txt");
}




/*void
on_modifr_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
           GtkWidget *window6y;
            GtkWidget *window7y;
            GtkWidget *input16y, *output16y;
	    personne p;
            char ch[50];
            FILE* f ;
            window6y=lookup_widget(objet_graphique, "window6y");
            input16y=lookup_widget(objet_graphique,"entry21y");
            output16y=lookup_widget(objet_graphique,"label59y");
            strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input16y)));
f=fopen("/home/yassmine/Projects/project1/src/ajout.txt","r");
while (fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s\n",p.nom,p.prenom,p.cin,p.jour,p.mois,p.annee,p.sexe,p.taille,p.poids,p.imc,p.clas,p.regime)!=EOF)
{ 
if (strcmp(ch,p.cin)==0)
{
             window7y = create_rbfwindow7y ();
             gtk_widget_show(window7y);
             gtk_widget_hide(window6y);
}
else
{gtk_label_set_text(GTK_LABEL(output16y),"cin incompatible");}
}
}
*/



void
rbfon_button4return_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"rbfwindow1");
gtk_widget_hide(window);
window1=create_rbfwindow();
gtk_widget_show_all(window1);
}


void
rbfon_retour1enterid_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"rbfwindow4");
gtk_widget_hide(window);
window1=create_rbfwindow();
gtk_widget_show_all(window1);
}


void
rbfon_button1gestionvol_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"rbfwindow5");
gtk_widget_hide(window);
window1=create_rbfwindow();
gtk_widget_show_all(window1);
}


void
rbfon_modifyvol1_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *input120;
GtkWidget *output20;
output20= lookup_widget(button,"rbferreur");

FILE *idtemp ;
FILE *uservol;

char x[50];
input120=lookup_widget(button,"rbfentrysupmod");
strcpy(x,gtk_entry_get_text(GTK_ENTRY(input120)));
idtemp=fopen ("idtemp.txt","a+");
uservol=fopen ("uservol.txt","a+");
char pVille_depart[20], pVille_arrivee[20], pJour[20], pMois[20], pAnnee[20], pDuree_vol[20], pClasse[20], pNbre_voyageurs[20], pPrix_vol[20], pId_vol[20];
 while (fscanf(uservol,"%s %s %s %s %s %s %s %s \n",pVille_depart, pVille_arrivee, pJour, pDuree_vol, pClasse, pNbre_voyageurs, pPrix_vol, pId_vol)!=EOF)
{ 
if (strcmp(x,pId_vol)==0)
{
fprintf(idtemp,"%s",x);
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"rbfwindow4");
gtk_widget_hide(window);
window1=create_rbfwindow3();
gtk_widget_show_all(window1);



}
}
fclose(idtemp);
fclose(uservol);


char ext[]="\0";

if(strcmp(x,ext)==0||strcmp(x,pId_vol)!=0)
{
gtk_label_set_text(GTK_LABEL(output20),"id incompatible");
}

}


void
rbfon_buttonconfirm_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
FILE *idtemp ;
FILE *uservol;
FILE *ftempvol;

idtemp=fopen ("idtemp.txt","a+");
char x[20];

fscanf(idtemp,"%s",x);

ftempvol=fopen ("tempvol.txt","a+");
uservol=fopen ("uservol.txt","a+");


char pVille_depart[20], pVille_arrivee[20], pJour[20], pMois[20], pAnnee[20], pDuree_vol[20], pClasse[20], pNbre_voyageurs[20], pPrix_vol[20], pId_vol[20];


                       while (fscanf(uservol,"%s %s %s %s %s %s %s %s \n",pVille_depart, pVille_arrivee, pJour, pDuree_vol, pClasse, pNbre_voyageurs, pPrix_vol, pId_vol)!=EOF)
{ 
if (strcmp(x,pId_vol)!=0)
{
fprintf(ftempvol,"%s %s %s %s %s %s %s %s\n",pVille_depart, pVille_arrivee, pJour, pDuree_vol, pClasse, pNbre_voyageurs, pPrix_vol, pId_vol);
}
}
char a[20],b[20],c[50],d[50],e[50],f[50],g[50],h[50],i[50],j[50];

GtkWidget *input1;
GtkWidget *input2;
GtkWidget *input3;
GtkWidget *input4;

GtkWidget *combobox4;
GtkWidget *combobox5;
GtkWidget *combobox6;
GtkWidget *spinbutton123;
GtkWidget *spinbutton223;
GtkWidget *spinbutton323;

spinbutton123=lookup_widget(button, "rbfspinbutton123");
spinbutton223=lookup_widget(button, "rbfspinbutton223");
spinbutton323=lookup_widget(button, "rbfspinbutton323");
input1= lookup_widget(button,"rbfentry123");
input2= lookup_widget(button,"rbfentry223");
input3= lookup_widget(button,"rbfentry323");
input4= lookup_widget(button,"rbfentry423");

strcpy(a,gtk_entry_get_text(GTK_ENTRY(input1)));

strcpy(b,gtk_entry_get_text(GTK_ENTRY(input2)));

strcpy(c,gtk_entry_get_text(GTK_ENTRY(input3)));

strcpy(d,gtk_entry_get_text(GTK_ENTRY(input4)));

int JJ=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton123));
int MM=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton223));
int AA=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton323));

combobox4=lookup_widget(button, "rbfcombobox4");
combobox5=lookup_widget(button, "rbfcombobox5");
combobox6=lookup_widget(button, "rbfcombobox6");

char role[20];
strcpy(role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));

char role1[20];
strcpy(role1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)));

char role2[20];
strcpy(role2,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox6)));

fprintf(ftempvol,"%s %s %d/%d/%d %s %s %s %s %s",role,role1,JJ,MM,AA,a,role2,b,c,d);

fclose(idtemp);
fclose(ftempvol);
fclose(uservol);
remove ("idtemp.txt");
remove ("uservol.txt");
rename ("tempvol.txt","uservol.txt");

}


void
rbfon_buttonretour5_clicked               (GtkWidget        *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *window1;
window=lookup_widget(button,"rbfwindow3");
gtk_widget_hide(window);
window1=create_rbfwindow();
gtk_widget_show_all(window1);
}









