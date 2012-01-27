#ifndef SPEDIALOG_H
#define SPEDIALOG_H

#include <QDialog>
#include <QtSql>
namespace Ui {
class SpeDialog;
}

class SpeDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SpeDialog(const QString& cis,QWidget *parent = 0);
    ~SpeDialog();
    
private:
    Ui::SpeDialog *ui;
    QSqlQueryModel * mModel;
};

#endif // SPEDIALOG_H
