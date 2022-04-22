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
    delete pkg_manage_model_;
}

void JuliaPkgManagement::initUI() {
    // define the external link of label
    // ui->label_julia->setText("<a href=https://julialang.org>Julia a High Performance and Dynamically Typed Language.");
    ui_->label_julia_hub->setText("<a style='color: green;' href=https://juliahub.com/ui/Home>JuliaHub");
    ui_->label_julia_com_en->setText(
            "<a style='color: black;' href=https://discourse.julialang.org>Julia-Community-EN");
    ui_->label_julia_com_cn->setText("<a style='color: black;' href=https://discourse.juliacn.com>Julia-Community-CN");

    // define the tableModel
    pkg_manage_model_ = new QStandardItemModel(30, 3, this);
    pkg_manage_model_->setHeaderData(0, Qt::Horizontal, tr("Package Name"));
    pkg_manage_model_->setHeaderData(1, Qt::Horizontal, tr("Current Version"));
    pkg_manage_model_->setHeaderData(2, Qt::Horizontal, tr("Latest Version"));

    ui_->tableView_pkg->setModel(pkg_manage_model_);
    ui_->tableView_pkg->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void JuliaPkgManagement::setConnectionsBetweenSignalsAndSlots() {
    connect(ui_->btn_one_click, SIGNAL(clicked()), this, SLOT(installJulia()));
    connect(ui_->btn_auto_check, SIGNAL(clicked()), this, SLOT(checkJuliaEnvAuto()));
    connect(ui_->btn_load, SIGNAL(clicked()), this, SLOT(loadJuliaPath()));
    connect(ui_->lineEdit_executor, SIGNAL(returnPressed()), this, SLOT(editLineFinished()));
}

void JuliaPkgManagement::installJulia() {
    QDesktopServices::openUrl(QUrl(QString("https://cn.julialang.org/downloads/")));
    /*
    args_.clear();
    args_ << "-o" << "C:\\Users\\%username%\\Downloads\\julia-1.7.2-win64.exe"
          << QString("https://mirrors.sjtug.sjtu.edu.cn/julia-releases/bin/winnt/x64/1.7/julia-1.7.2-win64.exe");
    qDebug() << args_;
    proc_.start("curl", args_);
    if (!proc_.waitForStarted()) {
        auto error_curl_julia = new QErrorMessage(this);
        error_curl_julia->setWindowTitle("Error");
        error_curl_julia->showMessage("Can't use curl to download julia-1.7.2-win64.exe! Please install manually.");
    }
    proc_.waitForFinished();
    QString tmp = QString::fromLocal8Bit(proc_.readAllStandardOutput());
    qDebug() << tmp;
    qDebug() << "end";
    */
}

void JuliaPkgManagement::checkJuliaStr() {
    if (julia_path_ != "") {
        julia_path_ = julia_path_.simplified();
        QStringList tmp_list = julia_path_.split("\\");
        QString tmp = tmp_list.back();
        if (tmp == "julia.exe") {
            ui_->lineEdit_executor->setText(julia_path_);
        } else {
            QMessageBox box;
            box.setText("The name of executor isn't julia.exe!");
            box.exec();

            ui_->lineEdit_executor->setText("");
            return;
        }
    } else {
        QMessageBox box;
        box.setText("The Path of Julia is Empty!");
        box.exec();

        ui_->lineEdit_executor->setText("");
        return;
    }
}


void JuliaPkgManagement::editLineFinished() {
    julia_path_ = ui_->lineEdit_executor->text();
    this->checkJuliaStr();
}

void JuliaPkgManagement::checkJuliaEnvAuto() {
    args_.clear();
    args_ << "julia";
    proc_.start("where", args_);

    if (!proc_.waitForStarted()) {
        auto error_scan_julia = new QErrorMessage(this);
        error_scan_julia->setWindowTitle("Error");
        error_scan_julia->showMessage("QProcess exec Error: where julia");
    }
    proc_.waitForFinished();
    julia_path_ = QString::fromLocal8Bit(proc_.readAllStandardOutput());
    this->checkJuliaStr();
}

void JuliaPkgManagement::loadJuliaPath() {
    julia_path_ = QFileDialog::getOpenFileName(this, "Please select the julia.exe", "./", "(*.exe)");
    julia_path_.replace(QString("/"), QString("\\"));
    this->checkJuliaStr();
}