#ifndef JULIA_PKG_MANAGEMENT_JULIA_PKG_MANAGEMENT_H
#define JULIA_PKG_MANAGEMENT_JULIA_PKG_MANAGEMENT_H

#include <QWidget>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QProcess>
#include <QErrorMessage>
#include <QStandardItemModel>
#include <QMap>
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
    enum VERSION_TYPE{current=0, latest=1};
    Ui::JuliaPkgManagement *ui_;

    QString julia_path_{};
    QProcess proc_;
    QStringList args_;
    QStandardItemModel* pkg_manage_model_;

    QString scan_pkg_path_{};
    unsigned int num_pkg_{0};
    QMap<QString, QString> cur_pkg_name_version_{};
    QMap<QString, QString> latest_pkg_name_version_{};

    QString selected_pkg_name_in_table_{};

    void initUI();
    void setConnectionsBetweenSignalsAndSlots();

    void checkJuliaStr();

    void getScriptsPath();
    void scanCurrentPkg();
    void processPkgInfo(QString&);
    void clearTableData();
    void updateTableModel(const QMap<QString, QString>&, VERSION_TYPE);

private slots:
    void checkJuliaEnvAuto();
    void loadJuliaPath();
    void editLineFinished();
    void installJulia();

    void getSelectedRowInTable();
    void rmSelectedPkg();
    void updatePkgAll();
};


#endif //JULIA_PKG_MANAGEMENT_JULIA_PKG_MANAGEMENT_H
