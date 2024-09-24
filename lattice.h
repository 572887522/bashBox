#ifndef LATTICE_H
#define LATTICE_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include <QPaintEvent>
#include <QFileInfo>
#include <QFileIconProvider>
#include "unitbox.h"

class Lattice : public QWidget
{
    Q_OBJECT

private:
    UnitBox *unitLabel;
public:
    explicit Lattice(QWidget *parent = nullptr);
    ~Lattice();


private:
    bool findFilePathFromDrop(QDropEvent *event, QString &filePath);
    bool findIconFromPath(QString filePath, QPixmap &unitIcon);
    bool loadDataFromUserIcon(QDropEvent *event);

public:
    void paintEvent(QPaintEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

signals:
};

#endif // LATTICE_H
