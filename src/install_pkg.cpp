//
// Created by yjd20 on 2022/4/23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_install_pkg.h" resolved

#include "julia_pkg_management/install_pkg.h"

InstallPkg::InstallPkg(QWidget *parent) :
        QWidget(parent), ui(new Ui::InstallPkg) {
    ui->setupUi(this);

    connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(getPkgName()));
}

void InstallPkg::getPkgName() {
    new_pkg_name_ = ui->lineEdit->text();
    emit this->senderNewPkg(new_pkg_name_);
    this->close();
}

InstallPkg::~InstallPkg() {
    delete ui;
}
