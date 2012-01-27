#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStatusBar>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mModel = new CustomSqlModel;
    ui->tableView->setModel(mModel);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("afsaps.sqlite");

    if (db.open())
        setFilter();


    ui->tableView->hideColumn(0);

    connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(setFilter(QString)));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(setFilter()));
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(showDetail()));
    connect(ui->actionA_propos,SIGNAL(triggered()),this,SLOT(showAbout()));
    connect(ui->actionA_propos_de_Qt4,SIGNAL(triggered()),qApp,SLOT(aboutQt()));


}

MainWindow::~MainWindow()
{
    delete ui;
    delete mModel;
}

void MainWindow::setFilter(const QString &filter)
{


    mModel->setIcon(QIcon(ui->comboBox->currentIndex() ? ":dci.png" : ":specialite.png"));

    if ( filter.isEmpty())
    {

        if (!ui->comboBox->currentIndex())
            mModel->setQuery("SELECT cis,denomination from CIS");
        else
            mModel->setQuery("SELECT cis,dci from COMPO");



    }

    if (!ui->comboBox->currentIndex())
        mModel->setQuery("SELECT cis,denomination from CIS where denomination LIKE '%"+filter+"%'");
    else
        mModel->setQuery("SELECT cis,dci from COMPO where dci LIKE '%"+filter+"%'");

    qDebug()<<mModel->lastError().text();




}

void MainWindow::showDetail()
{

    QModelIndex index = ui->tableView->selectionModel()->selectedIndexes().first();

    QString id = mModel->data(mModel->index(index.row(),0)).toString();
    qDebug()<<"cis selected "<<id;


        DetailDialog * dialog = new DetailDialog(id);
        dialog->exec();




}

void MainWindow::showAbout()
{


    QMessageBox::about(this,tr("A propos de spemed"),QApplication::applicationName()+" - "
                       +QApplication::organizationName()+"\n"
                       "version "+QApplication::applicationVersion()+"\n"
                       +QApplication::organizationDomain()+"\n"
                       "janvier 2012 - LICENCE GPL3\n"
                       "http://afssaps-prd.afssaps.fr");
}
