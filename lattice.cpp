#include "lattice.h"

Lattice::Lattice(QWidget *parent)
    : QWidget{parent}
{
    unitLabel = nullptr;
}

Lattice::~Lattice()
{
}

bool Lattice::findFilePathFromDrop(QDropEvent *event, QString &filePath)
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

bool Lattice::findIconFromPath(QString filePath, QPixmap &unitIcon)
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

bool Lattice::loadDataFromUserIcon(QDropEvent *event)
{
    if(unitLabel == nullptr)
    {
        qDebug() << "no unit label when load data from icon";
        return false;
    }

    QString path;
    QPixmap pixmap;
    if(findFilePathFromDrop(event, path) == false)
    {
        qDebug() << "error: get file path failed!";
    }
    else if(findIconFromPath(path, pixmap) == false)
    {
        qDebug() << "error: set icon to unit failed!";
    }
    else
    {
        qDebug() << "load data from icon success!";
        unitLabel->setFilePath(path);
        unitLabel->setUnitIcon(pixmap);
        return true;
    }

    return false;
}


void Lattice::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setPen(QColor("black")); //设置画笔记颜色
    p.drawRect(0, 0, width() -1, height() -1); //绘制边框
}

void Lattice::dragEnterEvent(QDragEnterEvent *event) {
    qDebug() << "enter dragEnterEvent of lattice";
    if(unitLabel != nullptr)
    {
        qDebug() << "this lattic has label, ignore this drop action";
        event->ignore();
        return;
    }
    event->acceptProposedAction();
}

void Lattice::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata"))
    {
        qDebug() << "get data from drag in dropEvent";
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QString filePath;
        dataStream >> pixmap >> filePath;

        unitLabel = new UnitBox(this);
        unitLabel->setFilePath(filePath);
        unitLabel->setUnitIcon(pixmap);
        unitLabel->setAttribute(Qt::WA_DeleteOnClose);
        unitLabel->show();
    }
    else
    {
        qDebug() << "get data from userIcon in dropEvent";
        unitLabel = new UnitBox(this);
        loadDataFromUserIcon(event);
        unitLabel->setAttribute(Qt::WA_DeleteOnClose);
        unitLabel->show();
    }

    event->acceptProposedAction();

}

void Lattice::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "mouse Press";

    QLabel *child = static_cast<QLabel*>(childAt(event->position().toPoint()));
    if (!child)
        return;

    QDrag *drag = new QDrag(this);

    QByteArray itemData;
    QPixmap pixmap = unitLabel->getUnitIcon();
    QString filePath = unitLabel->getFilePath();
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << filePath;

    QMimeData *mimeData = new QMimeData();
    mimeData->setData("application/x-dnditemdata", itemData);

    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->position().toPoint() - child->pos());

    if(drag->exec(Qt::MoveAction, Qt::MoveAction) == Qt::MoveAction)
    {
        unitLabel->close();
        unitLabel = nullptr;

    }
}
