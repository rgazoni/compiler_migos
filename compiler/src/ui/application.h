#ifndef GTKMM_APPLICATION_H
#define GTKMM_APPLICATION_H

#include <gtkmm.h>
#include "mainwindow.h"
#include "fileexplorer.h"

class Application : public Gtk::Application
{
protected:
  Application();

public:
  static Glib::RefPtr<Application> create();
  static ExampleWindow *win;

protected:
  //Overrides of default signal handlers:
  void on_startup() override;
  void on_activate() override;

private:
  void create_window();

  void on_menu_openfile();
  void on_menu_savefile();
  void on_menu_file_quit();
  void on_menu_help_about();

  Glib::RefPtr<Gtk::Builder> m_refBuilder;
  FileExplorer fileexplorer;
};

#endif /* GTKMM_APPLICATION_H */