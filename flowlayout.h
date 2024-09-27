#ifndef FLOWLAYOUT_H
#define FLOWLAYOUT_H

#include <QLayout>

class flowLayout : public QLayout
{
public:
    explicit flowLayout(QWidget *parent = nullptr);

    void setGeometry(const QRect &rect) override;
    void doLayout(const QRect &rect) const;

    void addItem(QLayoutItem *item) override;
    QLayoutItem *itemAt(int index) const override;
    QLayoutItem *takeAt(int index) override;
    int count() const override;

    QSize sizeHint() const override;
    Qt::Orientations expandingDirections() const override;
signals:

private:
    QList<QLayoutItem *> itemList;
};

#endif // FLOWLAYOUT_H
