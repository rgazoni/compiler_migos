#include "mainwindow.h"
#include "fileexplorer.h"
#include "application.h"
#include "../parser.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <thread>
#include <chrono>

ExampleWindow::ExampleWindow()
: Gtk::ApplicationWindow(),
  m_VBox(Gtk::Orientation::VERTICAL),
  m_LnCol_Box(Gtk::Orientation::HORIZONTAL),
  m_Button_Compile("Compile"),
  m_ErrorBox(Gtk::Orientation::VERTICAL),
  m_Errors_Label("Errors"),
  m_BottomContainer(Gtk::Orientation::HORIZONTAL),
  m_ButtonBox(Gtk::Orientation::VERTICAL)
{

  set_title("Compiler");
  set_default_size(1200, 800);

  m_VBox.set_margin(20);
  set_child(m_VBox);

//------------------ TextView w/ scrolled window implementation ----------------------------
  // ScrolledWindow Configuration
  //Add the TreeView, inside a ScrolledWindow, with the button underneath:
  m_ScrolledWindow.set_child(m_TextView);
  //Only show the scrollbars when they are necessary:
  m_ScrolledWindow.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
  m_ScrolledWindow.set_expand();

  m_VBox.append(m_ScrolledWindow);

//-----------------------------------------------------------------------------

//------------------ Line Column Frame ----------------------------------------

  m_VBox.append(m_LnCol_Box);
  m_LnCol_Box.set_halign(Gtk::Align::START);
  m_LnCol_Box.append(m_LnCol_Frame);
  ExampleWindow::m_LnCol_Frame.set_margin_top(7);
  ExampleWindow::m_LnCol_Frame.set_size_request(150, 26);

//-----------------------------------------------------------------------------

  //Append Bottom Container
  m_VBox.append(m_BottomContainer);

//------------------------------ Error Box implementation ----------------------------------

  m_BottomContainer.append(m_ErrorBox);

  // Error Box Configuration
  m_ErrorBox.set_margin_top(20);
  m_ErrorBox.set_margin_bottom(20);

  // Label for error message
  m_ErrorBox.append(m_Errors_Label);

  //Label configuration
  m_Errors_Label.set_halign(Gtk::Align::START);
  m_Errors_Label.set_margin_bottom(10);
  m_Errors_Label.set_margin_start(3);

  m_ErrorBox.append(m_Errors_Frame);
  m_Errors_Frame.set_size_request(850, 80);

//-----------------------------------------------------------------------------

//------------------------------ Button Box implementation ----------------------------------

  //Append Button Box
  m_BottomContainer.append(m_ButtonBox);

  // Compile Button Configuration
  m_ButtonBox.append(m_Button_Compile);
  m_ButtonBox.append(m_Compile_Frame);
  m_ButtonBox.set_margin(5);
  m_ButtonBox.set_valign(Gtk::Align::CENTER);
  m_ButtonBox.set_halign(Gtk::Align::CENTER);
  m_ButtonBox.set_hexpand(true);

  m_Button_Compile.set_margin_top(22);
  m_Button_Compile.set_size_request(250, 15);
  m_Button_Compile.set_hexpand(false);

  m_Compile_Frame.set_margin_top(10);
  m_Compile_Frame.set_size_request(250, 35);

//-----------------------------------------------------------------------------

  //Connect signals:
  // add_action("copy", sigc::mem_fun(*this, &ExampleWindow::on_menu_others));
  // add_action("paste", sigc::mem_fun(*this, &ExampleWindow::on_menu_others));

  m_Button_Compile.signal_clicked().connect(sigc::mem_fun(*this,
              &ExampleWindow::on_button_compile) );

  fill_buffers();

  m_TextView.set_buffer(m_refTextBuffer);

  Glib::signal_timeout().connect(sigc::mem_fun(*this, &ExampleWindow::setLnCol), 10);
}

void ExampleWindow::fill_buffers()
{
  m_refTextBuffer = Gtk::TextBuffer::create();
  m_refTextBuffer->set_text("");

}

ExampleWindow::~ExampleWindow()
{
}

bool ExampleWindow::setLnCol()
{
    Gdk::Rectangle a, b;
    m_TextView.get_cursor_locations(a, b);
    m_LnCol_Frame.set_label(Glib::ustring::sprintf("Ln %d, Col %d", (a.get_y()/12)+1, (a.get_x()/3)+1));
    return true; // Add this line to indicate success
}

void ExampleWindow::on_button_compile()
{
  if(FileExplorer::current_filepath != "")
    parser(FileExplorer::current_filepath.c_str());
  std::cout << "Success" << std::endl;
  // else {
  //   std::string text = Application::win->m_refTextBuffer->get_text();
  //   // Get the current working directory
  //   std::filesystem::path currentPath = std::filesystem::current_path();
  //   // Append the file name to the current working directory
  //   std::filesystem::path currentFilePath = currentPath / "tmp/temporary.txt";

  //   std::string tempFilePath = currentFilePath.string();
  //   // Create and open a text file
  //   std::ofstream MyFile;
  //   // Check if the file is open
  //   MyFile.open(tempFilePath);
  //   if (MyFile.is_open()) {
  //       // Write to the file
  //       MyFile << text;
  //       // Close the file
  //       MyFile.close();
  //       std::cout << "File written successfully to: " << currentFilePath << std::endl;
  //   } else {
  //       std::cerr << "Error opening file: " << currentFilePath << std::endl;
  //   }
  }

  // // Append the file name to the current working directory
  // std::filesystem::path currentFilePath = currentPath / "tmp/temporary.txt";

  // // Create and open a text file
  // std::ofstream MyFile(currentFilePath);

  // // Check if the file is open
  // if (MyFile.is_open()) {
  //     // Write to the file
  //     MyFile << text;

  //     // Close the file
  //     MyFile.close();
  //     std::cout << "File written successfully to: " << currentFilePath << std::endl;
  // } else {
  //     std::cerr << "Error opening file: " << currentFilePath << std::endl;
  // }

// }