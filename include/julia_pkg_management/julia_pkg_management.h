#ifndef JULIA_PKG_MANAGEMENT_JULIA_PKG_MANAGEMENT_H
#define JULIA_PKG_MANAGEMENT_JULIA_PKG_MANAGEMENT_H

#include <QWidget>
#include <QDesktopServices>
#include <QMessageBox>
#include <QFileDialog>
#include <QProcess>
#include <QErrorMessage>
#include <QStandardItemModel>
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
    Ui::JuliaPkgManagement *ui_;

    QString julia_path_{};
    QProcess proc_;
    QStringList args_;
    QStandardItemModel* pkg_manage_model_;


    void initUI();
    void setConnectionsBetweenSignalsAndSlots();

    void checkJuliaStr();

private slots:
    void checkJuliaEnvAuto();
    void loadJuliaPath();
    void editLineFinished();
};


#endif //JULIA_PKG_MANAGEMENT_JULIA_PKG_MANAGEMENT_H
