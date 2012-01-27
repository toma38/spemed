#ifndef DETAILDIALOG_H
#define DETAILDIALOG_H

#include <QDialog>
#include <QtSql>
namespace Ui {
class DetailDialog;
}

class DetailDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DetailDialog(const QString& cis, QWidget *parent = 0);
    ~DetailDialog();
    
private:
    Ui::DetailDialog *ui;

};

#endif // DETAILDIALOG_H
