/********************************************************************************
** Form generated from reading UI file 'julia_pkg_management.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JULIA_PKG_MANAGEMENT_H
#define UI_JULIA_PKG_MANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JuliaPkgManagement
{
public:

    void setupUi(QWidget *JuliaPkgManagement)
    {
        if (JuliaPkgManagement->objectName().isEmpty())
            JuliaPkgManagement->setObjectName(QString::fromUtf8("JuliaPkgManagement"));
        JuliaPkgManagement->resize(400, 300);

        retranslateUi(JuliaPkgManagement);

        QMetaObject::connectSlotsByName(JuliaPkgManagement);
    } // setupUi

    void retranslateUi(QWidget *JuliaPkgManagement)
    {
        JuliaPkgManagement->setWindowTitle(QCoreApplication::translate("JuliaPkgManagement", "JuliaPkgManagement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class JuliaPkgManagement: public Ui_JuliaPkgManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JULIA_PKG_MANAGEMENT_H
