#include "application.h"
#include "mainwindow.h"
#include "fileexplorer.h"
#include <iostream>

//Declaring static
ExampleWindow *Application::win;

Application::Application()
: Gtk::Application("org.gtkmm.main_menu"),
  fileexplorer(FileExplorer())
{
}

Glib::RefPtr<Application> Application::create()
{
  return Glib::make_refptr_for_instance<Application>(new Application());
}

void Application::on_startup()
{
  //Call the base class's implementation:
  Gtk::Application::on_startup();

  //Create actions for menus and toolbars.
  //We can use add_action() because Gtk::Application derives from Gio::ActionMap.

  //File|New sub menu:
  add_action("openfile",
    sigc::mem_fun(*this, &Application::on_menu_openfile));

  add_action("savefile",
    sigc::mem_fun(*this, &Application::on_menu_savefile));

  //File menu:
  add_action("quit", sigc::mem_fun(*this, &Application::on_menu_file_quit));

  //Help menu:
  add_action("about", sigc::mem_fun(*this, &Application::on_menu_help_about));

  // Set accelerator keys:
  set_accel_for_action("app.openfile", "<Primary>n");
  set_accel_for_action("app.savefile", "<Primary>s");
  set_accel_for_action("app.quit", "<Primary>q");
  set_accel_for_action("win.copy", "<Primary>c");
  set_accel_for_action("win.paste", "<Primary>v");

  m_refBuilder = Gtk::Builder::create();

  //Layout the actions in a menubar and a menu:
  Glib::ustring ui_info =
    "<interface>"
    "  <!-- menubar -->"
    "  <menu id='menu-container'>"
    "    <submenu>"
    "      <attribute name='label' translatable='yes'>_Compiler</attribute>"
    "      <section>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>Open _File</attribute>"
    "          <attribute name='action'>app.openfile</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;n</attribute>"
    "        </item>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>Save _File</attribute>"
    "          <attribute name='action'>app.savefile</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;s</attribute>"
    "        </item>"
    "      </section>"
    "      <section>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>_Quit</attribute>"
    "          <attribute name='action'>app.quit</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;q</attribute>"
    "        </item>"
    "      </section>"
    "    </submenu>"
    "    <submenu>"
    "      <attribute name='label' translatable='yes'>_Edit</attribute>"
    "      <section>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>_Copy</attribute>"
    "          <attribute name='action'>win.copy</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;c</attribute>"
    "        </item>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>_Paste</attribute>"
    "          <attribute name='action'>win.paste</attribute>"
    "          <attribute name='accel'>&lt;Primary&gt;v</attribute>"
    "        </item>"
    "      </section>"
    "    </submenu>"
    "    <submenu>"
    "      <attribute name='label' translatable='yes'>_Help</attribute>"
    "      <section>"
    "        <item>"
    "          <attribute name='label' translatable='yes'>_About App</attribute>"
    "          <attribute name='action'>app.about</attribute>"
    "        </item>"
    "      </section>"
    "    </submenu>"
    "  </menu>"
    "</interface>";

  try
  {
    m_refBuilder->add_from_string(ui_info);
  }
  catch (const Glib::Error& ex)
  {
    std::cerr << "Building menus failed: " << ex.what();
  }

  //Get the menubar and the app menu, and add them to the application:
  auto gmenu = m_refBuilder->get_object<Gio::Menu>("menu-container");
  if (!gmenu)
  {
    g_warning("GMenu not found");
  }
  else
  {
    set_menubar(gmenu);
  }
}

void Application::on_activate()
{
  //std::cout << "debug1: " << G_STRFUNC << std::endl;
  // The application has been started, so let's show a window.
  // A real application might want to reuse this window in on_open(),
  // when asked to open a file, if no changes have been made yet.
  create_window();
}

void Application::create_window()
{
  win = new ExampleWindow();

  //Make sure that the application runs for as long this window is still open:
  add_window(*win);

  //Delete the window when it is hidden.
  //That's enough for this simple example.
  win->signal_hide().connect([this]() { delete win; });

  win->set_show_menubar();
  win->set_visible(true);
}

void Application::on_menu_openfile()
{
  fileexplorer.on_openfile();
}

void Application::on_menu_savefile()
{
  fileexplorer.on_savefile();
}



void Application::on_menu_file_quit()
{
  std::cout << G_STRFUNC << std::endl;
  quit(); // Not really necessary, when Gtk::Widget::set_visible(false) is called.

  // Gio::Application::quit() will make Gio::Application::run() return,
  // but it's a crude way of ending the program. The window is not removed
  // from the application. Neither the window's nor the application's
  // destructors will be called, because there will be remaining reference
  // counts in both of them. If we want the destructors to be called, we
  // must remove the window from the application. One way of doing this
  // is to hide the window.
  std::vector<Gtk::Window*> windows = get_windows();
  if (windows.size() > 0)
    windows[0]->set_visible(false); // In this simple case, we know there is only one window.
}

void Application::on_menu_help_about()
{
  std::cout << "Help|About App was selected." << std::endl;
}