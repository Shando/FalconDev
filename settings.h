#ifndef SETTINGS_H
#define SETTINGS_H

#include <ui_settings.h>

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog ( QDialog *parent = nullptr );
    void initialise ( );

    bool bRO;
    bool bWW;
    bool bAP;
    bool bTR;
    bool bAI;
    int iSP;

signals:
    void sendValues ( bool bRO, bool bWW, bool bAP, bool bTR, bool bAI, int iSP );

public slots:
    void updateValues ( );
    void closeDlg ( );

private:
    Ui::Settings ui;
    void changeEvent ( QEvent *e );
};

#endif // SETTINGS_H
