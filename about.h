#include <QDialog>
#include "ui_about.h"

class AboutDialog : public QDialog, public Ui::Dialog {
    Q_OBJECT

public:
    AboutDialog( QWidget * parent = 0);
};
