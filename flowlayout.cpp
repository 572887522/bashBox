#include "flowlayout.h"
#include <QDebug>

#define SPACE 10

flowLayout::flowLayout(QWidget *parent)
    : QLayout{parent}
{}

void flowLayout::setGeometry(const QRect &rect)
{
    qDebug() << "geometry change";
    doLayout(rect);
}

void flowLayout::doLayout(const QRect &rect) const
{
    int left, top, right, bottom;
    getContentsMargins(&left, &top, &right, &bottom);

    QRect effectiveRect = rect.adjusted(+left, +top, -right, -bottom);
    int x = effectiveRect.x();
    int y = effectiveRect.y();
    int lineHigh = 0;

    for(QLayoutItem *item : itemList)
    {
        int rightBoundary = x + item->sizeHint().width() + SPACE;
        if(rightBoundary - SPACE > effectiveRect.right() && lineHigh > 0)
        {
            x = effectiveRect.x();
            y = y + lineHigh + SPACE;
            rightBoundary = x + item->sizeHint().width() + SPACE;
        }

        item->setGeometry(QRect(QPoint(x,y), item->sizeHint()));
        x = rightBoundary;
        lineHigh = qMax(lineHigh, item->sizeHint().height());
    }

}

void flowLayout::addItem(QLayoutItem *item)//add
{
    itemList.append(item);
}
QLayoutItem* flowLayout::itemAt(int index) const // search
{
    return itemList.value(index);
}
QLayoutItem* flowLayout::takeAt(int index) // remove
{
    if (index >= 0 && index < itemList.size())
        return itemList.takeAt(index);
    return nullptr;
}
int flowLayout::count() const
{
    return itemList.size();
}

QSize flowLayout::sizeHint() const
{
    return maximumSize();
}
Qt::Orientations flowLayout::expandingDirections() const
{
    return { };
}
