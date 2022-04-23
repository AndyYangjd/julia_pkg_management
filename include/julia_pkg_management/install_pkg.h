//
// Created by yjd20 on 2022/4/23.
//

#ifndef JULIA_PKG_MANAGEMENT_INSTALL_PKG_H
#define JULIA_PKG_MANAGEMENT_INSTALL_PKG_H

#include <QWidget>
#include "../../form/ui_install_pkg.h"


QT_BEGIN_NAMESPACE
namespace Ui { class InstallPkg; }
QT_END_NAMESPACE

class InstallPkg : public QWidget {
Q_OBJECT

public:
    explicit InstallPkg(QWidget *parent = nullptr);

    ~InstallPkg() override;

    /*
    QString getNewPkgName() {
        return new_pkg_name_;
    };
    */

signals:
    void senderNewPkg(QString);

private:
    Ui::InstallPkg *ui;

    QString new_pkg_name_{};

private slots:

    void getPkgName();
};


#endif //JULIA_PKG_MANAGEMENT_INSTALL_PKG_H
