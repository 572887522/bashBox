#include "unitbox.h"

UnitBox::UnitBox(QWidget *parent)
    : QLabel{parent}
{
    filePath = "";
}
UnitBox::UnitBox(QString str)
    : QLabel{str}
{}


void UnitBox::dragEnterEvent(QDragEnterEvent *event) {
    qDebug() << "enter dragEnterEvent";
    event->acceptProposedAction();
}

void UnitBox::dropEvent(QDropEvent *event)
{
    if(filePath.isEmpty() == false && unitIcon.isNull() == false)
    {
        qDebug() << "unit have value, ignore this drop event";
        return;
    }

    qDebug() << "drop Event";
    event->acceptProposedAction();

    if(getFilePath(event) == false)
    {
        qDebug() << "error: get file path failed!";
    }
    else if(setIconToUnit() == false)
    {
        qDebug() << "error: set icon to unit failed!";
    }
    else
    {
        qDebug() << "success!";
    }
}

void UnitBox::enterEvent(QEnterEvent *event)
{
    qDebug() << "enter Event";
}

void UnitBox::mousePressEvent()
{
    qDebug() << "mouse Press";
}

void UnitBox::mouseReleaseEvent(QMouseEvent* event)
{
    if(event->button() == Qt::LeftButton)
        qDebug() << "left mouse release";
    else
        qDebug() << "right mouse release";

    qDebug() << filePath;
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




bool UnitBox::getFilePath(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if(urls.size() != 1)
    {
        qDebug() << "url number = " << urls.size() << " != 1, error!";
        return false;
    }

    for(QUrl url : urls)
        filePath = url.toLocalFile();

    return true;
}

bool UnitBox::getPIconFromPath()
{
    if(filePath.isEmpty())
    {
        qDebug() << "filePath is empty, error!";
        return false;
    }

    QFileInfo fileInfo(filePath);
    QFileIconProvider iconProvider;
    QIcon icon = iconProvider.icon(fileInfo);

    unitIcon = icon.pixmap(icon.actualSize(QSize(64, 64)));
    return true;
}

bool UnitBox::setIconToUnit()
{
    if(getPIconFromPath())
    {
        setPixmap(unitIcon);
        return true;
    }
    else
    {
        qDebug() << "read icon from filepath err!";
        return false;
    }
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
