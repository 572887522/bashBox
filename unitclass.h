#ifndef UNITCLASS_H
#define UNITCLASS_H

#include <QWidget>
#include <QPushButton>

class unitclass : public QPushButton
{
    Q_OBJECT
public:
    explicit unitclass(QWidget *parent = nullptr);
    unitclass();

signals:
};

#endif // UNITCLASS_H
