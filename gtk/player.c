#include <gst/gst.h>

#include "player.h"

GstElement *pipeline = NULL;

static void uninit_gst()
{
	gst_element_set_state(GST_ELEMENT(pipeline), GST_STATE_NULL);
	gst_object_unref(GST_OBJECT(pipeline));
}

static gboolean bus_call(GstBus *bus, GstMessage *msg, gpointer user_data)
{
	switch (GST_MESSAGE_TYPE(msg)) {
		case GST_MESSAGE_EOS:
			g_message("End-of-stream");
			uninit_gst(user_data);
			break;
		case GST_MESSAGE_ERROR:
			{
			gchar *debug;
			GError *err;

			gst_message_parse_error(msg, &err, &debug);
			g_free(debug);

			g_error("%s", err->message);
			g_error_free(err);
			uninit_gst(user_data);
			break;
			}
		default:
			break;
	}

	return TRUE;
}

static void init_gst()
{
	//GstElement *pipeline;
	GstBus *bus;

	pipeline = gst_element_factory_make("playbin", "gultec_player");

	bus = gst_pipeline_get_bus(GST_PIPELINE(pipeline));
	gst_bus_add_watch(bus, bus_call, pipeline);
	gst_object_unref(bus);

}

static void dialog_response(GtkDialog *dialog, gint response_id, gpointer user_data)
{
	switch (response_id) {
		case GTK_RESPONSE_REJECT:
			break;
		case GTK_RESPONSE_NO:
			break;
		case GTK_RESPONSE_YES:
			gst_element_set_state(GST_ELEMENT(pipeline), GST_STATE_PLAYING);
			break;
		case GTK_RESPONSE_ACCEPT:
			break;
		case GTK_RESPONSE_CLOSE:
			uninit_gst();
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

	init_gst();

	if (filename) {
		gchar *uri;
		uri = g_strconcat("file://", filename, NULL);
		g_object_set(G_OBJECT(pipeline), "uri", uri, NULL);
		g_free(uri);
	}
	g_free(filename);
}
