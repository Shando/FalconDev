#include <settings.h>

SettingsDialog::SettingsDialog ( QDialog *parent )
    : QDialog ( parent )
{
    ui.setupUi ( this );

    connect ( ui.btnAccept, SIGNAL ( clicked ( ) ), this, SLOT ( updateValues ( ) ) );
    connect ( ui.btnClose, SIGNAL ( clicked ( ) ), this, SLOT ( closeDlg ( ) ) );
}


void SettingsDialog::initialise ( )
{
    if ( bRO ) {
        ui.chkReadOnly->setChecked( true );
    } else {
        ui.chkReadOnly->setChecked ( false );
    }

    if ( bWW ) {
        ui.chkWordWrap->setChecked( true );
    } else {
        ui.chkWordWrap->setChecked ( false );
    }

    if ( bAP ) {
        ui.chkAutoParenth->setChecked( true );
    } else {
        ui.chkAutoParenth->setChecked ( false );
    }

    if ( bTR ) {
        ui.chkTabReplace->setChecked( true );
    } else {
        ui.chkTabReplace->setChecked ( false );
    }

    if ( bAI ) {
        ui.chkAutoIndent->setChecked( true );
    } else {
        ui.chkAutoIndent->setChecked ( false );
    }

    ui.spnSpaces->setValue ( iSP );
}
void SettingsDialog::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);

    switch (e->type()) {
        case QEvent::LanguageChange:
            ui.retranslateUi(this);
            break;
        default:
            break;
   }
}

void SettingsDialog::closeDlg ( )
{
    this->close ( );
}

void SettingsDialog::updateValues ( )
{
    bRO = false;
    bWW = false;
    bAP = false;
    bTR = false;
    bAI = false;
    iSP = 1;

    if ( ui.chkReadOnly->checkState() == 2 )
    {
        bRO = true;
    }

    if ( ui.chkWordWrap->checkState() == 2 )
    {
        bWW = true;
    }

    if ( ui.chkAutoParenth->checkState() == 2 )
    {
        bAP = true;
    }

    if ( ui.chkTabReplace->checkState() == 2 )
    {
        bTR = true;
    }

    if ( ui.chkAutoIndent->checkState() == 2 )
    {
        bAI = true;
    }

    iSP = ui.spnSpaces->value ( );

    emit sendValues ( bRO, bWW, bAP, bTR, bAI, iSP );

    this->close ( );
}
