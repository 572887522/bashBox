#ifndef BASHBOX_H
#define BASHBOX_H

#include <QMainWindow>
#include <QLabel>
#include <QGridLayout>
#include <QVector>
#include <QString>
#include <QPushButton>
#include "unitbox.h"
#include "lattice.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class bashBox;
}
QT_END_NAMESPACE


using shortBox = Lattice;
#define MAXBOXNUMBER 20
#define TABWIDGETCOLUMN 5

class bashBox : public QMainWindow
{
    Q_OBJECT

private:
    Ui::bashBox *ui;
    QList<shortBox*> *shortBoxs;
    QGridLayout *glayout;

public:
    bashBox(QWidget *parent = nullptr);
    ~bashBox();

private:
    void initVariable();
    void reSetUI();


};
#endif // BASHBOX_H
