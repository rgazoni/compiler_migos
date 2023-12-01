#ifndef GTKMM_MAINWINDOW_H
#define GTKMM_MAINWINDOW_H

#include <gtkmm.h>

class MainWindow : public Gtk::ApplicationWindow
{
public:
  MainWindow();
  virtual ~MainWindow();

  Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer;

  //Inteface Functions
  void input_data();
  void output_data();
  static void on_setup_Code_ColumnView(std::string current_filepath);

protected:

  //Child widgets:
  Gtk::Box m_VBox;
  Gtk::Box m_BottomContainer, m_TopContainer;

  Gtk::Box m_CodeBox, m_MemoryBox;
  Gtk::ScrolledWindow m_CodeScrolledWindow, m_MemoryScrolledWindow;
  Gtk::Label m_CodeMachine_Label, m_Memory_Label;
  Gtk::ColumnView m_CodeColumnView, m_MemoryColumnView;

  Gtk::Box m_IOdata, m_InputBox, m_InputRequestBox, m_OutputBox;
  Gtk::Label m_Input_Label, m_Output_Label;
  Gtk::Frame m_Output_Frame;
  Gtk::TextView m_Input_TextView, m_Output_TextView;
  Gtk::ScrolledWindow m_Input_ScrolledWindow;
  Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer_Input;
  Gtk::Button m_InputSubmit_Button;
  Gtk::Button m_Run_Button;


  //Signal handlers
  void on_submit(); //Buttom Submit Input data
  void on_button_run(); //Buttom Run

  // A Gio::ListStore item.
  class ModelCodeColumns : public Glib::Object
  {
  public:
    Glib::ustring m_col_instruction, m_col_label, m_col_firstattr, m_col_secondattr;
    int  m_col_line;

    static Glib::RefPtr<ModelCodeColumns> create(int col_line, const Glib::ustring& col_label,
      const Glib::ustring& col_instruction, const Glib::ustring& col_firstattr, const Glib::ustring& col_secondattr)
    {
      return Glib::make_refptr_for_instance<ModelCodeColumns>(
        new ModelCodeColumns(col_line, col_label, col_instruction, col_firstattr, col_secondattr));
    }

  protected:
    ModelCodeColumns(int col_line, const Glib::ustring& col_label, const Glib::ustring& col_instruction,
      const Glib::ustring& col_firstattr, const Glib::ustring& col_secondattr)
    : m_col_line(col_line), m_col_label(col_label), m_col_instruction(col_instruction), m_col_firstattr(col_firstattr),
      m_col_secondattr(col_secondattr)
    {}
  }; // ModelCodeColumns

    // A Gio::ListStore item.
  class ModelMemoryColumns : public Glib::Object
  {
  public:
    Glib::ustring m_col_address, m_col_value;

    static Glib::RefPtr<ModelMemoryColumns> create(const Glib::ustring& col_address,
      const Glib::ustring& col_value)
    {
      return Glib::make_refptr_for_instance<ModelMemoryColumns>(
        new ModelMemoryColumns(col_address, col_value));
    }

  protected:
    ModelMemoryColumns(const Glib::ustring& col_address, const Glib::ustring& col_value)
    : m_col_address(col_address), m_col_value(col_value)
    {}
  }; // ModelMemoryColumns

  public:
  static Glib::RefPtr<Gio::ListStore<ModelCodeColumns>> m_CodeListStore;
  Glib::RefPtr<Gio::ListStore<ModelMemoryColumns>> m_MemoryListStore;

  //Code Machine Column view methods
  void on_setup_label(const Glib::RefPtr<Gtk::ListItem>& list_item, Gtk::Align halign);
  void on_bind_line(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_bind_label(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_bind_instruction(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_bind_firstattr(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_bind_secondattr(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_bind_address(const Glib::RefPtr<Gtk::ListItem>& list_item);
  void on_bind_value(const Glib::RefPtr<Gtk::ListItem>& list_item);

};

#endif //GTKMM_MAINWINDOW_H