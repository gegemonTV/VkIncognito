#include <stdlib.h>
#include "headers/log_in.h"

gchar *login_style = "log_in.css";

gchar *get_file( const gchar * filename)
{
    string temp = "";
    string read_file = "";
    gchar * ret;

    fstream my_file(filename);
    while( getline(my_file, temp) )
    {
        read_file += temp;
        read_file += '\n';
    }
    ret = (gchar*)malloc(sizeof(gchar)*(read_file.length()+1));
    strcpy(ret, read_file.c_str());
    return ret;
}

void write_file( const gchar * filename, gchar * text )
{
    ofstream my_file(filename);
    my_file << text;
    my_file.close();
}


int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    GtkWidget *window;
    GtkWidget *username_label, *passwd_label;
    GtkWidget *username_entry, *passwd_entry;
    GtkWidget *log_in_button;
    GtkWidget *horizontal_box_username, *horizontal_box_passwd;
    GtkWidget *vertical_box;

    // Window Initialization
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Vk Incognito");
    gtk_window_set_resizable(GTK_WINDOW(window), gtk_true());
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 600);
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Labels Initialization
    username_label = gtk_label_new(email_phone_label_ru);
    passwd_label = gtk_label_new(passwd_label);

    gtk_label_set_width_chars(GTK_LABEL(username_label), 16);
    gtk_label_set_width_chars(GTK_LABEL(passwd_label), 16);

    // Entries Initialization
    username_entry = gtk_entry_new();
    passwd_entry = gtk_entry_new();

    gtk_entry_set_placeholder_text(GTK_ENTRY(username_entry), email_phone_placeholder_ru);
    gtk_entry_set_placeholder_text(GTK_ENTRY(passwd_entry), password_placeholder_ru);

    // Buttons Initialization
    log_in_button = gtk_button_new();
    gtk_button_set_label(GTK_BUTTON(log_in_button), log_in_label_ru);

    // Boxes Initialization
    horizontal_box_username = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 12);
    horizontal_box_passwd = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 12);
    vertical_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

    // Packing username objects in box
    gtk_box_pack_start(GTK_BOX(horizontal_box_username), username_label, TRUE, TRUE, 5);
    gtk_box_pack_start(GTK_BOX(horizontal_box_username), username_entry, TRUE, FALSE, 5);

    // Packing password objects in box
    gtk_box_pack_start(GTK_BOX(horizontal_box_passwd), passwd_label, TRUE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(horizontal_box_passwd), passwd_entry, TRUE, FALSE, 5);

    // Packing username and password boxes into vertical box
    gtk_box_pack_start(GTK_BOX(vertical_box), horizontal_box_username, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(vertical_box), horizontal_box_passwd, FALSE, FALSE, 5);

    // Packing log in button into vertical box
    gtk_box_pack_start(GTK_BOX(vertical_box), log_in_button, FALSE, FALSE, 5);

    //Adding vertical box to container
    gtk_container_add(GTK_CONTAINER(window), vertical_box);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
