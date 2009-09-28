#include <gtk/gtk.h>

GtkLabel *tunombre;
GtkEntry *nombre;
GtkEntry *ap;
GtkEntry *am;

void 
on_miventanita_destroy (GtkObject *object, gpointer user_data)
{
        gtk_main_quit();
}

void on_button_pressed (GtkButton *button, gpointer user_data){
	const gchar* espacio=" ";
	const gchar* tnombre = gtk_entry_get_text(nombre);
	const gchar* tap = gtk_entry_get_text(ap);
	const gchar* tam = gtk_entry_get_text(am);
	gchar* strcompleto = g_strconcat(tnombre,espacio,tap,espacio,tam,NULL);
	gtk_label_set_text(tunombre,strcompleto);
/*	g_free(strcompleto);*/
}

int
main (int argc, char *argv[])
{
        GtkBuilder              *builder;
        GtkWidget               *miventanita;

		gtk_init (&argc, &argv);
        
        builder = gtk_builder_new ();
        gtk_builder_add_from_file (builder, "miventanita.glade", NULL);
 
        miventanita = GTK_WIDGET (gtk_builder_get_object (builder, "miventanita"));
		tunombre = GTK_LABEL (gtk_builder_get_object (builder,"tunombre"));
		nombre=GTK_ENTRY(gtk_builder_get_object (builder,"nombre"));
		ap=GTK_ENTRY(gtk_builder_get_object (builder,"ap"));
		am=GTK_ENTRY(gtk_builder_get_object (builder,"am"));
        gtk_builder_connect_signals (builder, NULL);          
        g_object_unref (G_OBJECT (builder));
        gtk_widget_show (miventanita);       
		//gtk_label_set_text(label,""); 
		gtk_main ();
        
        return 0;
}

