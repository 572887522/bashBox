#include "unitbox.h"

UnitBox::UnitBox(QWidget *parent)
    : QLabel{parent}
{
    filePath = "";
    qDebug() << "create unitBox";
}
UnitBox::UnitBox(QString str)
    : QLabel{str}
{}


void UnitBox::enterEvent(QEnterEvent *event)
{
    qDebug() << "unitBox enter Event";
}

void UnitBox::mouseDoubleClickEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
        qDebug() << "left mouse double release";
    else
        qDebug() << "right mouse double release";

    if(filePath.isEmpty())
    {
        qDebug() << "no link to open program";
        return;
    }
    qDebug() << filePath;

    openUrl(filePath);
}

void UnitBox::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
        qDebug() << "left mouse release";
    else
        qDebug() << "right mouse release";

    qDebug() << filePath;
}

void UnitBox::openUrl(QString filePath)
{
    if(filePath.isEmpty())
        qDebug() << "filePath is empty, do nothing";
    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));

}

void UnitBox::resetPixMap(QPixmap &unitIcon)
{
    QPixmap nullPixMap;
    unitIcon.swap(nullPixMap);
}
