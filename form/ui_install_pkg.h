/********************************************************************************
** Form generated from reading UI file 'install_pkg.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTALL_PKG_H
#define UI_INSTALL_PKG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InstallPkg
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QWidget *InstallPkg)
    {
        if (InstallPkg->objectName().isEmpty())
            InstallPkg->setObjectName(QString::fromUtf8("InstallPkg"));
        InstallPkg->resize(720, 50);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InstallPkg->sizePolicy().hasHeightForWidth());
        InstallPkg->setSizePolicy(sizePolicy);
        InstallPkg->setMinimumSize(QSize(720, 50));
        InstallPkg->setMaximumSize(QSize(720, 50));
        horizontalLayout = new QHBoxLayout(InstallPkg);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(InstallPkg);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(InstallPkg);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);


        retranslateUi(InstallPkg);

        QMetaObject::connectSlotsByName(InstallPkg);
    } // setupUi

    void retranslateUi(QWidget *InstallPkg)
    {
        InstallPkg->setWindowTitle(QCoreApplication::translate("InstallPkg", "Install New Package", nullptr));
        label->setText(QCoreApplication::translate("InstallPkg", "Package Name\357\274\232", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("InstallPkg", "Please Input the New Package-Name Here.Than Enter to Comfirm.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InstallPkg: public Ui_InstallPkg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTALL_PKG_H
