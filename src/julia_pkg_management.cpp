//
// Created by yjd20 on 2022/4/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_julia_pkg_management.h" resolved

#include "julia_pkg_management/julia_pkg_management.h"


JuliaPkgManagement::JuliaPkgManagement(QWidget *parent) :
        QWidget(parent), ui(new Ui::JuliaPkgManagement) {
    ui->setupUi(this);
    this->initUI();
}

JuliaPkgManagement::~JuliaPkgManagement() {
    delete ui;
}

void JuliaPkgManagement::initUI() {
    // ui->label_julia->setText("<a href=https://julialang.org>Julia a High Performance and Dynamically Typed Language.");
    ui->label_julia_hub->setText("<a style='color: green;' href=https://juliahub.com/ui/Home>JuliaHub");
    ui->label_julia_com_en->setText("<a style='color: black;' href=https://discourse.julialang.org>Julia-Community-EN");
    ui->label_julia_com_cn->setText("<a style='color: black;' href=https://discourse.juliacn.com>Julia-Community-CN");
}

void JuliaPkgManagement::setConnectionsBetweenSignalsAndSlots() {

}