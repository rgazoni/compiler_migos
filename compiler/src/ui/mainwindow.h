#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>

class ExampleWindow : public Gtk::ApplicationWindow
{
public:
  ExampleWindow();
  virtual ~ExampleWindow();

  Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer, m_refErrorsBuffer, m_refCompileBuffer;


protected:

  void fill_buffers();

  //Signal handlers:
  bool setLnCol();
  void on_button_compile();

  //Child widgets:
  Gtk::Box m_VBox;

  Gtk::Box m_LnCol_Box;
  Gtk::Frame m_LnCol_Frame;

  Gtk::Box m_BottomContainer;

  Gtk::Box m_ErrorBox;
  Gtk::TextView m_Errors_TV;
  Gtk::Label m_Errors_Label;
  Gtk::TextView m_Errors_Output;
  Gtk::ScrolledWindow m_ErrorsScrolledWindow;

  Gtk::ScrolledWindow m_ScrolledWindow;
  Gtk::TextView m_TextView;

  Gtk::Box m_ButtonBox;
  Gtk::Button m_Button_Compile;
  Gtk::TextView m_Compile_TV;
};

#endif //GTKMM_EXAMPLEWINDOW_H