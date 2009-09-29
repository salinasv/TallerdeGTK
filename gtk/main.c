#include <gtk/gtk.h>

typedef struct name_
{
	GtkWidget *name;
	GtkWidget *pat;
	GtkWidget *mat;
	GtkWidget *label;
	gchar *fullname;
}Name;

static void lookup_character_action()
{
	g_print("lookup\n");
}

static void clear_character_action()
{
	g_print("clear!\n");
}

static void quit_action()
{
	gtk_main_quit();
}

static GtkActionEntry entries[] = 
{
	{ "FileMenuAction", NULL, "_File" },                  /* name, stock id, label */
	{ "CharacterMenuAction", NULL, "_Character" },

	{ "NewAction", GTK_STOCK_NEW, "_New" },
	{ "OpenAction", GTK_STOCK_OPEN, "_Open" },
	{ "SaveAction", GTK_STOCK_SAVE, "_Save"},
	{ "SaveAsAction", GTK_STOCK_SAVE, "Save _As"},

	{ "LookupAction", GTK_STOCK_FIND,                             /* name, stock id */
		"_Lookup", "<control>L",                                    /* label, accelerator */
		"Look-up the character drawn",                              /* tooltip */ 
		G_CALLBACK (lookup_character_action) },

	{ "ClearAction", GTK_STOCK_OPEN,
		"_Clear","<control>C",  
		"Clear the drawing area",
		G_CALLBACK (clear_character_action) },

	{ "QuitAction", GTK_STOCK_QUIT,
		"_Quit", "<control>Q",    
		"Quit",
		G_CALLBACK (quit_action) }
};
static guint n_entries = G_N_ELEMENTS (entries);

	void 
on_window1_destroy (GtkObject *object, gpointer user_data)
{
	gtk_main_quit();
}

void on_button_pressed (GtkButton *button, gpointer userdata){
	Name *usrname = (Name*)userdata;

	g_free(usrname->fullname);

	usrname->fullname = NULL;
	usrname->fullname = g_strconcat(
			"Tu nombre es: ",
			gtk_entry_get_text(GTK_ENTRY(usrname->name)),
			" ",
			gtk_entry_get_text(GTK_ENTRY(usrname->pat)),
			" ",
			gtk_entry_get_text(GTK_ENTRY(usrname->mat)),
			NULL);
	gtk_label_set_text(GTK_LABEL(usrname->label), usrname->fullname);
}

	int
main (int argc, char *argv[])
{
	GtkWidget	*window1, *button;
	GtkWidget *main_win;
	GtkWidget *label;
	GtkWidget *hbox;
	GtkWidget *vbox;
	GtkWidget *menu_box;
	GtkWidget *menubar;
	GtkWidget *toolbar;
	GtkUIManager *ui_manager;
	GtkActionGroup *action_group;
	GError *error = NULL;
	Name *usr_name;
	gint ui_id;

	gtk_init (&argc, &argv);

	window1= gtk_window_new (GTK_WINDOW_TOPLEVEL);
	g_signal_connect (G_OBJECT (window1), "destroy",G_CALLBACK (on_window1_destroy), NULL);
	gtk_window_set_title(GTK_WINDOW(window1), "Bla bla bla");

	/* GtkUIManager Menu and tooltip stuff */
	action_group = gtk_action_group_new("TestActions");
	gtk_action_group_add_actions(action_group, entries, n_entries, NULL);

	ui_manager = gtk_ui_manager_new();
	gtk_ui_manager_insert_action_group(ui_manager, action_group, 0);

	ui_id = gtk_ui_manager_add_ui_from_file(ui_manager, "menus.xml", &error);

	/* Pack the menu and toolbar */
	menu_box = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window1), menu_box);

	menubar = gtk_ui_manager_get_widget(ui_manager, "/MainMenu");
	toolbar = gtk_ui_manager_get_widget(ui_manager, "/MainToolbar");
	gtk_box_pack_start(GTK_BOX(menu_box), menubar, FALSE, FALSE, 0);
	gtk_box_pack_start(GTK_BOX(menu_box), toolbar, FALSE, FALSE, 0);

	/* Main window stuff */
	main_win = gtk_vbox_new(FALSE, 0);
	gtk_box_pack_start(GTK_BOX(menu_box),main_win, FALSE, FALSE, 0);

	usr_name = g_new(Name, 1);
	usr_name->label = gtk_label_new("Tu nombre es:");

	hbox = gtk_hbox_new(FALSE, 0);

	/* Labels */
	vbox = gtk_vbox_new(TRUE, 0);
	label = gtk_label_new("Nombre");
	gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
	label = gtk_label_new("Apellido Paterno");
	gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
	label = gtk_label_new("Apellido Materno");
	gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);

	gtk_box_pack_start(GTK_BOX(hbox), vbox, FALSE, FALSE, 0);

	/* Entries */
	vbox = gtk_vbox_new(FALSE, 0);
	usr_name->name = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(vbox), usr_name->name, FALSE, FALSE, 0);
	usr_name->pat = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(vbox), usr_name->pat, FALSE, FALSE, 0);
	usr_name->mat = gtk_entry_new();
	gtk_box_pack_start(GTK_BOX(vbox), usr_name->mat, FALSE, FALSE, 0);

	gtk_box_pack_start(GTK_BOX(hbox), vbox, FALSE, FALSE, 0);

	gtk_box_pack_start(GTK_BOX(main_win), hbox, FALSE, FALSE, 0);

	button = gtk_button_new_with_label("button");
	g_signal_connect(G_OBJECT(button), "pressed", G_CALLBACK(on_button_pressed), usr_name);
	gtk_box_pack_start(GTK_BOX(main_win),button, FALSE, FALSE, 0);

	gtk_box_pack_start(GTK_BOX(main_win), usr_name->label, FALSE, FALSE, 0);
	//gtk_container_add(GTK_CONTAINER(window1),button);
	//gtk_container_add(GTK_CONTAINER(window1),label);

	gtk_widget_show_all(window1);
	gtk_main ();

	return 0;
}

