#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QtSql>
#include <QSortFilterProxyModel>
#include "detaildialog.h"
#include "spedialog.h"
#include "customsqlmodel.h"
#include "afssapsdetailwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void setFilter(const QString& filter = QString());
    void showDetail();
    void showAbout();
    
private:
    Ui::MainWindow *ui;
    CustomSqlModel * mModel;
};

#endif // MAINWINDOW_H
