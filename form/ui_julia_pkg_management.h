/********************************************************************************
** Form generated from reading UI file 'julia_pkg_management.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JULIA_PKG_MANAGEMENT_H
#define UI_JULIA_PKG_MANAGEMENT_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_JuliaPkgManagement
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_julia;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *btn_one_click;
    QPushButton *btn_auto_check;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_julia_hub;
    QLabel *label_julia_com_en;
    QLabel *label_julia_com_cn;
    QFrame *line_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *lineEdit_executor;
    QToolButton *btn_load;
    QSpacerItem *verticalSpacer_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *btn_add;
    QToolButton *btn_uninstall;
    QToolButton *btn_upgrade;
    QToolButton *btn_upgrade_all;
    QSpacerItem *horizontalSpacer_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QTableView *tableView_pkg;

    void setupUi(QWidget *JuliaPkgManagement)
    {
        if (JuliaPkgManagement->objectName().isEmpty())
            JuliaPkgManagement->setObjectName(QString::fromUtf8("JuliaPkgManagement"));
        JuliaPkgManagement->resize(850, 850);
        JuliaPkgManagement->setMinimumSize(QSize(850, 850));
        JuliaPkgManagement->setMaximumSize(QSize(850, 850));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/image/pkg_management.PNG"), QSize(), QIcon::Normal, QIcon::Off);
        JuliaPkgManagement->setWindowIcon(icon);
        JuliaPkgManagement->setLayoutDirection(Qt::LeftToRight);
        JuliaPkgManagement->setAutoFillBackground(true);
        JuliaPkgManagement->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        verticalLayout_3 = new QVBoxLayout(JuliaPkgManagement);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_julia = new QLabel(JuliaPkgManagement);
        label_julia->setObjectName(QString::fromUtf8("label_julia"));
        QFont font;
        font.setPointSize(15);
        font.setUnderline(false);
        label_julia->setFont(font);
        label_julia->setLayoutDirection(Qt::LeftToRight);
        label_julia->setTextFormat(Qt::PlainText);
        label_julia->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_julia->setWordWrap(true);
        label_julia->setOpenExternalLinks(true);
        label_julia->setTextInteractionFlags(Qt::LinksAccessibleByMouse);

        horizontalLayout_2->addWidget(label_julia);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        btn_one_click = new QPushButton(JuliaPkgManagement);
        btn_one_click->setObjectName(QString::fromUtf8("btn_one_click"));
        QFont font1;
        font1.setPointSize(12);
        btn_one_click->setFont(font1);

        verticalLayout_2->addWidget(btn_one_click);

        btn_auto_check = new QPushButton(JuliaPkgManagement);
        btn_auto_check->setObjectName(QString::fromUtf8("btn_auto_check"));
        btn_auto_check->setFont(font1);

        verticalLayout_2->addWidget(btn_auto_check);


        horizontalLayout_2->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_julia_hub = new QLabel(JuliaPkgManagement);
        label_julia_hub->setObjectName(QString::fromUtf8("label_julia_hub"));
        QFont font2;
        font2.setPointSize(10);
        font2.setUnderline(true);
        label_julia_hub->setFont(font2);
        label_julia_hub->setAlignment(Qt::AlignCenter);
        label_julia_hub->setOpenExternalLinks(true);

        verticalLayout->addWidget(label_julia_hub);

        label_julia_com_en = new QLabel(JuliaPkgManagement);
        label_julia_com_en->setObjectName(QString::fromUtf8("label_julia_com_en"));
        label_julia_com_en->setFont(font2);
        label_julia_com_en->setFrameShadow(QFrame::Sunken);
        label_julia_com_en->setAlignment(Qt::AlignCenter);
        label_julia_com_en->setOpenExternalLinks(true);

        verticalLayout->addWidget(label_julia_com_en);

        label_julia_com_cn = new QLabel(JuliaPkgManagement);
        label_julia_com_cn->setObjectName(QString::fromUtf8("label_julia_com_cn"));
        label_julia_com_cn->setFont(font2);
        label_julia_com_cn->setAlignment(Qt::AlignCenter);
        label_julia_com_cn->setOpenExternalLinks(true);

        verticalLayout->addWidget(label_julia_com_cn);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalLayout_2->setStretch(0, 3);

        verticalLayout_3->addLayout(horizontalLayout_2);

        line_2 = new QFrame(JuliaPkgManagement);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_2);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(JuliaPkgManagement);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_5);

        lineEdit_executor = new QLineEdit(JuliaPkgManagement);
        lineEdit_executor->setObjectName(QString::fromUtf8("lineEdit_executor"));
        lineEdit_executor->setFont(font1);

        horizontalLayout->addWidget(lineEdit_executor);

        btn_load = new QToolButton(JuliaPkgManagement);
        btn_load->setObjectName(QString::fromUtf8("btn_load"));
        btn_load->setFont(font1);
        btn_load->setAcceptDrops(false);
        btn_load->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/image/upload.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_load->setIcon(icon1);
        btn_load->setIconSize(QSize(16, 16));
        btn_load->setToolButtonStyle(Qt::ToolButtonIconOnly);
        btn_load->setAutoRaise(true);

        horizontalLayout->addWidget(btn_load);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        line = new QFrame(JuliaPkgManagement);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btn_add = new QToolButton(JuliaPkgManagement);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));
        btn_add->setMinimumSize(QSize(50, 0));
        btn_add->setMaximumSize(QSize(50, 16777215));
        QFont font3;
        font3.setPointSize(10);
        btn_add->setFont(font3);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/image/install.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_add->setIcon(icon2);
        btn_add->setAutoRaise(true);

        horizontalLayout_3->addWidget(btn_add);

        btn_uninstall = new QToolButton(JuliaPkgManagement);
        btn_uninstall->setObjectName(QString::fromUtf8("btn_uninstall"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_uninstall->sizePolicy().hasHeightForWidth());
        btn_uninstall->setSizePolicy(sizePolicy);
        btn_uninstall->setMinimumSize(QSize(50, 0));
        btn_uninstall->setMaximumSize(QSize(50, 16777215));
        btn_uninstall->setFont(font3);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/image/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_uninstall->setIcon(icon3);
        btn_uninstall->setAutoRaise(true);

        horizontalLayout_3->addWidget(btn_uninstall);

        btn_upgrade = new QToolButton(JuliaPkgManagement);
        btn_upgrade->setObjectName(QString::fromUtf8("btn_upgrade"));
        btn_upgrade->setMinimumSize(QSize(50, 0));
        btn_upgrade->setMaximumSize(QSize(50, 16777215));
        btn_upgrade->setFont(font3);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/image/update_one.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_upgrade->setIcon(icon4);
        btn_upgrade->setAutoRaise(true);

        horizontalLayout_3->addWidget(btn_upgrade);

        btn_upgrade_all = new QToolButton(JuliaPkgManagement);
        btn_upgrade_all->setObjectName(QString::fromUtf8("btn_upgrade_all"));
        btn_upgrade_all->setMinimumSize(QSize(50, 0));
        btn_upgrade_all->setMaximumSize(QSize(50, 16777215));
        btn_upgrade_all->setFont(font3);
        btn_upgrade_all->setIcon(icon1);
        btn_upgrade_all->setAutoRaise(true);

        horizontalLayout_3->addWidget(btn_upgrade_all);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 50);

        verticalLayout_3->addLayout(horizontalLayout_3);

        scrollArea = new QScrollArea(JuliaPkgManagement);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 832, 605));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        tableView_pkg = new QTableView(scrollAreaWidgetContents);
        tableView_pkg->setObjectName(QString::fromUtf8("tableView_pkg"));
        tableView_pkg->setAutoScrollMargin(0);
        tableView_pkg->setDragEnabled(true);
        tableView_pkg->setSortingEnabled(true);

        verticalLayout_4->addWidget(tableView_pkg);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_3->addWidget(scrollArea);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(3, 1);
        verticalLayout_3->setStretch(7, 10);

        retranslateUi(JuliaPkgManagement);

        QMetaObject::connectSlotsByName(JuliaPkgManagement);
    } // setupUi

    void retranslateUi(QWidget *JuliaPkgManagement)
    {
        JuliaPkgManagement->setWindowTitle(QCoreApplication::translate("JuliaPkgManagement", "  Pkg Management for Julia", nullptr));
#if QT_CONFIG(tooltip)
        label_julia->setToolTip(QCoreApplication::translate("JuliaPkgManagement", "click this will open the webset of julia", nullptr));
#endif // QT_CONFIG(tooltip)
        label_julia->setText(QCoreApplication::translate("JuliaPkgManagement", "Julia: a High Performance and Dynamically Typed Language.", nullptr));
#if QT_CONFIG(tooltip)
        btn_one_click->setToolTip(QCoreApplication::translate("JuliaPkgManagement", "Install julia with jill(A third package of pip)", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_one_click->setText(QCoreApplication::translate("JuliaPkgManagement", "One-Click to Install", nullptr));
#if QT_CONFIG(tooltip)
        btn_auto_check->setToolTip(QCoreApplication::translate("JuliaPkgManagement", "Auto check the environment of julia.exe", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_auto_check->setText(QCoreApplication::translate("JuliaPkgManagement", "Auto Check(Recommend)", nullptr));
#if QT_CONFIG(tooltip)
        label_julia_hub->setToolTip(QCoreApplication::translate("JuliaPkgManagement", "The webset of julia packages", nullptr));
#endif // QT_CONFIG(tooltip)
        label_julia_hub->setText(QCoreApplication::translate("JuliaPkgManagement", "Julia-Hub", nullptr));
        label_julia_com_en->setText(QCoreApplication::translate("JuliaPkgManagement", "Julia-Community-EN", nullptr));
        label_julia_com_cn->setText(QCoreApplication::translate("JuliaPkgManagement", "Julia-Community-CN", nullptr));
        label_5->setText(QCoreApplication::translate("JuliaPkgManagement", "Julia Executor:", nullptr));
#if QT_CONFIG(tooltip)
        btn_load->setToolTip(QCoreApplication::translate("JuliaPkgManagement", "Please select the path of julia.exe", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_load->setText(QString());
#if QT_CONFIG(tooltip)
        btn_add->setToolTip(QCoreApplication::translate("JuliaPkgManagement", "Install Package", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_add->setText(QString());
#if QT_CONFIG(tooltip)
        btn_uninstall->setToolTip(QCoreApplication::translate("JuliaPkgManagement", "Delete the Selected Package", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_uninstall->setText(QString());
#if QT_CONFIG(tooltip)
        btn_upgrade->setToolTip(QCoreApplication::translate("JuliaPkgManagement", "Upgrade the Selected Package", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_upgrade->setText(QString());
#if QT_CONFIG(tooltip)
        btn_upgrade_all->setToolTip(QCoreApplication::translate("JuliaPkgManagement", "Upgrade All Packages", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_upgrade_all->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class JuliaPkgManagement: public Ui_JuliaPkgManagement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JULIA_PKG_MANAGEMENT_H
