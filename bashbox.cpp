#include "bashbox.h"
#include "ui_bashbox.h"


bashBox::bashBox(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::bashBox)
{

    ui->setupUi(this);

    reSetUI(ui);


}

bashBox::~bashBox()
{
    for(shortBox *shBox : *shortBoxs)
    {
        delete shBox;
        shBox = nullptr;
    }
    delete shortBoxs;
    delete ui;
}

void bashBox::reSetUI(Ui::bashBox *ui)
{
    shortBoxs = new QVector<shortBox*>();

    glayout = new QGridLayout(ui->tab);
    glayout->setSpacing(10);

    for(int i = 0;i < MAXBOXNUMBER; i++)
    {
        shortBox *shBox = new shortBox(QString("label %1").arg(i+1));
        shBox->setFixedSize(50,50);
        shortBoxs->push_back(shBox);

        glayout->addWidget(shBox, i/TABWIDGETCOLUMN, i%TABWIDGETCOLUMN);
    }
}
