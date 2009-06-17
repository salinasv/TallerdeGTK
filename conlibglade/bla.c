#include <gtk/gtk.h>
#include <glade/glade.h>

#define GLADE_FILE "bla.glade"

GtkWidget *label;

void 
on_window1_destroy (GtkObject *object, gpointer user_data)
{
        gtk_main_quit();
}
 
void on_button_pressed (GtkButton *button, gpointer user_data){
	gtk_label_set_text(GTK_LABEL(label),"hola");
}

int
main (int argc, char *argv[])
{
    GladeXML *xml;    
	GtkWidget               *window1;

    gtk_init (&argc, &argv);
        
	xml = glade_xml_new(GLADE_FILE, NULL, NULL);

	window1 = glade_xml_get_widget (xml, "window1");
	label = glade_xml_get_widget (xml, "label");
	
	//g_assert (label != NULL );
	//g_assert (window1 != NULL );

	glade_xml_signal_autoconnect(xml);
	g_object_unref (G_OBJECT (xml));
	gtk_widget_show_all(window1);
	gtk_label_set_text(GTK_LABEL(label),"");
	gtk_main();

	return 0;
}
