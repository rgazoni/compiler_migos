#include "ui/mainwindow.h"
#include "ui/application.h"
#include <gtkmm/application.h>

int main(int argc, char *argv[]) {
    auto application = Application::create();
    const int status = application->run(argc, argv);
    return status;
}
