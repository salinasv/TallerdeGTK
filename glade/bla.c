#include <gtk/gtk.h>
 
GtkLabel *label;

void 
on_window1_destroy (GtkObject *object, gpointer user_data)
{
        gtk_main_quit();
}
 
void on_button_pressed (GtkButton *button, gpointer user_data){
	gtk_label_set_text(label,"hola");
}

int
main (int argc, char *argv[])
{
        GtkBuilder              *builder;
        GtkWidget               *window1;

        gtk_init (&argc, &argv);
        
        builder = gtk_builder_new ();
        gtk_builder_add_from_file (builder, "bla.xml", NULL);
 
        window1 = GTK_WIDGET (gtk_builder_get_object (builder, "window1"));
		label = GTK_LABEL (gtk_builder_get_object (builder,"label"));
        gtk_builder_connect_signals (builder, NULL);          
        g_object_unref (G_OBJECT (builder));
        gtk_widget_show (window1);       
		gtk_label_set_text(label,""); 
		gtk_main ();
        
        return 0;
}

