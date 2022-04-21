//
// Created by yjd20 on 2022/4/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_julia_pkg_management.h" resolved

#include "julia_pkg_management/julia_pkg_management.h"


JuliaPkgManagement::JuliaPkgManagement(QWidget *parent) :
        QWidget(parent), ui_(new Ui::JuliaPkgManagement) {
    ui_->setupUi(this);
    this->initUI();
    this->setConnectionsBetweenSignalsAndSlots();
}

JuliaPkgManagement::~JuliaPkgManagement() {
    delete ui_;
}

void JuliaPkgManagement::initUI() {
    // ui->label_julia->setText("<a href=https://julialang.org>Julia a High Performance and Dynamically Typed Language.");
    ui_->label_julia_hub->setText("<a style='color: green;' href=https://juliahub.com/ui/Home>JuliaHub");
    ui_->label_julia_com_en->setText("<a style='color: black;' href=https://discourse.julialang.org>Julia-Community-EN");
    ui_->label_julia_com_cn->setText("<a style='color: black;' href=https://discourse.juliacn.com>Julia-Community-CN");
}

void JuliaPkgManagement::setConnectionsBetweenSignalsAndSlots() {
    connect(ui_->btn_auto_check, SIGNAL(clicked()), this, SLOT(checkJuliaEnvAuto()));
    connect(ui_->btn_load, SIGNAL(clicked()), this, SLOT(loadJuliaPath()));
}

void JuliaPkgManagement::checkJuliaEnvAuto() {

}

void JuliaPkgManagement::loadJuliaPath() {
    julia_path_ = QFileDialog::getOpenFileName(this, "Please select the julia.exe", "./", "(*.exe)");
    if (julia_path_.isEmpty())
    {
        QMessageBox box;
        box.setText("Your input is empty. Please select the file of julia.exe");
        box.exec();

        ui_->lineEdit_executor->setText("");
        return;
    }
    else
    {
        julia_path_ = julia_path_.simplified();
        QStringList tmp_list = julia_path_.split("/");
        QString tmp = tmp_list.back();
        if (tmp=="julia.exe"){
            ui_->lineEdit_executor->setText(julia_path_);
        }else{
            QMessageBox box;
            box.setText("Your file is not julia.exe. Please select the file of julia.exe");
            box.exec();

            ui_->lineEdit_executor->setText("");
            return;
        }
    }
}