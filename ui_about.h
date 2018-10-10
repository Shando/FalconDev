/********************************************************************************
** Form generated from reading UI file 'about.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUT_H
#define UI_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_About
{
public:
    QTextBrowser *textBrowser;
    QPushButton *aboutOK;

    void setupUi(QDialog *About)
    {
        if (About->objectName().isEmpty())
            About->setObjectName(QString::fromUtf8("About"));
        About->setWindowModality(Qt::ApplicationModal);
        About->resize(471, 329);
        About->setModal(true);
        textBrowser = new QTextBrowser(About);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 451, 271));
        aboutOK = new QPushButton(About);
        aboutOK->setObjectName(QString::fromUtf8("aboutOK"));
        aboutOK->setGeometry(QRect(200, 290, 75, 31));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        aboutOK->setFont(font);

        retranslateUi(About);
        QObject::connect(aboutOK, SIGNAL(clicked()), About, SLOT(close()));

        QMetaObject::connectSlotsByName(About);
    } // setupUi

    void retranslateUi(QDialog *About)
    {
        About->setWindowTitle(QApplication::translate("About", "About Falcon Development Environment", nullptr));
        textBrowser->setHtml(QApplication::translate("About", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This Development Environment is brought to you by SpinalSoft (AU) and is (C) SpinalSoft (AU) 2018.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">It is built using the community version of Qt (<a href=\"https://www.qt.io/\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">https://www.qt.io/"
                        "</span></a>) and is released under the same licence (MIT) as QCodeEditor (see README.md file).</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">QCodeEditor is by Megaxela (<a href=\"https://github.com/Megaxela/QCodeEditor\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">https://github.com/Megaxela/QCodeEditor</span></a>)</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt; text-decoration: underline; color:#0000ff;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">The various themes are :</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margi"
                        "n-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Crystal Hammer (<a href=\"\n"
"\n"
"https://cryham.tuxfamily.org/themes#Qt_Creator\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">https://cryham.tuxfamily.org/themes#Qt_Creator</span></a>)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Dark Code (<a href=\"http://gitlab.unique-conception.org/qt-tools/qtcreator-dark-code-style/blob/master/dark_code.xml\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">http://gitlab.unique-conception.org/qt-tools/qtcreator-dark-code-style/blob/master/dark_code.xml</span></a>)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Dracula (<a href=\"https://draculatheme.com\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">https://draculatheme.com</span></a>)</p>\n"
"<p style="
                        "\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Eclipse (<a href=\"http://www.eclipsecolorthemes.org/?view=theme&amp;id=3741\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">http://www.eclipsecolorthemes.org/?view=theme&amp;id=3741</span></a>)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Monokai (<a href=\"https://github.com/bfrg/qtcreator-monokai\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">https://github.com/bfrg/qtcreator-monokai</span></a>)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Sublime Material (<a href=\"https://www.buymeacoffee.com/foxoman\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">https://www.buymeacoffee.com/foxoman</span></a>)</p>\n"
"<p style=\" margin-top:0px; margin-botto"
                        "m:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Tomorrow Theme (<a href=\"https://github.com/chriskempson/tomorrow-theme\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">https://github.com/chriskempson/tomorrow-theme</span></a>)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">VS2012 (<a href=\"https://blog.benjaminhuang.me/2013/02/14/qt-creator-color-scheme-msvs2012-style/\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">https://blog.benjaminhuang.me/2013/02/14/qt-creator-color-scheme-msvs2012-style/</span></a>)</p></body></html>", nullptr));
        aboutOK->setText(QApplication::translate("About", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class About: public Ui_About {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUT_H
