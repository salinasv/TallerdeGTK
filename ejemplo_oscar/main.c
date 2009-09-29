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
	g_free(strcompleto);
}

void on_clear_clicked(GtkButton *button, gpointer user_data){
	g_print("Clear!!\n");
}

void on_lookup_clicked(GtkButton *button, gpointer user_data){
	g_print("Look Up!!\n");
}

void on_about_activate(GtkMenuItem *menu_item, gpointer about){
	gtk_widget_show(about);
}
void on_openn_activate(GtkMenuItem *menu_item, gpointer filechooser){
	gtk_widget_show(filechooser);
}

void on_seleccionar_clicked(GtkButton *button, gpointer filechooser){
	g_print("\n\nLa ruta del archivo seleccionado es: ");
	g_print(gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(filechooser)));
	g_print("\n\n");
	gtk_widget_hide(filechooser);
}

void on_filechooser_file_activated(gpointer filechooser){
	g_print("\n\nLa ruta del archivo seleccionado es: ");
	g_print(gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(filechooser)));
	g_print("\n\n");
	gtk_widget_hide(filechooser);
}

	int
main (int argc, char *argv[])
{
	GtkBuilder *builder;
	GtkWidget *miventanita;
	GtkWidget *about;
	GtkWidget *abouthelp;
	GtkWidget *clear;
	GtkWidget *lookup;
	GtkWidget *openn;
	GtkWidget *filechooser;
	GtkButton *seleccionar;
	gtk_init (&argc, &argv);

	builder = gtk_builder_new ();
	gtk_builder_add_from_file (builder, "miventanita.glade", NULL);

	miventanita = GTK_WIDGET (gtk_builder_get_object (builder, "miventanita"));
	filechooser = GTK_WIDGET (gtk_builder_get_object (builder, "filechooser"));
	about = GTK_WIDGET (gtk_builder_get_object (builder, "about"));
	abouthelp = GTK_WIDGET (gtk_builder_get_object (builder, "abouthelp"));
	clear  = GTK_WIDGET (gtk_builder_get_object (builder, "clear1"));
	lookup = GTK_WIDGET (gtk_builder_get_object (builder, "lookup1"));
	tunombre = GTK_LABEL (gtk_builder_get_object (builder,"tunombre"));
	openn = GTK_WIDGET (gtk_builder_get_object (builder,"openn"));
	seleccionar = GTK_BUTTON (gtk_builder_get_object (builder, "seleccionar"));

	nombre=GTK_ENTRY(gtk_builder_get_object (builder,"nombre"));
	ap=GTK_ENTRY(gtk_builder_get_object (builder,"ap"));
	am=GTK_ENTRY(gtk_builder_get_object (builder,"am"));
	gtk_builder_connect_signals (builder, NULL);  

	g_signal_connect(G_OBJECT(abouthelp), "activate", G_CALLBACK(on_about_activate), about);
	g_signal_connect(G_OBJECT(openn), "activate", G_CALLBACK(on_openn_activate), filechooser);
	g_signal_connect(G_OBJECT(seleccionar), "clicked", G_CALLBACK(on_seleccionar_clicked), filechooser);

	g_object_unref (G_OBJECT (builder));
	gtk_widget_show (miventanita);       
	//gtk_label_set_text(label,""); 
	gtk_main ();

	return 0;
}
