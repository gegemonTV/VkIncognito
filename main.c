#include <stdlib.h>
#include <gtk-3.0/gtk/gtk.h>

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    GtkWidget *window;

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title(GTK_WINDOW(window), "Vk Incognito");
    gtk_window_set_resizable(GTK_WINDOW(window), gtk_true());

    // some shitg
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show(window);

    gtk_main();

    return 0;
}
