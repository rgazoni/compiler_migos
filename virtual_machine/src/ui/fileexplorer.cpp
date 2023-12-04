#include "fileexplorer.h"
#include "application.h"
#include "mainwindow.h"
#include <iostream>
#include <fstream>
#include <string>

std::string FileExplorer::current_filepath = "";

FileExplorer::FileExplorer()
{
}

FileExplorer::~FileExplorer()
{
}

void FileExplorer::on_openfile()
{
    auto dialog = new Gtk::FileChooserDialog("Please choose a file",
            Gtk::FileChooser::Action::OPEN);
    
    // TODO dialog->set_transient_for(Application::win);

    dialog->set_modal(true);
    dialog->signal_response().connect(sigc::bind(
        sigc::mem_fun(*this, &FileExplorer::on_openfile_dialog_response), dialog));

    //Add response buttons to the dialog:
    dialog->add_button("_Cancel", Gtk::ResponseType::CANCEL);
    dialog->add_button("_Open", Gtk::ResponseType::OK);

    //Add filters, so that only certain file types can be selected:
    auto filter_text = Gtk::FileFilter::create();
    filter_text->set_name("Text files");
    filter_text->add_mime_type("text/plain");
    dialog->add_filter(filter_text);

    auto filter_cpp = Gtk::FileFilter::create();
    filter_cpp->set_name("C/C++ files");
    filter_cpp->add_mime_type("text/x-c");
    filter_cpp->add_mime_type("text/x-c++");
    filter_cpp->add_mime_type("text/x-c-header");
    dialog->add_filter(filter_cpp);

    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog->add_filter(filter_any);

    //Show the dialog and wait for a user response:
    dialog->show();
}

void FileExplorer::on_openfile_dialog_response(int response_id, Gtk::FileChooserDialog* dialog)
{
    //Handle the response:
    switch (response_id)
    {
        case Gtk::ResponseType::OK:
        {
            std::cout << "[DEBUG]   Open clicked." << std::endl;

            current_filepath = dialog->get_file()->get_path();
            std::cout << "[DEBUG]   File selected: " << current_filepath.c_str() << std::endl;

            MainWindow::on_setup_Code_ColumnView(current_filepath);

        break;
        }
        case Gtk::ResponseType::CANCEL:
        {
            std::cout << "Cancel clicked." << std::endl;
        break;
        }
        default:
        {
            std::cout << "Unexpected button clicked." << std::endl;
        break;
        }
    }
    delete dialog;
}
