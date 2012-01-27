#ifndef CUSTOMSQLMODEL_H
#define CUSTOMSQLMODEL_H

#include <QSqlQueryModel>
#include <QIcon>
class CustomSqlModel : public QSqlQueryModel
{
    Q_OBJECT
public:
    explicit CustomSqlModel(QObject *parent = 0);

    QVariant data(const QModelIndex &item = QModelIndex(), int role = Qt::DisplayRole) const;

    void setIcon(const QIcon& icon){mIcon = icon;}
    
signals:
    
public slots:

private:
    QIcon mIcon;
    
};

#endif // CUSTOMSQLMODEL_H
