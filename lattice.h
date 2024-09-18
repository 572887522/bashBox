#ifndef LATTICE_H
#define LATTICE_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QPaintEvent>
#include "unitbox.h"

class Lattice : public QWidget
{
    Q_OBJECT
private:
    QWidget *bashBox_;
    UnitBox *selfLabel;
public:
    explicit Lattice(QWidget *parent = nullptr);
    ~Lattice();

    void paintEvent(QPaintEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;

signals:
};

#endif // LATTICE_H
