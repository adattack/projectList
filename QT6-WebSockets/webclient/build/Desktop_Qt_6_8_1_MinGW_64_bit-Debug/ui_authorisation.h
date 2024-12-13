/********************************************************************************
** Form generated from reading UI file 'authorisation.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORISATION_H
#define UI_AUTHORISATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Authorisation
{
public:
    QGridLayout *gridLayout;
    QLineEdit *nick;
    QLineEdit *port;
    QPushButton *ok;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Authorisation)
    {
        if (Authorisation->objectName().isEmpty())
            Authorisation->setObjectName("Authorisation");
        Authorisation->resize(377, 124);
        gridLayout = new QGridLayout(Authorisation);
        gridLayout->setObjectName("gridLayout");
        nick = new QLineEdit(Authorisation);
        nick->setObjectName("nick");

        gridLayout->addWidget(nick, 0, 1, 1, 1);

        port = new QLineEdit(Authorisation);
        port->setObjectName("port");

        gridLayout->addWidget(port, 2, 1, 1, 1);

        ok = new QPushButton(Authorisation);
        ok->setObjectName("ok");

        gridLayout->addWidget(ok, 0, 2, 1, 1);

        label = new QLabel(Authorisation);
        label->setObjectName("label");

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_2 = new QLabel(Authorisation);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);


        retranslateUi(Authorisation);

        QMetaObject::connectSlotsByName(Authorisation);
    } // setupUi

    void retranslateUi(QDialog *Authorisation)
    {
        Authorisation->setWindowTitle(QCoreApplication::translate("Authorisation", "Dialog", nullptr));
        nick->setPlaceholderText(QCoreApplication::translate("Authorisation", "\350\276\223\345\205\245\346\202\250\347\232\204\346\230\265\347\247\260", nullptr));
        port->setPlaceholderText(QCoreApplication::translate("Authorisation", "\350\276\223\345\205\245\347\253\257\345\217\243", nullptr));
        ok->setText(QCoreApplication::translate("Authorisation", "OK", nullptr));
        label->setText(QCoreApplication::translate("Authorisation", "\347\253\257\345\217\243", nullptr));
        label_2->setText(QCoreApplication::translate("Authorisation", "\346\230\265\347\247\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Authorisation: public Ui_Authorisation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORISATION_H
