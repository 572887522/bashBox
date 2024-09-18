#ifndef UNITBOX_H
#define UNITBOX_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QDropEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QMimeData>
#include <QDesktopServices>
#include <QFileInfo>
#include <QFileIconProvider>
#include <QPoint>

class UnitBox : public QLabel
{
    Q_OBJECT

private:
    QWidget *_bashBox;
    QString filePath;
    QPixmap unitIcon;
    QPoint dragStartPosition;


public:
    explicit UnitBox(QWidget *parent = nullptr);
    UnitBox(QWidget *parent, QWidget *bashBox);
    UnitBox(QString );

    QString getFilePath() {return filePath;}
    QPixmap getUnitIcon() {return unitIcon;}

    // event
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void enterEvent(QEnterEvent *);

    void mouseDoubleClickEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    bool getFilePathFromDrop(QDropEvent *event);
    bool getPIconFromPath();
    bool setIconToUnit();
    void openUrl(QString filePath);
    void resetPixMap(QPixmap &unitIcon);

signals:
};

#endif // UNITBOX_H
