#include <gtk/gtk.h>

typedef struct AppWidgets{
GtkLabel tunombre;
GtkEntry nombre;
GtkEntry ap;
GtkEntry am;
}AppWidgets;

void 
on_miventanita_destroy (GtkObject *object, gpointer user_data)
{
        gtk_main_quit();
}
 
void on_button_pressed (GtkButton *button, gpointer mwp){
	const gchar* espacio=" ";
	const gchar* tnombre = gtk_entry_get_text(mwp.nombre);
	const gchar* tap = gtk_entry_get_text(mwp.ap);
	const gchar* tam = gtk_entry_get_text(mwp.am);
	gchar* strcompleto = g_strconcat(tnombre,espacio,tap,espacio,tam,NULL);
	gtk_label_set_text(mwp.tunombre,strcompleto);
/*	g_free(strcompleto);*/
}

int
main (int argc, char *argv[])
{
        GtkBuilder              *builder;
        GtkWidget               *miventanita;

		AppWidgets mw;
		gpointer mwp = mw;
		gtk_init (&argc, &argv);
        
        builder = gtk_builder_new ();
        gtk_builder_add_from_file (builder, "miventanita.glade", NULL);
 
        miventanita = GTK_WIDGET (gtk_builder_get_object (builder, "miventanita"));
		mw.tunombre = GTK_LABEL (gtk_builder_get_object (builder,"tunombre"));
		mw.nombre=GTK_ENTRY(gtk_builder_get_object (builder,"nombre"));
		mw.ap=GTK_ENTRY(gtk_builder_get_object (builder,"ap"));
		mw.am=GTK_ENTRY(gtk_builder_get_object (builder,"am"));
        gtk_builder_connect_signals (builder, mwp);          
        g_object_unref (G_OBJECT (builder));
        gtk_widget_show (miventanita);       
		//gtk_label_set_text(label,""); 
		gtk_main ();
        
        return 0;
}

