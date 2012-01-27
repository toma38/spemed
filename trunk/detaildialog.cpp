#include "detaildialog.h"
#include "ui_detaildialog.h"
#include <QDebug>

DetailDialog::DetailDialog(const QString& cis,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailDialog)
{
    ui->setupUi(this);


    QSqlQuery query("select "
                    "CIS.denomination,"
                    "COMPO.dci,"
                    "CIS.forme,"
                    "CIS.administration,"
                    "CIS.AMM,"
                    "CIS.status,"
                    "COMPO.forme,"
                    "COMPO.dosage,"
                    "COMPO.nature "
                    "FROM CIS, COMPO where CIS.cis = " +cis+" AND COMPO.cis = " + cis);
    query.seek(0);


    qDebug()<<query.lastQuery();
    qDebug()<<query.lastError().text();


    for ( int i=0; i<query.record().count(); ++i)
        ui->listWidget->addItem(query.record().value(i).toString());



setWindowTitle(ui->listWidget->item(0)->text());





}

DetailDialog::~DetailDialog()
{
    delete ui;

}
