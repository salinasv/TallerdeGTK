#include <gtk/gtk.h>
 

void 
on_window1_destroy (GtkObject *object, gpointer user_data)
{
        gtk_main_quit();
}
 
void on_button_pressed (GtkButton *button, gpointer label){
	gtk_label_set_text(GTK_LABEL(label),"hola");
}

int
main (int argc, char *argv[])
{
        GtkWidget	*window1, *button, *frame, *label;

        gtk_init (&argc, &argv);
        
		window1= gtk_window_new (GTK_WINDOW_TOPLEVEL);
		g_signal_connect (G_OBJECT (window1), "destroy",G_CALLBACK (on_window1_destroy), NULL);
		gtk_window_set_title(GTK_WINDOW(window1), "Bla bla bla");
		
		frame = gtk_fixed_new();
		gtk_container_add(GTK_CONTAINER(window1),frame);


		label = gtk_label_new("");
		button = gtk_button_new_with_label("button");
		g_signal_connect(G_OBJECT(button), "pressed", G_CALLBACK(on_button_pressed), label);
		gtk_fixed_put(GTK_FIXED(frame),button,40,10);

		gtk_fixed_put(GTK_FIXED(frame),label,10,0);
		//gtk_container_add(GTK_CONTAINER(window1),button);
		//gtk_container_add(GTK_CONTAINER(window1),label);

		gtk_widget_show_all(window1);
		gtk_label_set_text(GTK_LABEL(label),"");
		gtk_main ();
        
        return 0;
}

