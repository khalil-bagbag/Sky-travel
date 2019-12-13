/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_tbwindow1 (void)
{
  GtkWidget *tbwindow1;
  GtkWidget *tbfixed1;
  GtkObject *tbspinbutton1_adj;
  GtkWidget *tbspinbutton1;
  GtkObject *tbspinbutton3_adj;
  GtkWidget *tbspinbutton3;
  GtkWidget *tbentryi;
  GtkWidget *tbentry1998;
  GtkWidget *tbentry2005;
  GtkWidget *tbentry2006;
  GtkWidget *tbentry2007;
  GtkWidget *tbentry2008;
  GtkWidget *tbentry2009;
  GtkWidget *tbentry2010;
  GtkWidget *tbimage6;
  GtkWidget *tbcomboboxh;
  GtkWidget *tblabelh;
  GtkWidget *tblabelekm;
  GtkWidget *tblabelp;
  GtkWidget *tblabeli;
  GtkWidget *tblabelr;
  GtkWidget *tbbuttonrch;
  GtkWidget *alignment5;
  GtkWidget *hbox5;
  GtkWidget *image5;
  GtkWidget *label7;
  GtkWidget *tblabelhkm;
  GtkWidget *tblabelvkm;
  GtkWidget *tblabele;
  GtkWidget *tblabelpkm;
  GtkWidget *tblabelikm;
  GtkWidget *tblabelmkm;
  GtkWidget *tbajouter_v;
  GtkWidget *alignment1;
  GtkWidget *hbox1;
  GtkWidget *tbimage1;
  GtkWidget *tblabel1;
  GtkWidget *tbafficher_v;
  GtkWidget *alignment3;
  GtkWidget *hbox3;
  GtkWidget *image3;
  GtkWidget *label3;
  GtkWidget *tbmodifier_v;
  GtkWidget *alignment4;
  GtkWidget *tbhbox4;
  GtkWidget *tbimage4;
  GtkWidget *tblabel4;
  GtkWidget *tbimage_principale_919b9d_png;
  GtkWidget *tbcomboboxe;
  GtkWidget *tblabel9km;
  GtkWidget *tblabelv;
  GtkWidget *tblabel_7;
  GtkWidget *tbcomboboxv;

  tbwindow1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (tbwindow1, 1280, -1);
  gtk_window_set_title (GTK_WINDOW (tbwindow1), _("espace agent"));

  tbfixed1 = gtk_fixed_new ();
  gtk_widget_show (tbfixed1);
  gtk_container_add (GTK_CONTAINER (tbwindow1), tbfixed1);

  tbspinbutton1_adj = gtk_adjustment_new (10, 10, 900, 1, 10, 10);
  tbspinbutton1 = gtk_spin_button_new (GTK_ADJUSTMENT (tbspinbutton1_adj), 1, 0);
  gtk_widget_show (tbspinbutton1);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbspinbutton1, 896, 64);
  gtk_widget_set_size_request (tbspinbutton1, 80, 32);

  tbspinbutton3_adj = gtk_adjustment_new (1, 10, 1000, 1, 10, 10);
  tbspinbutton3 = gtk_spin_button_new (GTK_ADJUSTMENT (tbspinbutton3_adj), 1, 0);
  gtk_widget_show (tbspinbutton3);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbspinbutton3, 1152, 64);
  gtk_widget_set_size_request (tbspinbutton3, 112, 32);

  tbentryi = gtk_entry_new ();
  gtk_widget_show (tbentryi);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbentryi, 1024, 64);
  gtk_widget_set_size_request (tbentryi, 80, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (tbentryi), 8226);

  tbentry1998 = gtk_entry_new ();
  gtk_widget_show (tbentry1998);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbentry1998, 784, 136);
  gtk_widget_set_size_request (tbentry1998, 72, 32);
  gtk_entry_set_invisible_char (GTK_ENTRY (tbentry1998), 8226);

  tbentry2005 = gtk_entry_new ();
  gtk_widget_show (tbentry2005);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbentry2005, 696, 240);
  gtk_widget_set_size_request (tbentry2005, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (tbentry2005), 8226);

  tbentry2006 = gtk_entry_new ();
  gtk_widget_show (tbentry2006);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbentry2006, 696, 192);
  gtk_widget_set_size_request (tbentry2006, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (tbentry2006), 8226);

  tbentry2007 = gtk_entry_new ();
  gtk_widget_show (tbentry2007);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbentry2007, 696, 288);
  gtk_widget_set_size_request (tbentry2007, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (tbentry2007), 8226);

  tbentry2008 = gtk_entry_new ();
  gtk_widget_show (tbentry2008);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbentry2008, 696, 344);
  gtk_widget_set_size_request (tbentry2008, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (tbentry2008), 8226);

  tbentry2009 = gtk_entry_new ();
  gtk_widget_show (tbentry2009);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbentry2009, 696, 392);
  gtk_widget_set_size_request (tbentry2009, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (tbentry2009), 8226);

  tbentry2010 = gtk_entry_new ();
  gtk_widget_show (tbentry2010);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbentry2010, 696, 432);
  gtk_widget_set_size_request (tbentry2010, 160, 27);
  gtk_entry_set_invisible_char (GTK_ENTRY (tbentry2010), 8226);

  tbimage6 = create_pixmap (tbwindow1, "arriere plan.jpg");
  gtk_widget_show (tbimage6);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbimage6, 304, 0);
  gtk_widget_set_size_request (tbimage6, 992, 472);

  tbcomboboxh = gtk_combo_box_new_text ();
  gtk_widget_show (tbcomboboxh);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbcomboboxh, 312, 64);
  gtk_widget_set_size_request (tbcomboboxh, 150, 35);
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), "");
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("J E R B A:"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Badira"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Magic"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Saida"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Cigale"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("T O U Z E R:"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Khella"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Marigold"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Hasdrubal"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("T U N I S:"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Ibis"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Movenpick"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Tour"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Concorde"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("S O U S S E:"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Laico"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Robinson"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Royal"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("H A M M A M E T:"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Mouradi"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Palace"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("Haway"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("G A M M A R T H:"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("fido"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("gikow"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("nihaw"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("vikil"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("M O N  A S T I R:"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("gikabo "));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("bijiha"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("anaci"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("M A H D I A:"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("gijit"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("vohur"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("nytor"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("M I D O U N:"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("quive"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("nikonk"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("hyter"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("N A B E U L:"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("qyter"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("jiton"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("bines"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxh), _("gitow"));

  tblabelh = gtk_label_new (_("hotel"));
  gtk_widget_show (tblabelh);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tblabelh, 312, 16);
  gtk_widget_set_size_request (tblabelh, 80, 32);

  tblabelekm = gtk_label_new (_("etoile"));
  gtk_widget_show (tblabelekm);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tblabelekm, 704, 8);
  gtk_widget_set_size_request (tblabelekm, 64, 40);

  tblabelp = gtk_label_new (_("prix"));
  gtk_widget_show (tblabelp);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tblabelp, 888, 16);
  gtk_widget_set_size_request (tblabelp, 72, 32);

  tblabeli = gtk_label_new (_("id"));
  gtk_widget_show (tblabeli);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tblabeli, 1008, 16);
  gtk_widget_set_size_request (tblabeli, 88, 32);

  tblabelr = gtk_label_new (_("max reservation"));
  gtk_widget_show (tblabelr);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tblabelr, 1144, 16);
  gtk_widget_set_size_request (tblabelr, 136, 40);

  tbbuttonrch = gtk_button_new ();
  gtk_widget_show (tbbuttonrch);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbbuttonrch, 648, 136);
  gtk_widget_set_size_request (tbbuttonrch, 136, 32);

  alignment5 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment5);
  gtk_container_add (GTK_CONTAINER (tbbuttonrch), alignment5);

  hbox5 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox5);
  gtk_container_add (GTK_CONTAINER (alignment5), hbox5);

  image5 = gtk_image_new_from_stock ("gtk-find", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image5);
  gtk_box_pack_start (GTK_BOX (hbox5), image5, FALSE, FALSE, 0);

  label7 = gtk_label_new_with_mnemonic (_("rechercher"));
  gtk_widget_show (label7);
  gtk_box_pack_start (GTK_BOX (hbox5), label7, FALSE, FALSE, 0);

  tblabelhkm = gtk_label_new (_("hotel"));
  gtk_widget_show (tblabelhkm);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tblabelhkm, 616, 184);
  gtk_widget_set_size_request (tblabelhkm, 64, 40);

  tblabelvkm = gtk_label_new (_("ville"));
  gtk_widget_show (tblabelvkm);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tblabelvkm, 600, 232);
  gtk_widget_set_size_request (tblabelvkm, 89, 40);

  tblabele = gtk_label_new (_("etoile"));
  gtk_widget_show (tblabele);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tblabele, 616, 280);
  gtk_widget_set_size_request (tblabele, 80, 32);

  tblabelpkm = gtk_label_new (_("prix"));
  gtk_widget_show (tblabelpkm);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tblabelpkm, 624, 336);
  gtk_widget_set_size_request (tblabelpkm, 64, 32);

  tblabelikm = gtk_label_new (_("id"));
  gtk_widget_show (tblabelikm);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tblabelikm, 624, 384);
  gtk_widget_set_size_request (tblabelikm, 64, 40);

  tblabelmkm = gtk_label_new (_("max reservation"));
  gtk_widget_show (tblabelmkm);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tblabelmkm, 568, 424);
  gtk_widget_set_size_request (tblabelmkm, 120, 48);

  tbajouter_v = gtk_button_new ();
  gtk_widget_show (tbajouter_v);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbajouter_v, 1048, 200);
  gtk_widget_set_size_request (tbajouter_v, 104, 40);

  alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment1);
  gtk_container_add (GTK_CONTAINER (tbajouter_v), alignment1);

  hbox1 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox1);
  gtk_container_add (GTK_CONTAINER (alignment1), hbox1);

  tbimage1 = gtk_image_new_from_stock ("gtk-add", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (tbimage1);
  gtk_box_pack_start (GTK_BOX (hbox1), tbimage1, FALSE, FALSE, 0);

  tblabel1 = gtk_label_new_with_mnemonic (_("ajouter"));
  gtk_widget_show (tblabel1);
  gtk_box_pack_start (GTK_BOX (hbox1), tblabel1, FALSE, FALSE, 0);

  tbafficher_v = gtk_button_new ();
  gtk_widget_show (tbafficher_v);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbafficher_v, 1048, 352);
  gtk_widget_set_size_request (tbafficher_v, 104, 40);

  alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment3);
  gtk_container_add (GTK_CONTAINER (tbafficher_v), alignment3);

  hbox3 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (hbox3);
  gtk_container_add (GTK_CONTAINER (alignment3), hbox3);

  image3 = gtk_image_new_from_stock ("gtk-open", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (image3);
  gtk_box_pack_start (GTK_BOX (hbox3), image3, FALSE, FALSE, 0);

  label3 = gtk_label_new_with_mnemonic (_("afficher"));
  gtk_widget_show (label3);
  gtk_box_pack_start (GTK_BOX (hbox3), label3, FALSE, FALSE, 0);

  tbmodifier_v = gtk_button_new ();
  gtk_widget_show (tbmodifier_v);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbmodifier_v, 1048, 280);
  gtk_widget_set_size_request (tbmodifier_v, 104, 40);

  alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
  gtk_widget_show (alignment4);
  gtk_container_add (GTK_CONTAINER (tbmodifier_v), alignment4);

  tbhbox4 = gtk_hbox_new (FALSE, 2);
  gtk_widget_show (tbhbox4);
  gtk_container_add (GTK_CONTAINER (alignment4), tbhbox4);

  tbimage4 = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
  gtk_widget_show (tbimage4);
  gtk_box_pack_start (GTK_BOX (tbhbox4), tbimage4, FALSE, FALSE, 0);

  tblabel4 = gtk_label_new_with_mnemonic (_("modifier"));
  gtk_widget_show (tblabel4);
  gtk_box_pack_start (GTK_BOX (tbhbox4), tblabel4, FALSE, FALSE, 0);

  tbimage_principale_919b9d_png = create_pixmap (tbwindow1, "image-principale-919b9d.png");
  gtk_widget_show (tbimage_principale_919b9d_png);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbimage_principale_919b9d_png, 8, 0);
  gtk_widget_set_size_request (tbimage_principale_919b9d_png, 296, 472);
  GTK_WIDGET_SET_FLAGS (tbimage_principale_919b9d_png, GTK_CAN_FOCUS);

  tbcomboboxe = gtk_combo_box_new_text ();
  gtk_widget_show (tbcomboboxe);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbcomboboxe, 704, 64);
  gtk_widget_set_size_request (tbcomboboxe, 150, 35);
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxe), _("5"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxe), _("4"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxe), _("3"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxe), _("2"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxe), _("1"));

  tblabel9km = gtk_label_new ("");
  gtk_widget_show (tblabel9km);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tblabel9km, 928, 120);
  gtk_widget_set_size_request (tblabel9km, 280, 40);

  tblabelv = gtk_label_new (_("ville"));
  gtk_widget_show (tblabelv);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tblabelv, 488, 8);
  gtk_widget_set_size_request (tblabelv, 88, 40);

  tblabel_7 = gtk_label_new ("");
  gtk_widget_show (tblabel_7);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tblabel_7, 944, 408);
  gtk_widget_set_size_request (tblabel_7, 320, 40);

  tbcomboboxv = gtk_combo_box_new_text ();
  gtk_widget_show (tbcomboboxv);
  gtk_fixed_put (GTK_FIXED (tbfixed1), tbcomboboxv, 512, 64);
  gtk_widget_set_size_request (tbcomboboxv, 150, 35);
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxv), _("Jerba"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxv), _("Touzer"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxv), _("Tunis"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxv), _("Sousse"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxv), _("Hammamet"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxv), _("Gammarth"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxv), _("Monastir"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxv), _("Mahdia"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxv), _("Midoun"));
  gtk_combo_box_append_text (GTK_COMBO_BOX (tbcomboboxv), _("Nabeul"));

  g_signal_connect ((gpointer) tbbuttonrch, "clicked",
                    G_CALLBACK (tbon_buttonrch_clicked),
                    NULL);
  g_signal_connect ((gpointer) tbajouter_v, "clicked",
                    G_CALLBACK (tbon_ajouter_v_clicked),
                    NULL);
  g_signal_connect ((gpointer) tbafficher_v, "clicked",
                    G_CALLBACK (tbon_afficher_v_clicked),
                    NULL);
  g_signal_connect ((gpointer) tbmodifier_v, "clicked",
                    G_CALLBACK (tbon_modifier_v_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (tbwindow1, tbwindow1, "tbwindow1");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbfixed1, "tbfixed1");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbspinbutton1, "tbspinbutton1");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbspinbutton3, "tbspinbutton3");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbentryi, "tbentryi");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbentry1998, "tbentry1998");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbentry2005, "tbentry2005");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbentry2006, "tbentry2006");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbentry2007, "tbentry2007");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbentry2008, "tbentry2008");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbentry2009, "tbentry2009");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbentry2010, "tbentry2010");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbimage6, "tbimage6");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbcomboboxh, "tbcomboboxh");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabelh, "tblabelh");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabelekm, "tblabelekm");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabelp, "tblabelp");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabeli, "tblabeli");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabelr, "tblabelr");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbbuttonrch, "tbbuttonrch");
  GLADE_HOOKUP_OBJECT (tbwindow1, alignment5, "alignment5");
  GLADE_HOOKUP_OBJECT (tbwindow1, hbox5, "hbox5");
  GLADE_HOOKUP_OBJECT (tbwindow1, image5, "image5");
  GLADE_HOOKUP_OBJECT (tbwindow1, label7, "label7");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabelhkm, "tblabelhkm");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabelvkm, "tblabelvkm");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabele, "tblabele");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabelpkm, "tblabelpkm");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabelikm, "tblabelikm");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabelmkm, "tblabelmkm");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbajouter_v, "tbajouter_v");
  GLADE_HOOKUP_OBJECT (tbwindow1, alignment1, "alignment1");
  GLADE_HOOKUP_OBJECT (tbwindow1, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbimage1, "tbimage1");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabel1, "tblabel1");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbafficher_v, "tbafficher_v");
  GLADE_HOOKUP_OBJECT (tbwindow1, alignment3, "alignment3");
  GLADE_HOOKUP_OBJECT (tbwindow1, hbox3, "hbox3");
  GLADE_HOOKUP_OBJECT (tbwindow1, image3, "image3");
  GLADE_HOOKUP_OBJECT (tbwindow1, label3, "label3");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbmodifier_v, "tbmodifier_v");
  GLADE_HOOKUP_OBJECT (tbwindow1, alignment4, "alignment4");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbhbox4, "tbhbox4");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbimage4, "tbimage4");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabel4, "tblabel4");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbimage_principale_919b9d_png, "tbimage_principale_919b9d_png");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbcomboboxe, "tbcomboboxe");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabel9km, "tblabel9km");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabelv, "tblabelv");
  GLADE_HOOKUP_OBJECT (tbwindow1, tblabel_7, "tblabel_7");
  GLADE_HOOKUP_OBJECT (tbwindow1, tbcomboboxv, "tbcomboboxv");

  gtk_widget_grab_focus (tbimage_principale_919b9d_png);
  gtk_widget_grab_default (tbimage_principale_919b9d_png);
  return tbwindow1;
}

GtkWidget*
create_tbwindow2 (void)
{
  GtkWidget *tbwindow2;
  GtkWidget *tbfixed2;
  GtkWidget *tbtreeview1;
  GtkWidget *tblabel8km;
  GtkWidget *tbimage7;
  GtkWidget *tbbutton_supprimer;
  GtkWidget *tbretour;

  tbwindow2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (tbwindow2), _("list hebergement"));

  tbfixed2 = gtk_fixed_new ();
  gtk_widget_show (tbfixed2);
  gtk_container_add (GTK_CONTAINER (tbwindow2), tbfixed2);

  tbtreeview1 = gtk_tree_view_new ();
  gtk_widget_show (tbtreeview1);
  gtk_fixed_put (GTK_FIXED (tbfixed2), tbtreeview1, 152, 112);
  gtk_widget_set_size_request (tbtreeview1, 952, 416);

  tblabel8km = gtk_label_new ("");
  gtk_widget_show (tblabel8km);
  gtk_fixed_put (GTK_FIXED (tbfixed2), tblabel8km, 680, 56);
  gtk_widget_set_size_request (tblabel8km, 272, 40);

  tbimage7 = create_pixmap (tbwindow2, "arriere plan.jpg");
  gtk_widget_show (tbimage7);
  gtk_fixed_put (GTK_FIXED (tbfixed2), tbimage7, 0, 8);
  gtk_widget_set_size_request (tbimage7, 1280, 544);

  tbbutton_supprimer = gtk_button_new_with_mnemonic (_("supprimer"));
  gtk_widget_show (tbbutton_supprimer);
  gtk_fixed_put (GTK_FIXED (tbfixed2), tbbutton_supprimer, 912, 48);
  gtk_widget_set_size_request (tbbutton_supprimer, 120, 40);

  tbretour = gtk_button_new_from_stock ("retour");
  gtk_widget_show (tbretour);
  gtk_fixed_put (GTK_FIXED (tbfixed2), tbretour, 168, 48);
  gtk_widget_set_size_request (tbretour, 112, 40);

  g_signal_connect ((gpointer) tbbutton_supprimer, "clicked",
                    G_CALLBACK (tbon_button_supprimer_clicked),
                    NULL);
  g_signal_connect ((gpointer) tbretour, "clicked",
                    G_CALLBACK (tbon_retour_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (tbwindow2, tbwindow2, "tbwindow2");
  GLADE_HOOKUP_OBJECT (tbwindow2, tbfixed2, "tbfixed2");
  GLADE_HOOKUP_OBJECT (tbwindow2, tbtreeview1, "tbtreeview1");
  GLADE_HOOKUP_OBJECT (tbwindow2, tblabel8km, "tblabel8km");
  GLADE_HOOKUP_OBJECT (tbwindow2, tbimage7, "tbimage7");
  GLADE_HOOKUP_OBJECT (tbwindow2, tbbutton_supprimer, "tbbutton_supprimer");
  GLADE_HOOKUP_OBJECT (tbwindow2, tbretour, "tbretour");

  return tbwindow2;
}

