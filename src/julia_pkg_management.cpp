//
// Created by yjd20 on 2022/4/20.
//

// You may need to build the project (run Qt uic code generator) to get "ui_julia_pkg_management.h" resolved

#include "julia_pkg_management/julia_pkg_management.h"
#include "julia_pkg_management/httpwindow.h"


JuliaPkgManagement::JuliaPkgManagement(QWidget *parent) :
        QWidget(parent), ui_(new Ui::JuliaPkgManagement) {
    ui_->setupUi(this);
    this->initUI();
    this->setConnectionsBetweenSignalsAndSlots();
    this->getScriptsPath();
}

JuliaPkgManagement::~JuliaPkgManagement() {
    delete ui_;
    delete pkg_manage_model_;
    delete widget_install_pkg_;
}

void JuliaPkgManagement::clearTableData() {
    pkg_manage_model_->clear();
    pkg_manage_model_->setHorizontalHeaderLabels(
            QStringList() << "Package Name" << "Current Version" << "Latest Version");
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
    ui_->tableView_pkg->setSelectionBehavior(QAbstractItemView::SelectRows);

    widget_install_pkg_ = new InstallPkg();
    widget_install_pkg_->setWindowModality(Qt::ApplicationModal);
}

void JuliaPkgManagement::setConnectionsBetweenSignalsAndSlots() {
    connect(ui_->btn_one_click, SIGNAL(clicked()), this, SLOT(installJulia()));
    connect(ui_->btn_auto_check, SIGNAL(clicked()), this, SLOT(checkJuliaEnvAuto()));
    connect(ui_->btn_load, SIGNAL(clicked()), this, SLOT(loadJuliaPath()));
    connect(ui_->lineEdit_executor, SIGNAL(returnPressed()), this, SLOT(editLineFinished()));

    connect(ui_->btn_add, SIGNAL(clicked(bool)), this, SLOT(installPkg()));
    connect(ui_->btn_uninstall, SIGNAL(clicked(bool)), this, SLOT(rmSelectedPkg()));
    connect(ui_->btn_upgrade, SIGNAL(clicked(bool)), this, SLOT(upSelectedPkg()));
    connect(ui_->btn_upgrade_all, SIGNAL(clicked()), this, SLOT(updatePkgAll()));
    connect(ui_->tableView_pkg, SIGNAL(clicked(const QModelIndex &)), this, SLOT(getSelectedRowInTable()));

    // self defined signals and slot
    connect(this->widget_install_pkg_, SIGNAL(senderNewPkg(QString)), this, SLOT(getNewPkgName(QString)));
}

void JuliaPkgManagement::getNewPkgName(QString _new_pkg_name) {
    qDebug() << _new_pkg_name;
}

void JuliaPkgManagement::installPkg() {

    widget_install_pkg_->show();
    /*
    auto new_pkg_name = widget_install_pkg->getNewPkgName();
    while (new_pkg_name==""){
        new_pkg_name = widget_install_pkg->getNewPkgName();
    }
    if (new_pkg_name!="")
    {
        qDebug() << new_pkg_name;
    }
    */
}

void JuliaPkgManagement::upSelectedPkg() {
    if (selected_pkg_name_in_table_ != "") {
        args_.clear();
        args_ << scan_pkg_path_ << "--up-one" << selected_pkg_name_in_table_;
        proc_.start("julia", args_);

        if (!proc_.waitForStarted()) {
            auto error_scan_julia = new QErrorMessage(this);
            error_scan_julia->setWindowTitle("QProcess Exec Error");
            error_scan_julia->showMessage("Can't run: julia scan_pkg.jl --up-one pkg-name");
        }
        proc_.waitForFinished();
        QString up_one_pkg_info = QString::fromLocal8Bit(proc_.readAllStandardOutput());

        up_one_pkg_info = up_one_pkg_info.simplified();
        // qDebug() << rm_pkg_info;
        this->processPkgInfo(up_one_pkg_info);
    } else {
        QMessageBox box;
        box.setText("Please firstly select the pkg in the table which you want uninstall!");
        box.exec();

        return;
    }
}

void JuliaPkgManagement::rmSelectedPkg() {
    if (selected_pkg_name_in_table_ != "") {
        args_.clear();
        args_ << scan_pkg_path_ << "--rm" << selected_pkg_name_in_table_;
        proc_.start("julia", args_);

        if (!proc_.waitForStarted()) {
            auto error_scan_julia = new QErrorMessage(this);
            error_scan_julia->setWindowTitle("QProcess Exec Error");
            error_scan_julia->showMessage("Can't run: julia scan_pkg.jl --rm pkg-name");
        }
        proc_.waitForFinished();
        QString rm_pkg_info = QString::fromLocal8Bit(proc_.readAllStandardOutput());

        rm_pkg_info = rm_pkg_info.simplified();
        // qDebug() << rm_pkg_info;
        this->processPkgInfo(rm_pkg_info);
    } else {
        QMessageBox box;
        box.setText("Please firstly select the pkg in the table which you want uninstall!");
        box.exec();

        return;
    }
}

void JuliaPkgManagement::getSelectedRowInTable() {
    auto selected_table_row_ = ui_->tableView_pkg->currentIndex().row();
    auto selected_pkg_index = pkg_manage_model_->index(selected_table_row_, 0);
    selected_pkg_name_in_table_ = pkg_manage_model_->data(selected_pkg_index).toString();
    // qDebug() << selected_pkg_name_in_table_;
}

void JuliaPkgManagement::updatePkgAll() {
    args_.clear();
    args_ << scan_pkg_path_ << "--up-all";
    proc_.start("julia", args_);

    if (!proc_.waitForStarted()) {
        auto error_scan_julia = new QErrorMessage(this);
        error_scan_julia->setWindowTitle("QProcess Exec Error");
        error_scan_julia->showMessage("Can't run: julia scan_pkg.jl --up-all");
    }
    proc_.waitForFinished();
    QString updated_pkg_info = QString::fromLocal8Bit(proc_.readAllStandardOutput());

    updated_pkg_info = updated_pkg_info.simplified();
    this->processPkgInfo(updated_pkg_info);
}

void JuliaPkgManagement::updateTableModel(const QMap<QString, QString> &_map, VERSION_TYPE _type) {
    this->clearTableData();

    int i_row = 0;
    for (const auto &item_pkg_version: _map.toStdMap()) {
        auto *pkg_name = new QStandardItem(item_pkg_version.first);
        pkg_manage_model_->setItem(i_row, 0, pkg_name);
        // pkg_manage_model_->item(i_row, 0)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        auto *pkg_version = new QStandardItem(item_pkg_version.second);
        pkg_manage_model_->setItem(i_row, 1, pkg_version);
        pkg_manage_model_->item(i_row, 1)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        i_row++;
    }

    this->num_pkg_ = i_row;
}

void JuliaPkgManagement::processPkgInfo(QString &_info) {
    cur_pkg_name_version_.clear();
    auto str_len = _info.length();
    QStringList cur_pkg_info_list{};
    QString cur_pkg_info{};
    while (str_len > 0) {
        auto start = _info.indexOf("]");
        _info = _info.mid(start + 2);
        _info = _info.simplified();
        auto end = _info.indexOf("[");

        if (end > 0) {
            cur_pkg_info = _info.mid(0, end);
            cur_pkg_info = cur_pkg_info.simplified();

            cur_pkg_info_list = cur_pkg_info.split(" ");
            // qDebug() << cur_pkg_info_list;
            if (cur_pkg_info_list.length() == 2) {
                cur_pkg_name_version_.insert(cur_pkg_info_list.at(0), cur_pkg_info_list.at(1).mid(1));
            } else {
                cur_pkg_name_version_.insert(cur_pkg_info_list.at(0), "");
            }

            _info = _info.mid(end + 1);
            str_len = _info.length();
        } else {// walk to the end of last package
            cur_pkg_info_list = _info.split(" ");
            // qDebug() << cur_pkg_info_list;
            if (cur_pkg_info_list.length() == 2) {
                cur_pkg_name_version_.insert(cur_pkg_info_list.at(0), cur_pkg_info_list.at(1).mid(1));
            } else {
                cur_pkg_name_version_.insert(cur_pkg_info_list.at(0), "");
            }

            break;
        }
    }
    // qDebug() << pkg_name_version_;
    this->updateTableModel(cur_pkg_name_version_, VERSION_TYPE::current);
}

void JuliaPkgManagement::scanCurrentPkg() {
    args_.clear();
    args_ << scan_pkg_path_ << "--cur";
    proc_.start("julia", args_);

    if (!proc_.waitForStarted()) {
        auto error_scan_julia = new QErrorMessage(this);
        error_scan_julia->setWindowTitle("QProcess Exec Error");
        error_scan_julia->showMessage("Can't run: julia scan_pkg.jl --cur");
    }
    proc_.waitForFinished();
    QString tmp = QString::fromLocal8Bit(proc_.readAllStandardOutput());

    tmp = tmp.simplified();
    this->processPkgInfo(tmp);
    // qDebug() << tmp;
}

void JuliaPkgManagement::getScriptsPath() {
    QString cur_file_path = QDir::currentPath();
    QString cur_parent_path = cur_file_path.mid(0, cur_file_path.lastIndexOf("/"));
    scan_pkg_path_ = cur_parent_path.append("/").append("scripts/").append("scan_pkg.jl");
    scan_pkg_path_.replace("/", "\\");
    if (scan_pkg_path_.isEmpty()) {
        auto error_scan_julia = new QErrorMessage(this);
        error_scan_julia->setWindowTitle("Fatal Error");
        error_scan_julia->showMessage("Can't get the path of scan_pkg.jl!");

        return;
    }
}

void JuliaPkgManagement::installJulia() {
    QDesktopServices::openUrl(QUrl(QString("https://cn.julialang.org/downloads/")));

    /*
    HttpWindow* dig_download=new HttpWindow(this);
    dig_download->show();
    */

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

            // scan the packages
            this->scanCurrentPkg();

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