#include "mainwindow.h"
#include <iostream>
#include <fstream>
#include "fileexplorer.h"
#include "../virtual_machine/DVM.h"

Glib::RefPtr<Gio::ListStore<MainWindow::ModelCodeColumns>> MainWindow::m_CodeListStore = Gio::ListStore<MainWindow::ModelCodeColumns>::create();

MainWindow::MainWindow()
: Gtk::ApplicationWindow(),
  m_VBox(Gtk::Orientation::VERTICAL),
  m_TopContainer(Gtk::Orientation::HORIZONTAL),
  m_CodeBox(Gtk::Orientation::VERTICAL),
  m_CodeMachine_Label("Code Machine"),
  m_MemoryBox(Gtk::Orientation::VERTICAL),
  m_Memory_Label("Memory"),
  m_IOdata(Gtk::Orientation::VERTICAL),
  m_InputBox(Gtk::Orientation::VERTICAL),
  m_InputRequestBox(Gtk::Orientation::HORIZONTAL),
  m_OutputBox(Gtk::Orientation::VERTICAL),
  m_Input_Label("Input Data"),
  m_InputSubmit_Button("Submit"),
  m_Output_Label("Output Data"),
  m_Run_Button("Run Run Run")
{

  set_title("Virtual Machine");
  set_default_size(1200, 800);

  m_VBox.set_margin(70);
  set_child(m_VBox);

  m_VBox.append(m_TopContainer);
  m_VBox.append(m_BottomContainer);
  m_TopContainer.set_spacing(40);

//------------------ ColumnView Machine Code Implementation ----------------------------

  m_TopContainer.append(m_CodeBox);

  m_CodeMachine_Label.set_halign(Gtk::Align::START);
  m_CodeMachine_Label.set_margin_bottom(10);
  m_CodeMachine_Label.set_margin_start(3);

  // m_CodeColumnView.set_expand();
  m_CodeColumnView.set_size_request(900, -1);

  // - ColumnView w/ scrolled window implementation
  // Add the ColumnView, inside a ScrolledWindow, with the button underneath:
  m_CodeScrolledWindow.set_child(m_CodeColumnView);
  //Only show the scrollbars when they are necessary:
  m_CodeScrolledWindow.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
  m_CodeScrolledWindow.set_expand();

  m_CodeBox.append(m_CodeMachine_Label);
  m_CodeBox.append(m_CodeScrolledWindow);

//-------------------------- CODE_COLUMN_VIEW ---------------------------------------

  // Set list model and selection model.
  auto selection_model = Gtk::SingleSelection::create(m_CodeListStore);
  selection_model->set_autoselect(false);
  selection_model->set_can_unselect(true);
  m_CodeColumnView.set_model(selection_model);
  m_CodeColumnView.add_css_class("data-table"); // high density table

  m_CodeColumnView.set_reorderable(false);

  // Line column
  auto factory = Gtk::SignalListItemFactory::create();
  factory->signal_setup().connect(sigc::bind(sigc::mem_fun(*this,
    &MainWindow::on_setup_label), Gtk::Align::END));
  factory->signal_bind().connect(
    sigc::mem_fun(*this, &MainWindow::on_bind_line));
  auto column = Gtk::ColumnViewColumn::create("Line", factory);
  m_CodeColumnView.append_column(column);

  // Label column
  factory = Gtk::SignalListItemFactory::create();
  factory->signal_setup().connect(sigc::bind(sigc::mem_fun(*this,
    &MainWindow::on_setup_label), Gtk::Align::END));
  factory->signal_bind().connect(
    sigc::mem_fun(*this, &MainWindow::on_bind_label));
  column = Gtk::ColumnViewColumn::create("Label", factory);
  m_CodeColumnView.append_column(column);

  // Instruction column
  factory = Gtk::SignalListItemFactory::create();
  factory->signal_setup().connect(sigc::bind(sigc::mem_fun(*this,
    &MainWindow::on_setup_label), Gtk::Align::START));
  factory->signal_bind().connect(
    sigc::mem_fun(*this, &MainWindow::on_bind_instruction));
  column = Gtk::ColumnViewColumn::create("Instruction", factory);
  column->set_expand();
  m_CodeColumnView.append_column(column);

  // First Attribute column
  factory = Gtk::SignalListItemFactory::create();
  factory->signal_setup().connect(sigc::bind(sigc::mem_fun(*this,
    &MainWindow::on_setup_label), Gtk::Align::END));
  factory->signal_bind().connect(
    sigc::mem_fun(*this, &MainWindow::on_bind_firstattr));
  column = Gtk::ColumnViewColumn::create("First Attribute", factory);
  m_CodeColumnView.append_column(column);

  // Second Attribute column
  factory = Gtk::SignalListItemFactory::create();
  factory->signal_setup().connect(sigc::bind(sigc::mem_fun(*this,
    &MainWindow::on_setup_label), Gtk::Align::END));
  factory->signal_bind().connect(
    sigc::mem_fun(*this, &MainWindow::on_bind_secondattr));
  column = Gtk::ColumnViewColumn::create("Second Attribute", factory);
  m_CodeColumnView.append_column(column);

//------------------ ColumnView Memory Implementation -------------------------

  m_TopContainer.append(m_MemoryBox);

  m_Memory_Label.set_halign(Gtk::Align::START);
  m_Memory_Label.set_margin_bottom(10);
  m_Memory_Label.set_margin_start(3);

  // - ColumnView w/ scrolled window implementation
  // Add the ColumnView, inside a ScrolledWindow, with the button underneath:
  m_MemoryScrolledWindow.set_child(m_MemoryColumnView);
  //Only show the scrollbars when they are necessary:
  m_MemoryScrolledWindow.set_policy(Gtk::PolicyType::AUTOMATIC, Gtk::PolicyType::AUTOMATIC);
  m_MemoryScrolledWindow.set_expand();


  m_MemoryBox.append(m_Memory_Label);
  m_MemoryBox.append(m_MemoryScrolledWindow);

//-------------------------- MEMORY_COLUMN_VIEW ---------------------------------------

  // Create the List model - USED TO APPEND DATA
  m_MemoryListStore = Gio::ListStore<ModelMemoryColumns>::create();
  m_MemoryListStore->append(ModelMemoryColumns::create("1", "2"));
  m_MemoryListStore->append(ModelMemoryColumns::create("30", ""));
  m_MemoryListStore->append(ModelMemoryColumns::create("", ""));

  // Set list model and selection model.
  auto selection_modelm = Gtk::SingleSelection::create(m_MemoryListStore);
  selection_modelm->set_autoselect(false);
  selection_modelm->set_can_unselect(true);
  m_MemoryColumnView.set_model(selection_modelm);
  m_MemoryColumnView.add_css_class("data-table"); // high density table

  m_MemoryColumnView.set_reorderable(false);

  // Address column
  auto factorym = Gtk::SignalListItemFactory::create();
  factorym->signal_setup().connect(sigc::bind(sigc::mem_fun(*this,
    &MainWindow::on_setup_label), Gtk::Align::END));
  factorym->signal_bind().connect(
    sigc::mem_fun(*this, &MainWindow::on_bind_address));
  auto columnm = Gtk::ColumnViewColumn::create("Address", factorym);
  m_MemoryColumnView.append_column(columnm);

  // Value column
  factorym = Gtk::SignalListItemFactory::create();
  factorym->signal_setup().connect(sigc::bind(sigc::mem_fun(*this,
    &MainWindow::on_setup_label), Gtk::Align::START));
  factorym->signal_bind().connect(
    sigc::mem_fun(*this, &MainWindow::on_bind_value));
  columnm = Gtk::ColumnViewColumn::create("Value", factorym);
  columnm->set_expand();
  m_MemoryColumnView.append_column(columnm);

//-----------------------------------------------------------------

//------------------ I/O Implementation -------------------------

  m_BottomContainer.append(m_IOdata);
  m_IOdata.append(m_InputBox);
  m_IOdata.append(m_OutputBox);

  m_IOdata.set_margin_top(30);
  m_IOdata.set_margin_bottom(30);
  m_IOdata.set_spacing(25);

  m_InputBox.append(m_Input_Label);
  m_InputBox.append(m_InputRequestBox);

  m_InputRequestBox.append(m_Input_ScrolledWindow);
  m_InputRequestBox.append(m_InputSubmit_Button);

  m_InputRequestBox.set_spacing(25);

  m_OutputBox.append(m_Output_Label);
  m_OutputBox.append(m_Output_TextView);

  m_Input_Label.set_halign(Gtk::Align::START);
  m_Input_Label.set_margin_bottom(10);
  m_Input_Label.set_margin_start(3);

  m_Input_ScrolledWindow.set_child(m_Input_TextView);
  m_Input_ScrolledWindow.set_policy(Gtk::PolicyType::NEVER, Gtk::PolicyType::NEVER);

  m_Input_TextView.set_size_request(150, -1);
  m_Input_TextView.set_margin_top(8);
  m_Input_TextView.set_margin_bottom(8);
  m_Input_TextView.set_editable(false);
  // BUFFER INPUT TEXTVIEW
  m_refTextBuffer_Input = Gtk::TextBuffer::create();
  m_Input_TextView.set_buffer(m_refTextBuffer_Input);

  m_InputSubmit_Button.signal_clicked().connect(sigc::mem_fun(*this,
              &MainWindow::on_submit) );

  m_Output_Label.set_halign(Gtk::Align::START);
  m_Output_Label.set_margin_bottom(10);
  m_Output_Label.set_margin_start(3);

  m_Output_TextView.set_size_request(522, 100);
  m_Output_TextView.set_editable(false);
  m_Output_TextView.set_cursor_visible(false);

  m_Run_Button.set_margin_start(100);
  m_Run_Button.set_margin_top(30);
  m_Run_Button.set_size_request(400, 50);
  m_BottomContainer.append(m_Run_Button);

  m_Run_Button.signal_clicked().connect(sigc::mem_fun(*this,
            &MainWindow::on_button_run) );

}

MainWindow::~MainWindow()
{
}

// #########################################################################
// Functions for Code Machine and Memory Tables Implementation --------------------------------

void MainWindow::on_setup_label(
  const Glib::RefPtr<Gtk::ListItem>& list_item, Gtk::Align halign)
{
  list_item->set_child(*Gtk::make_managed<Gtk::Label>("", halign));
}

void MainWindow::on_bind_line(const Glib::RefPtr<Gtk::ListItem>& list_item)
{
  auto col = std::dynamic_pointer_cast<ModelCodeColumns>(list_item->get_item());
  if (!col)
    return;
  auto label = dynamic_cast<Gtk::Label*>(list_item->get_child());
  if (!label)
    return;
  label->set_text(Glib::ustring::sprintf("%d", col->m_col_line));
  label->set_halign(Gtk::Align::START);
}

void MainWindow::on_bind_label(const Glib::RefPtr<Gtk::ListItem>& list_item)
{
  auto col = std::dynamic_pointer_cast<ModelCodeColumns>(list_item->get_item());
  if (!col)
    return;
  auto label = dynamic_cast<Gtk::Label*>(list_item->get_child());
  if (!label)
    return;
  label->set_text(Glib::ustring::format(col->m_col_label));
  label->set_halign(Gtk::Align::START);
}

void MainWindow::on_bind_instruction(const Glib::RefPtr<Gtk::ListItem>& list_item)
{
  auto col = std::dynamic_pointer_cast<ModelCodeColumns>(list_item->get_item());
  if (!col)
    return;
  auto label = dynamic_cast<Gtk::Label*>(list_item->get_child());
  if (!label)
    return;
  label->set_text(Glib::ustring::format(col->m_col_instruction));
  label->set_halign(Gtk::Align::START);
}

void MainWindow::on_bind_firstattr(const Glib::RefPtr<Gtk::ListItem>& list_item)
{
  auto col = std::dynamic_pointer_cast<ModelCodeColumns>(list_item->get_item());
  if (!col)
    return;
  auto label = dynamic_cast<Gtk::Label*>(list_item->get_child());
  if (!label)
    return;
  // 10 digits, using leading zeroes.
  label->set_text(Glib::ustring::format(col->m_col_firstattr));
  label->set_halign(Gtk::Align::START);
}

void MainWindow::on_bind_secondattr(const Glib::RefPtr<Gtk::ListItem>& list_item)
{
  auto col = std::dynamic_pointer_cast<ModelCodeColumns>(list_item->get_item());
  if (!col)
    return;
  auto label = dynamic_cast<Gtk::Label*>(list_item->get_child());
  if (!label)
    return;
  label->set_text(Glib::ustring::format(col->m_col_secondattr));
  label->set_halign(Gtk::Align::START);
}

void MainWindow::on_bind_address(const Glib::RefPtr<Gtk::ListItem>& list_item)
{
  auto col = std::dynamic_pointer_cast<ModelMemoryColumns>(list_item->get_item());
  if (!col)
    return;
  auto label = dynamic_cast<Gtk::Label*>(list_item->get_child());
  if (!label)
    return;
  label->set_text(Glib::ustring::format(col->m_col_address));
  label->set_halign(Gtk::Align::START);
}

void MainWindow::on_bind_value(const Glib::RefPtr<Gtk::ListItem>& list_item)
{
  auto col = std::dynamic_pointer_cast<ModelMemoryColumns>(list_item->get_item());
  if (!col)
    return;
  auto label = dynamic_cast<Gtk::Label*>(list_item->get_child());
  if (!label)
    return;
  label->set_text(Glib::ustring::format(col->m_col_value));
  label->set_halign(Gtk::Align::START);
}

void MainWindow::on_setup_Code_ColumnView(std::string current_filepath)
{
  std::ifstream ReadFile(current_filepath);
  int lineInc = 0;

  m_CodeListStore->remove_all();

  std::string line, all;
  while (std::getline(ReadFile, line)) {
        // Cria um stringstream a partir da line
        std::stringstream ss(line);
        // Vetor para armazenar os atributos
        std::vector<std::string> atributos;
        // Variável temporária para armazenar cada parte da linha
        std::string parte;

        // Percorre cada parte separada por espaços em branco
        while (ss >> parte) {
            // Adiciona a parte ao vetor de atributos
            atributos.push_back(parte);
        }

        if(atributos.size() == 0) continue;

        if(atributos.size() == 1){
          m_CodeListStore->append(ModelCodeColumns::create(lineInc, "", atributos[0], "", ""));
          lineInc++;
        }
        else if(std::isdigit(atributos[0][0])){
          m_CodeListStore->append(ModelCodeColumns::create(lineInc, atributos[0], atributos[1], "", ""));
          lineInc++;
        }
        else if(atributos.size() == 2){
          m_CodeListStore->append(ModelCodeColumns::create(lineInc, "", atributos[0], atributos[1], ""));
          lineInc++;
        }
        else /* if(atributos.size() == 3) */{
          m_CodeListStore->append(ModelCodeColumns::create(lineInc, "", atributos[0], atributos[1], atributos[2]));
          lineInc++;
        }
    }
  // Close the file
  ReadFile.close();
}

void MainWindow::on_submit()
{
  std::cout << m_refTextBuffer_Input->get_text() << std::endl;
  m_refTextBuffer_Input->set_text("");
  m_Input_TextView.set_editable(false);
}

void MainWindow::input_data()
{
  m_Input_TextView.set_editable(true);
}

void MainWindow::output_data()
{
  // m_Output_Frame.get
  // Maybe needs to have a static string to keep old outputs as they came in
}

void MainWindow::on_button_run()
{
  if(FileExplorer::current_filepath != ""){
    DVM dvm = DVM();
    dvm.executeFromFile(FileExplorer::current_filepath);
    std::cout << "Success" << std::endl;
  }
  }
