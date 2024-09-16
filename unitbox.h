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

class UnitBox : public QLabel
{
    Q_OBJECT

private:
    QString filePath;
    QPixmap unitIcon;


public:
    explicit UnitBox(QWidget *parent = nullptr);
    UnitBox(QString );

    // event
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void enterEvent(QEnterEvent *);
    void mousePressEvent();
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);

private:
    bool getFilePath(QDropEvent *event);
    bool getPIconFromPath();
    bool setIconToUnit();
    void openUrl(QString filePath);
    void resetPixMap(QPixmap &unitIcon);

signals:
};

#endif // UNITBOX_H
