#ifndef UNITBOX_H
#define UNITBOX_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <QMouseEvent>
#include <QMimeData>
#include <QDesktopServices>
#include <QPoint>
#include <QDrag>

class UnitBox : public QLabel
{
    Q_OBJECT

private:
    QString filePath;
    QPixmap unitIcon;
    // QPoint dragStartPosition;


public:
    explicit UnitBox(QWidget *parent = nullptr);
    UnitBox(QString );

    void setFilePath(const QString &path) {filePath = path;}
    void setUnitIcon(const QPixmap &map) {unitIcon = map; setPixmap(unitIcon);}
    QString getFilePath() {return filePath;}
    QPixmap getUnitIcon() {return unitIcon;}

    // event
    void enterEvent(QEnterEvent *) override;

    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    void openUrl(QString filePath);
    void resetPixMap(QPixmap &unitIcon);

signals:
};

#endif // UNITBOX_H
