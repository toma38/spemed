#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStatusBar>
#include <QMessageBox>
#include <QFile>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mModel = new CustomSqlModel;
    ui->tableView->setModel(mModel);


    if ( !QFile::exists("afsaps.sqlite"))
        QMessageBox::critical(this,"erreur","le fichier afsaps.sqlite est manquant");


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("afsaps.sqlite");

    if (db.open())
        setFilter();

    else {
        QMessageBox * box = new QMessageBox(this);
        box->setText("Impossible d'ouvrir la base de donnée.");
        box->setDetailedText(db.lastError().text());
        box->exec();

    }



    ui->tableView->hideColumn(0);
    ui->tableView->hideColumn(2);

    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(setFilter(QString)));
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(showDetail()));
    connect(ui->actionA_propos,SIGNAL(triggered()),this,SLOT(showAbout()));
    connect(ui->actionA_propos_de_Qt4,SIGNAL(triggered()),qApp,SLOT(aboutQt()));


    statusBar()->showMessage("dernière mise à jour depuis afsaps : 28/01/2012");


}

MainWindow::~MainWindow()
{
    delete ui;
    delete mModel;
}

void MainWindow::setFilter(const QString &filter)
{


    mModel->setIcon(QIcon(":specialite.png"));

    if ( filter.isEmpty())
        mModel->setQuery("SELECT cis,denomination,code from CIS");

    mModel->setQuery("SELECT cis,denomination,code from CIS where denomination LIKE '%"+filter+"%'");


    qDebug()<<mModel->lastError().text();

}

void MainWindow::showDetail()
{

    QModelIndex index = ui->tableView->selectionModel()->selectedIndexes().first();

    QString id = mModel->data(mModel->index(index.row(),2)).toString();
    qDebug()<<"cis selected "<<id;


    if (id.isEmpty()){
        QMessageBox::information(this,"désolé..", "Aucune information disponnible pour cette spécialité");
        return;
    }

    AfssapsDetailWidget * widget = new AfssapsDetailWidget(id);
    widget->show();


    //        DetailDialog * dialog = new DetailDialog(id);
    //        dialog->exec();




}

void MainWindow::showAbout()
{


    QMessageBox::about(this,tr("A propos de spemed"),QApplication::applicationName()+" - "
                       +QApplication::organizationName()+"\n"
                       "version "+QApplication::applicationVersion()+"\n"
                       +QApplication::organizationDomain()+"\n"
                       "MaJ janvier 2012 - LICENCE GPL3\n"
                       "http://afssaps-prd.afssaps.fr");
}
