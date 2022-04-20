//
// Created by yjd20 on 2022/4/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_julia_pkg_management.h" resolved

#include "../include/julia_pkg_management.h"



JuliaPkgManagement::JuliaPkgManagement(QWidget *parent) :
        QWidget(parent), ui(new Ui::JuliaPkgManagement) {
    ui->setupUi(this);
}

JuliaPkgManagement::~JuliaPkgManagement() {
    delete ui;
}
