#include "customsqlmodel.h"

CustomSqlModel::CustomSqlModel(QObject *parent) :
    QSqlQueryModel(parent)
{
}

QVariant CustomSqlModel::data(const QModelIndex &item, int role) const
{



    if ( role == Qt::TextColorRole){
        if (!record(item.row()).value(2).toString().isEmpty())
          return Qt::black;
        else return Qt::lightGray;


    }

    if ( role == Qt::DecorationRole)
        return mIcon;




    return QSqlQueryModel::data(item,role);
}
