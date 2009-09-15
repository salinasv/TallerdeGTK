#include <gtk/gtk.h>

#define PAPA 0
 
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
        GtkWidget	*window1, *button;
#if PAPA
	    GtkWidget	*frame;
#else
		GtkWidget 	*vbox;
#endif

        gtk_init (&argc, &argv);
        
		window1= gtk_window_new (GTK_WINDOW_TOPLEVEL);
		g_signal_connect (G_OBJECT (window1), "destroy",G_CALLBACK (on_window1_destroy), NULL);
		gtk_window_set_title(GTK_WINDOW(window1), "Bla bla bla");
		
#if PAPA
		frame = gtk_fixed_new();
		gtk_container_add(GTK_CONTAINER(window1),frame);
#else
		vbox = gtk_vbox_new(FALSE, 0);
#endif


		label = gtk_label_new("");
		button = gtk_button_new_with_label("button");
		g_signal_connect(G_OBJECT(button), "pressed", G_CALLBACK(on_button_pressed), NULL);
#if PAPA
		gtk_fixed_put(GTK_FIXED(frame),button,40,10);

		gtk_fixed_put(GTK_FIXED(frame),label,10,0);
		//gtk_container_add(GTK_CONTAINER(window1),button);
		//gtk_container_add(GTK_CONTAINER(window1),label);
#else
		gtk_container_add(GTK_CONTAINER(vbox), label);
		gtk_container_add(GTK_CONTAINER(vbox), button);

		gtk_container_add(GTK_CONTAINER(window1), vbox);
#endif

		gtk_widget_show_all(window1);
		gtk_label_set_text(GTK_LABEL(label),"");
		gtk_main ();
        
        return 0;
}

