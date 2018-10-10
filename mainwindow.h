#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QPair>
#include <QAction>
#include <QMenu>
#include <QTextStream>

#include "include/include/internal/QCodeEditor.hpp"
#include "include/include/internal/QFALCompleter.hpp"
#include "include/include/internal/QFALHighlighter.hpp"
#include "include/include/internal/QFramedTextAttribute.hpp"
#include "include/include/internal/QHighlightRule.hpp"
#include "include/include/internal/QLanguage.hpp"
#include "include/include/internal/QLineNumberArea.hpp"
#include "include/include/internal/QStyleSyntaxHighlighter.hpp"
#include "include/include/internal/QSyntaxStyle.hpp"

#include <settings.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString fileName;
    QString curFileName;
    QString curPath;
    bool fileModified;
    bool firstRun;

    bool bRO;
    bool bWW;
    bool bAP;
    bool bTR;
    bool bAI;
    int iSP;

    SettingsDialog* settDlg;
    int msgDlg ( );
    void readJSON ( );
    void writeJSON ( );

    QCodeEditor* m_codeEditor;

public slots:
    void fileNew ( );
    void fileOpen ( );
    void fileSave ( );
    void fileSaveAs ( );
    void filePrint ( );
    void fileClose ( );
    void fileQuit ( );
    void editUndo ( );
    void editRedo ( );
    void editCut ( );
    void editCopy ( );
    void editPaste ( );
    void editSelectAll ( );
    void runRun ( );
    void runDebug ( );
    void runStep ( );
    void styleCrystalHammer ( );
    void styleDarkCode ( );
    void styleNormal ( );
    void styleDracula ( );
    void styleMonokai ( );
    void styleSublime ( );
    void styleSublimeLight ( );
    void styleTomorrow ( );
    void styleTomorrowNight ( );
    void styleTomorrowNightBlue ( );
    void styleTomorrowNightEighties ( );
    void styleVS2012 ( );
    void setDefault ( );
    void txtChanged ( );
    void runOpenOCL ( );
    void settingsSettings ( );
    void helpHelp ( );
    void helpAbout ( );
    void updateSettings ( bool bRO, bool bWW, bool bAP, bool bTR, bool bAI, int iSP );

private:
    Ui::MainWindow *ui;
    Ui::Settings *settings;
    void loadStyle(QString path);
    QString loadCode(QString path);
    void initData();
    int saveFile();
    int curStyle;
    int defStyle;

    QVector<QPair<QString, QString>> m_codeSamples;
    QVector<QPair<QString, QCompleter*>> m_completers;
    QVector<QPair<QString, QStyleSyntaxHighlighter*>> m_highlighters;
    QVector<QPair<QString, QSyntaxStyle*>> m_styles;
};

#endif // MAINWINDOW_H
