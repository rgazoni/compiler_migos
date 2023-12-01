#ifndef GTKMM_FILEEXPLORER_H
#define GTKMM_FILEEXPLORER_H

#include <gtkmm.h>
#include <string>

class FileExplorer
{

public:
  FileExplorer();
  virtual ~FileExplorer();
  static std::string current_filepath;

public:
  //Signal handlers:
  void on_openfile();
  void on_savefile();
  void on_openfile_dialog_response(int response_id, Gtk::FileChooserDialog* dialog);


};

#endif //GTKMM_FILEEXPLORER_H