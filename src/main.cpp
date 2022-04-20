#include <QApplication>
#include <QPushButton>
#include "../include/julia_pkg_management.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    JuliaPkgManagement app_julia_pkg_management;
    app_julia_pkg_management.show();
    return QApplication::exec();
}
