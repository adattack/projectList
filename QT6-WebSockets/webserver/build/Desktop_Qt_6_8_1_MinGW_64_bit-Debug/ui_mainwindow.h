/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_host;
    QPushButton *settings;
    QComboBox *status;
    QTextEdit *textEdit;
    QPushButton *tray;
    QLabel *label_port;
    QLineEdit *host;
    QLineEdit *port;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(565, 389);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        label_host = new QLabel(centralwidget);
        label_host->setObjectName("label_host");

        gridLayout->addWidget(label_host, 1, 0, 1, 1);

        settings = new QPushButton(centralwidget);
        settings->setObjectName("settings");

        gridLayout->addWidget(settings, 0, 1, 1, 1);

        status = new QComboBox(centralwidget);
        status->addItem(QString());
        status->addItem(QString());
        status->setObjectName("status");

        gridLayout->addWidget(status, 0, 0, 1, 1);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 3, 0, 1, 2);

        tray = new QPushButton(centralwidget);
        tray->setObjectName("tray");

        gridLayout->addWidget(tray, 4, 0, 1, 1);

        label_port = new QLabel(centralwidget);
        label_port->setObjectName("label_port");

        gridLayout->addWidget(label_port, 2, 0, 1, 1);

        host = new QLineEdit(centralwidget);
        host->setObjectName("host");

        gridLayout->addWidget(host, 1, 1, 1, 1);

        port = new QLineEdit(centralwidget);
        port->setObjectName("port");

        gridLayout->addWidget(port, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 565, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_host->setText(QCoreApplication::translate("MainWindow", "\344\270\273\346\234\272", nullptr));
        settings->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\224\271\350\256\276\347\275\256", nullptr));
        status->setItemText(0, QCoreApplication::translate("MainWindow", "OFF", nullptr));
        status->setItemText(1, QCoreApplication::translate("MainWindow", "ON", nullptr));

        tray->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\260\217\345\214\226", nullptr));
        label_port->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
