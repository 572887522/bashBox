#include "lattice.h"

Lattice::Lattice(QWidget *parent)
    : QWidget{parent}, bashBox_(parent)
{
    selfLabel = nullptr;
}

Lattice::~Lattice()
{
    if(selfLabel != nullptr)
    {
        delete selfLabel;
        selfLabel = nullptr;
    }
}


void Lattice::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    p.setPen(QColor("black")); //设置画笔记颜色
    p.drawRect(0, 0, width() -1, height() -1); //绘制边框
}

void Lattice::dragEnterEvent(QDragEnterEvent *event) {
    qDebug() << "enter dragEnterEvent of lattice";
    event->acceptProposedAction();
}

void Lattice::dropEvent(QDropEvent *event)
{
    if(selfLabel != nullptr)
    {
        qDebug() << "this lattice has unit";
        return;
    }
    selfLabel = new UnitBox(this,bashBox_);
    selfLabel->resize(50,50);
    selfLabel->show();
    selfLabel->raise();

    selfLabel->dropEvent(event);
}
