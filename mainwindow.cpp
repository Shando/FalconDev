#include "mainwindow.h"
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QPagedPaintDevice>
#include <QMessageBox>
#include <QProcess>
#include <QJsonDocument>
#include <QJsonObject>
#include <ui_mainwindow.h>
#include <ui_about.h>
#include <ui_help.h>
#include <settings.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_codeEditor(nullptr),
    m_completers(),
    m_highlighters(),
    m_styles()
{
    initData();

    ui->setupUi(this);

    updateSettings ( bRO, bWW, bAP, bTR, bAI, iSP );

    connect ( ui->actionNew, SIGNAL ( triggered ( ) ), this, SLOT ( fileNew ( ) ) );
    connect ( ui->actionLoad, SIGNAL ( triggered ( ) ), this, SLOT ( fileOpen ( ) ) );
    connect ( ui->actionSave, SIGNAL ( triggered ( ) ), this, SLOT ( fileSave ( ) ) );
    connect ( ui->actionSave_As, SIGNAL ( triggered ( ) ), this, SLOT ( fileSaveAs ( ) ) );
    connect ( ui->actionQuit, SIGNAL ( triggered ( ) ), this, SLOT ( fileQuit ( ) ) );
    connect ( ui->actionPrint, SIGNAL ( triggered ( ) ), this, SLOT ( filePrint ( ) ) );
    connect ( ui->actionClose, SIGNAL ( triggered ( ) ), this, SLOT ( fileClose ( ) ) );
    connect ( ui->actionRun, SIGNAL ( triggered ( ) ), this, SLOT ( runRun ( ) ) );
    connect ( ui->actionDebug, SIGNAL ( triggered ( ) ), this, SLOT ( runDebug ( ) ) );
    connect ( ui->actionStep, SIGNAL ( triggered ( ) ), this, SLOT ( runStep ( ) ) );
    connect ( ui->actionOCL, SIGNAL ( triggered ( ) ), this, SLOT ( runOpenOCL ( ) ) );
    connect ( ui->actionCrystal_Hammer, SIGNAL ( triggered ( ) ), this, SLOT ( styleCrystalHammer ( ) ) );
    connect ( ui->actionDark_Code, SIGNAL ( triggered ( ) ), this, SLOT ( styleDarkCode ( ) ) );
    connect ( ui->actionNormal, SIGNAL ( triggered ( ) ), this, SLOT ( styleNormal ( ) ) );
    connect ( ui->actionDracula, SIGNAL ( triggered ( ) ), this, SLOT ( styleDracula ( ) ) );
    connect ( ui->actionMonokai, SIGNAL ( triggered ( ) ), this, SLOT ( styleMonokai ( ) ) );
    connect ( ui->actionSublime_Material, SIGNAL ( triggered ( ) ), this, SLOT ( styleSublime ( ) ) );
    connect ( ui->actionSublime_Material_Light, SIGNAL ( triggered ( ) ), this, SLOT ( styleSublimeLight ( ) ) );
    connect ( ui->actionTomorrow, SIGNAL ( triggered ( ) ), this, SLOT ( styleTomorrow ( ) ) );
    connect ( ui->actionTomorrow_Night, SIGNAL ( triggered ( ) ), this, SLOT ( styleTomorrowNight ( ) ) );
    connect ( ui->actionTomorrow_Night_Blue, SIGNAL ( triggered ( ) ), this, SLOT ( styleTomorrowNightBlue ( ) ) );
    connect ( ui->actionTomorrow_Night_Eighties, SIGNAL ( triggered ( ) ), this, SLOT ( styleTomorrowNightEighties ( ) ) );
    connect ( ui->actionVS2012, SIGNAL ( triggered ( ) ), this, SLOT ( styleVS2012 ( ) ) );
    connect ( ui->actionSave_Default, SIGNAL ( triggered ( ) ), this, SLOT ( setDefault ( ) ) );
    connect ( ui->actionHelp, SIGNAL ( triggered ( ) ), this, SLOT ( helpHelp ( ) ) );
    connect ( ui->actionAbout, SIGNAL ( triggered ( ) ), this, SLOT ( helpAbout ( ) ) );
    connect ( ui->actionSettings, SIGNAL ( triggered ( ) ), this, SLOT ( settingsSettings ( ) ) );

    ui->actionCopy->setEnabled ( false );
    ui->actionCut->setEnabled ( false );
    connect ( ui->plainTextEdit, SIGNAL ( copyAvailable ( bool ) ), ui->actionCopy, SLOT ( setEnabled ( bool ) ) );
    connect ( ui->plainTextEdit, SIGNAL ( copyAvailable ( bool ) ), ui->actionCut, SLOT ( setEnabled ( bool ) ) );

    ui->actionRedo->setEnabled ( false );
    ui->actionUndo->setEnabled ( false );
    connect ( ui->plainTextEdit, SIGNAL ( redoAvailable ( bool ) ), ui->actionRedo, SLOT ( setEnabled ( bool ) ) );
    connect ( ui->plainTextEdit, SIGNAL ( redoAvailable ( bool ) ), ui->actionUndo, SLOT ( setEnabled ( bool ) ) );

    ui->plainTextEdit->setPlainText (loadCode(":/files/resources/code_samples/Blank.fal"));
    ui->plainTextEdit->setSyntaxStyle (m_styles[1].second);
    ui->plainTextEdit->setCompleter (m_completers[0].second);
    ui->plainTextEdit->setHighlighter (m_highlighters[0].second);

    connect ( ui->plainTextEdit, SIGNAL ( textChanged ( ) ), this, SLOT ( txtChanged ( ) ) );

    curFileName = "";
    curPath = "";
    fileModified = false;
    firstRun = true;
    curStyle = defStyle;
    ui->plainTextEdit->setSyntaxStyle (m_styles[curStyle].second);
    ui->statusbar->showMessage("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initData()
{
    m_completers = { {"FAL", new QFALCompleter} };
    m_highlighters = { {"FAL", new QFALHighlighter} };
    m_styles = {
        {"Default", QSyntaxStyle::defaultStyle()}
    };

    // Loading styles
    loadStyle(":/files/resources/styles/default_style.xml");
    loadStyle(":/files/resources/styles/drakula.xml");
    loadStyle(":/files/resources/styles/crystal_hammer.xml");
    loadStyle(":/files/resources/styles/dark_code.xml");
    loadStyle(":/files/resources/styles/monokai.xml");
    loadStyle(":/files/resources/styles/SublimeMaterial.xml");
    loadStyle(":/files/resources/styles/SublimeMaterialLight.xml");
    loadStyle(":/files/resources/styles/Tomorrow.xml");
    loadStyle(":/files/resources/styles/Tomorrow-Night.xml");
    loadStyle(":/files/resources/styles/Tomorrow-Night-Blue.xml");
    loadStyle(":/files/resources/styles/Tomorrow-Night-Eighties.xml");
    loadStyle(":/files/resources/styles/VS2012.xml");

    readJSON ( );
}

QString MainWindow::loadCode(QString path)
{
    QFile fl(path);

    if (!fl.open(QIODevice::ReadOnly))
    {
        return QString();
    }

    return fl.readAll();
}

void MainWindow::loadStyle(QString path)
{
    QFile fl(path);

    if (!fl.open(QIODevice::ReadOnly))
    {
        return;
    }

    auto style = new QSyntaxStyle;

    if (!style->load(fl.readAll()))
    {
        delete style;
        return;
    }

    m_styles.append({style->name(), style});
}

void MainWindow::fileNew ( )
{
    int iret = msgDlg ( );

    switch (iret) {
      case QMessageBox::Save:
          fileSave ( );
          curFileName = "";
          curPath = "";
          fileModified = false;
          ui->plainTextEdit->clear ( );
          ui->plainTextEdit->setPlainText (loadCode(":/files/resources/code_samples/Blank.fal"));
          ui->plainTextEdit->setSyntaxStyle (m_styles[curStyle].second);
          ui->statusbar->showMessage("");
          break;
      case QMessageBox::Discard:
          curFileName = "";
          curPath = "";
          fileModified = false;
          ui->plainTextEdit->clear ( );
          ui->plainTextEdit->setPlainText (loadCode(":/files/resources/code_samples/Blank.fal"));
          ui->statusbar->showMessage("");
          break;
      case QMessageBox::Cancel:
          // Don't do anything
          break;
      default:
          // should never be reached
          break;
    }
 }

void MainWindow::fileOpen ( )
{
    int iret = msgDlg ( );

    switch (iret) {
      case QMessageBox::Save:
          fileSave ( );
          curFileName = "";
          curPath = "";
          fileModified = false;

          fileName = QFileDialog::getOpenFileName(this,
               tr("Open File"),
               "",
               tr("Falcon (*.fal)"));

          curFileName = QFileInfo(fileName).fileName();
          curPath = QFileInfo(fileName).filePath();

          if ( curFileName != "" ) {
              fileModified = false;
              ui->plainTextEdit->setPlainText (loadCode(fileName));
              ui->statusbar->showMessage(curPath);
          }
          break;
      case QMessageBox::Discard:
          curFileName = "";
          curPath = "";
          fileModified = false;

          fileName = QFileDialog::getOpenFileName(this,
               tr("Open File"),
               "",
               tr("Falcon (*.fal)"));

          curFileName = QFileInfo(fileName).fileName();
          curPath = QFileInfo(fileName).filePath();

          if ( curFileName != "" ) {
              fileModified = false;
              ui->plainTextEdit->setPlainText (loadCode(fileName));
              ui->statusbar->showMessage(curPath);
          }
          break;
      case QMessageBox::Cancel:
          // Don't do anything
          break;
      default:
          // should never be reached
          break;
    }
}

void MainWindow::fileSave ( )
{
    if ( curFileName == "" ) {
        fileSaveAs ( );
    } else {
        if ( saveFile ( ) == 0) {
            fileModified = false;
        }
    }
}

void MainWindow::fileSaveAs ( )
{
    fileName = QFileDialog::getSaveFileName(this,
         tr("Save File As"),
         "",
         tr("Falcon (*.fal)"));

    curFileName = QFileInfo(fileName).fileName();
    curPath = QFileInfo(fileName).filePath();

    if ( curFileName != "" ) {
        if ( saveFile ( ) == 0 ){
            fileModified = false;
            ui->statusbar->showMessage(curPath);
        }
    }
}

void MainWindow::filePrint ( )
{
    QPrinter printer(QPrinter::HighResolution);
    ui->plainTextEdit->print( &printer );
}

void MainWindow::fileClose ( )
{
    int iret = msgDlg ( );

    switch (iret) {
      case QMessageBox::Save:
          fileSave ( );
          fileNew ( );
          break;
      case QMessageBox::Discard:
          fileNew( );
          break;
      case QMessageBox::Cancel:
          // Don't do anything
          break;
      default:
          // should never be reached
          break;
    }
}

void MainWindow::fileQuit ( )
{
    int iret = msgDlg ( );

    switch (iret) {
      case QMessageBox::Save:
          fileSave ( );
          QCoreApplication::quit ( );
          break;
      case QMessageBox::Discard:
          QCoreApplication::quit ( );
          break;
      case QMessageBox::Cancel:
          // Don't do anything
          break;
      default:
          // should never be reached
          break;
    }
}

void MainWindow::editUndo ( )
{
    ui->plainTextEdit->undo ( );
}

void MainWindow::editRedo ( )
{
    ui->plainTextEdit->redo ( );
}

void MainWindow::editCut ( )
{
    ui->plainTextEdit->cut ( );
}

void MainWindow::editCopy ( )
{
    ui->plainTextEdit->copy ( );
}

void MainWindow::editPaste ( )
{
    if ( ui->plainTextEdit->canPaste ( ) ) {
        ui->plainTextEdit->paste ( );
    }
}

void MainWindow::editSelectAll ( )
{
    ui->plainTextEdit->selectAll ( );
}

void MainWindow::runRun ( )
{
    QString tStr;
    int iTemp = 0;
    tStr = "cmd /k";

    if ( curFileName == "" ) {
        curFileName = "temp.fal";
        curPath = QDir::currentPath() +"/" + curFileName;
        iTemp = saveFile ( );
    }

    if ( iTemp == 0 ) {
        tStr = tStr + " \"" + curPath + "\"";
        QByteArray ba = tStr.toLatin1();
        const char *c_str2 = ba.data();

        system(c_str2);
    }

    if ( curFileName == "temp.fal" ) {
        curFileName = "";
        curPath = "";
    }
}

void MainWindow::runDebug ( )
{
    // TODO: implement
}

void MainWindow::runStep ( )
{
    // TODO: implement
}

void MainWindow::styleCrystalHammer ( )
{
    curStyle = 3;
    ui->plainTextEdit->setSyntaxStyle ( m_styles[curStyle].second);
}

void MainWindow::styleDarkCode ( )
{
    curStyle = 4;
    ui->plainTextEdit->setSyntaxStyle ( m_styles[curStyle].second);
}

void MainWindow::styleNormal ( )
{
    curStyle = 1;
    ui->plainTextEdit->setSyntaxStyle ( m_styles[curStyle].second);
}

void MainWindow::styleDracula ( )
{
    curStyle = 2;
    ui->plainTextEdit->setSyntaxStyle ( m_styles[curStyle].second);
}

void MainWindow::styleMonokai ( )
{
    curStyle = 5;
    ui->plainTextEdit->setSyntaxStyle ( m_styles[curStyle].second);
}

void MainWindow::styleSublime ( )
{
    curStyle = 6;
    ui->plainTextEdit->setSyntaxStyle ( m_styles[curStyle].second);
}

void MainWindow::styleSublimeLight ( )
{
    curStyle = 7;
    ui->plainTextEdit->setSyntaxStyle ( m_styles[curStyle].second);
}

void MainWindow::styleTomorrow ( )
{
    curStyle = 8;
    ui->plainTextEdit->setSyntaxStyle ( m_styles[curStyle].second);
}

void MainWindow::styleTomorrowNight ( )
{
    curStyle = 9;
    ui->plainTextEdit->setSyntaxStyle ( m_styles[curStyle].second);
}

void MainWindow::styleTomorrowNightBlue ( )
{
    curStyle = 10;
    ui->plainTextEdit->setSyntaxStyle ( m_styles[curStyle].second);
}

void MainWindow::styleTomorrowNightEighties ( )
{
    curStyle = 11;
    ui->plainTextEdit->setSyntaxStyle ( m_styles[curStyle].second);
}

void MainWindow::styleVS2012 ( )
{
    curStyle = 12;
    ui->plainTextEdit->setSyntaxStyle ( m_styles[curStyle].second);
}

void MainWindow::setDefault ( )
{
    defStyle = curStyle;
    writeJSON ( );
}


void MainWindow::txtChanged ( )
{
    if ( firstRun ) {
        firstRun = false;
    } else {
        fileModified = true;
    }
}

int MainWindow::msgDlg ( )
{
    QMessageBox msgBox;
    int ret = QMessageBox::Discard;

    if ( fileModified ) {
        msgBox.setText ( "The document has been modified." );
        msgBox.setInformativeText ( "Do you want to save your changes?" );
        msgBox.setStandardButtons ( QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel );
        msgBox.setDefaultButton ( QMessageBox::Save );

        ret = msgBox.exec ( );
    } else {
        firstRun = true;
    }

    return ret;
}

void MainWindow::runOpenOCL ( ) {
    system("cmd /k");
}

int MainWindow::saveFile ( ) {
    QFile file(curPath);

    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << ui->plainTextEdit->toPlainText();
        file.flush();
        file.close();
    } else {
        QMessageBox::warning(this, tr("Warning"), tr("File not saved!"));
        return 1;
    }

    return 0;
}

void MainWindow::settingsSettings ( )
{
//    SettingsDialog *settDlg = new SettingsDialog ( );
//    Ui_Settings settUi;
//    settUi.setupUi ( settDlg );
    SettingsDialog *settDlg = new SettingsDialog ( );

    QObject::connect ( settDlg, SIGNAL ( sendValues ( bool, bool, bool, bool, bool, int ) ), this, SLOT ( updateSettings ( bool, bool, bool, bool, bool, int ) ) );

    settDlg->bRO = bRO;
    settDlg->bWW = bWW;
    settDlg->bAP = bAP;
    settDlg->bTR = bTR;
    settDlg->bAI = bAI;
    settDlg->iSP = iSP;

    settDlg->initialise ( );
    settDlg->exec ( );
}

void MainWindow::helpHelp ( )
{
    QDialog *help = new QDialog ( nullptr, nullptr );

    Ui_Help helpUi;
    helpUi.setupUi ( help );

    help->show ( );
}

void MainWindow::helpAbout ( )
{
    QDialog *about = new QDialog ( nullptr, nullptr );

    Ui_About aboutUi;
    aboutUi.setupUi ( about );

    about->exec ( );
}

void MainWindow::updateSettings ( bool bRO1, bool bWW1, bool bAP1, bool bTR1, bool bAI1, int iSP1  )
{
    bRO = bRO1;
    bWW = bWW1;
    bAP = bAP1;
    bTR = bTR1;
    bAI = bAI1;
    iSP = iSP1;

    if ( bRO )
    {
        ui->plainTextEdit->setReadOnly ( true );
        QWidget::setWindowTitle ( "Falcon Development Environment (*** READ ONLY ***)" );
    } else {
        ui->plainTextEdit->setReadOnly ( false );
        QWidget::setWindowTitle ( "Falcon Development Environment" );
    }

    if ( bWW )
    {
        ui->plainTextEdit->setWordWrapMode ( QTextOption::WordWrap );
    } else {
        ui->plainTextEdit->setWordWrapMode ( QTextOption::NoWrap );
    }

    if ( bAP )
    {
        ui->plainTextEdit->setAutoParentheses ( true );
    } else {
        ui->plainTextEdit->setAutoParentheses ( false );
    }

    if ( bTR )
    {
        ui->plainTextEdit->setTabReplace ( true );
    } else {
        ui->plainTextEdit->setTabReplace ( false );
    }

    if ( bAI )
    {
        ui->plainTextEdit->setAutoIndentation ( true );
    } else {
        ui->plainTextEdit->setAutoIndentation ( false );
    }

    ui->plainTextEdit->setTabReplaceSize ( iSP );

    writeJSON ( );
}

void MainWindow::readJSON ( )
{
    QString val;
    QFile file;

    QString dir = QDir::currentPath ( );
    dir = dir + "/settings.json";
    file.setFileName ( dir );
    file.open ( QIODevice::ReadOnly | QIODevice::Text );
    val = file.readAll ( );
    file.close ( );

    QJsonDocument d = QJsonDocument::fromJson ( val.toUtf8 ( ) );
    QJsonObject temp = d.object ( );
    QJsonValue value = temp.value ( QString ( "ro" ) );
    bRO = value.toBool();
    value = temp.value ( QString ( "ww" ) );
    bWW = value.toBool();
    value = temp.value ( QString ( "ap" ) );
    bAP = value.toBool();
    value = temp.value ( QString ( "tr" ) );
    bTR = value.toBool();
    value = temp.value ( QString ( "ai" ) );
    bAI = value.toBool();
    value = temp.value ( QString ( "ts" ) );
    iSP = value.toInt ( );
    value = temp.value ( QString ( "ds" ) );
    defStyle = value.toInt ( );
}

void MainWindow::writeJSON ( )
{
    QJsonObject obj;

    obj["ds"] = defStyle;
    obj["ro"] = bRO;
    obj["ww"] = bWW;
    obj["ap"] = bAP;
    obj["tr"] = bTR;
    obj["ai"] = bAI;
    obj["ts"] = iSP;

    QString dir = QDir::currentPath ( );
    dir = dir + "/settings.json";
    QFile file ( dir );
    file.open ( QFile::WriteOnly );
    file.write ( QJsonDocument ( obj ).toJson ( ) );
    file.close ( );
}
