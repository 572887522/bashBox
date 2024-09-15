#include "unitbox.h"

UnitBox::UnitBox(QWidget *parent)
    : QPushButton{parent}
{}
UnitBox::UnitBox(QString str)
    : QPushButton{str}
{}


void UnitBox::dragEnterEvent(QDragEnterEvent *event) {
    qDebug() << "enter dragEnterEvent";
    event->acceptProposedAction();
}

void UnitBox::dropEvent(QDropEvent *event)
{
    qDebug() << "drop Event";
    event->acceptProposedAction();
}

void UnitBox::enterEvent(QEnterEvent *event)
{
    qDebug() << "enter Event";
}
