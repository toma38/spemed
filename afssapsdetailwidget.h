#ifndef AFSSAPSDETAILWIDGET_H
#define AFSSAPSDETAILWIDGET_H

#include <QWebView>

class AfssapsDetailWidget : public QWebView
{
    Q_OBJECT
public:
    explicit AfssapsDetailWidget(const QString& code, QWidget *parent = 0);

signals:

public slots:

};

#endif // AFSSAPSDETAILWIDGET_H
