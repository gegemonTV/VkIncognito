#include <stdlib.h>
#include <gtk-3.0/gtk/gtk.h>

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    GtkWidget *window;
    GtkWidget *username_label, *passwd_label;
    GtkWidget *username_entry, *passwd_entry;
    GtkWidget *log_in_button;
    GtkWidget *horizontal_box_username, *horizontal_box_passwd;
    GtkWidget *vertical_box;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "Vk Incognito");
    gtk_window_set_resizable(GTK_WINDOW(window), gtk_true());
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show(window);

    gtk_main();

    return 0;
}
