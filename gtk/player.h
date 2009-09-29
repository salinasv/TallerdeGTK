#ifndef PLAYER_H
#define PLAYER_H

#include <gtk/gtk.h>

/**
 * Create a new player window and initialize every gst stuff
 */
void player_new(GtkWidget *parent, char *filename);

#endif /* PLAYER_H */
