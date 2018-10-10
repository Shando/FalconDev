/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QPushButton *btnAccept;
    QPushButton *btnClose;
    QCheckBox *chkReadOnly;
    QCheckBox *chkAutoParenth;
    QCheckBox *chkAutoIndent;
    QCheckBox *chkTabReplace;
    QCheckBox *chkWordWrap;
    QSpinBox *spnSpaces;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->setWindowModality(Qt::ApplicationModal);
        Settings->resize(346, 264);
        Settings->setModal(true);
        btnAccept = new QPushButton(Settings);
        btnAccept->setObjectName(QString::fromUtf8("btnAccept"));
        btnAccept->setGeometry(QRect(90, 200, 75, 41));
        btnClose = new QPushButton(Settings);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(180, 200, 75, 41));
        chkReadOnly = new QCheckBox(Settings);
        chkReadOnly->setObjectName(QString::fromUtf8("chkReadOnly"));
        chkReadOnly->setGeometry(QRect(131, 46, 73, 17));
        chkAutoParenth = new QCheckBox(Settings);
        chkAutoParenth->setObjectName(QString::fromUtf8("chkAutoParenth"));
        chkAutoParenth->setGeometry(QRect(131, 165, 109, 17));
        chkAutoParenth->setChecked(true);
        chkAutoIndent = new QCheckBox(Settings);
        chkAutoIndent->setObjectName(QString::fromUtf8("chkAutoIndent"));
        chkAutoIndent->setGeometry(QRect(131, 75, 105, 17));
        chkAutoIndent->setChecked(true);
        chkTabReplace = new QCheckBox(Settings);
        chkTabReplace->setObjectName(QString::fromUtf8("chkTabReplace"));
        chkTabReplace->setGeometry(QRect(131, 104, 82, 17));
        chkTabReplace->setChecked(true);
        chkWordWrap = new QCheckBox(Settings);
        chkWordWrap->setObjectName(QString::fromUtf8("chkWordWrap"));
        chkWordWrap->setGeometry(QRect(131, 17, 81, 17));
        chkWordWrap->setChecked(true);
        spnSpaces = new QSpinBox(Settings);
        spnSpaces->setObjectName(QString::fromUtf8("spnSpaces"));
        spnSpaces->setGeometry(QRect(131, 133, 37, 20));
        spnSpaces->setMinimum(1);
        spnSpaces->setMaximum(16);
        spnSpaces->setValue(4);

        retranslateUi(Settings);
        QObject::connect(btnClose, SIGNAL(clicked()), Settings, SLOT(close()));

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Change Settings", nullptr));
        btnAccept->setText(QApplication::translate("Settings", "Accept\n"
"Changes", nullptr));
        btnClose->setText(QApplication::translate("Settings", "Close", nullptr));
        chkReadOnly->setText(QApplication::translate("Settings", "Read Only", nullptr));
        chkAutoParenth->setText(QApplication::translate("Settings", "Auto Parentheses", nullptr));
        chkAutoIndent->setText(QApplication::translate("Settings", "Auto Indentation", nullptr));
        chkTabReplace->setText(QApplication::translate("Settings", "Tab Replace", nullptr));
        chkWordWrap->setText(QApplication::translate("Settings", "Word Wrap", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
