#include <gtk-3.0/gtk/gtk.h>

gchar *login_style = "styles/log_in.css";
gchar *login_builder = "styles/log_in_scene.glade";

const gchar *log_in_label_ru = "Вход";
const gchar *email_phone_label_ru = "Эл. почта или телефон:";
const gchar *password_label_ru = "Пароль: ";
const gchar *email_phone_placeholder_ru = "Введите эл. почту или телефон...";
const gchar *password_placeholder_ru = "Введите пароль...";


void refresh_css(gchar *stylefile)
{
    GtkCssProvider *provider;
    GdkScreen *screen;
    GdkDisplay *display;

    /* Apply CSS */
    provider = gtk_css_provider_new ();
    display = gdk_display_get_default ();
    screen = gdk_display_get_default_screen (display);
    gtk_style_context_add_provider_for_screen (screen, GTK_STYLE_PROVIDER (provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    GError *error = 0;
    gtk_css_provider_load_from_file(provider, g_file_new_for_path(stylefile), &error);
    g_object_unref(provider);
    /**/
}


int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    GtkWidget  *window;
    GtkBuilder *builder;

    GtkWidget  *vk_image;

    builder = gtk_builder_new();
    gtk_builder_add_from_file(GTK_BUILDER(builder), login_builder, NULL);

    window = GTK_WIDGET(gtk_builder_get_object(builder, "login_window"));
    gtk_window_set_icon_from_file(GTK_WINDOW(window), "styles/vk.png", 0);

    vk_image = GTK_WIDGET(gtk_builder_get_object(builder, "vk_image"));

    gtk_image_set_from_file(GTK_IMAGE(vk_image), "styles/vk.png");


    g_object_unref(builder);

    refresh_css(login_style);

    gtk_widget_show(window);

    gtk_main();

    return 0;
}


