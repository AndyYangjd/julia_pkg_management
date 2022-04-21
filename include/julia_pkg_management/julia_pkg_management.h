#ifndef JULIA_PKG_MANAGEMENT_JULIA_PKG_MANAGEMENT_H
#define JULIA_PKG_MANAGEMENT_JULIA_PKG_MANAGEMENT_H

#include <QWidget>
#include "../../form/ui_julia_pkg_management.h"


QT_BEGIN_NAMESPACE
namespace Ui { class JuliaPkgManagement; }
QT_END_NAMESPACE

class JuliaPkgManagement : public QWidget {
Q_OBJECT

public:
    explicit JuliaPkgManagement(QWidget *parent = nullptr);

    ~JuliaPkgManagement() override;

private:
    Ui::JuliaPkgManagement *ui;
};


#endif //JULIA_PKG_MANAGEMENT_JULIA_PKG_MANAGEMENT_H
