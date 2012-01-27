#include "spedialog.h"
#include "ui_spedialog.h"

SpeDialog::SpeDialog(const QString &cis, QWidget *parent):
    QDialog(parent),
    ui(new Ui::SpeDialog)
{
    ui->setupUi(this);


    mModel = new QSqlQueryModel;
    ui->listView->setModel(mModel);

    mModel->setQuery("select denomination from CIS where cis = "+cis);

}

SpeDialog::~SpeDialog()
{
    delete ui;
}
