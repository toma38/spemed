#include "afssapsdetailwidget.h"

AfssapsDetailWidget::AfssapsDetailWidget(const QString &code, QWidget *parent) :
    QWebView(parent)
{


    setUrl(QUrl("http://afssaps-prd.afssaps.fr/php/ecodex/rcp/R"+code+".htm"));

}
