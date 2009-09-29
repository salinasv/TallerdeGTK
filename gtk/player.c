#include <gst/gst.h>

#include "player.h"

static void dialog_response(GtkDialog *dialog, gint response_id, gpointer user_data)
{
	switch (response_id) {
		case GTK_RESPONSE_REJECT:
			break;
		case GTK_RESPONSE_NO:
			break;
		case GTK_RESPONSE_YES:
			break;
		case GTK_RESPONSE_ACCEPT:
			break;
		case GTK_RESPONSE_CLOSE:
			gtk_widget_destroy(user_data);
			break;
	}
}

void player_new(GtkWidget *parent, char *filename)
{
	GtkWidget *dialog;
	GtkWidget *button;

	dialog = gtk_dialog_new();
	gtk_window_set_title(GTK_WINDOW(dialog), "GULTEC Player");

	button = gtk_dialog_add_button(GTK_DIALOG(dialog),
			GTK_STOCK_MEDIA_PREVIOUS, GTK_RESPONSE_REJECT);
	
	button = gtk_dialog_add_button(GTK_DIALOG(dialog),
			GTK_STOCK_MEDIA_STOP, GTK_RESPONSE_NO);

	button = gtk_dialog_add_button(GTK_DIALOG(dialog),
			GTK_STOCK_MEDIA_PLAY, GTK_RESPONSE_YES);
	
	button = gtk_dialog_add_button(GTK_DIALOG(dialog),
			GTK_STOCK_MEDIA_NEXT, GTK_RESPONSE_ACCEPT);

	g_signal_connect(dialog, "response",
			G_CALLBACK(dialog_response), dialog);

	gtk_widget_show_all(dialog);

	g_free(filename);
}
