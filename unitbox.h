#ifndef UNITBOX_H
#define UNITBOX_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QDropEvent>
#include <QDebug>
#include <QMouseEvent>

class UnitBox : public QPushButton
{
    Q_OBJECT
public:
    explicit UnitBox(QWidget *parent = nullptr);
    UnitBox(QString );

    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void enterEvent(QEnterEvent *);

signals:
};

#endif // UNITBOX_H
