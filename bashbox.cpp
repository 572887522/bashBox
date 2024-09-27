#include "bashbox.h"
#include "ui_bashbox.h"


bashBox::bashBox(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::bashBox)
{
    ui->setupUi(this);

    initVariable();
    reSetUI();
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

void bashBox::initVariable()
{
    shortBoxs = new QVector<shortBox*>();
    glayout = new flowLayout(ui->tab);

    for(int i = 0;i < MAXBOXNUMBER; i++)
    {
        shortBox *shBox = new shortBox(this);
        shortBoxs->push_back(shBox);
    }
}

void bashBox::reSetUI()
{
    ui->tabWidget->setCurrentIndex(0);

    glayout->setSpacing(10);

    for(int i = 0;i < MAXBOXNUMBER; i++)
    {
        shortBox *shBox = shortBoxs->at(i);
        shBox->setFixedSize(50,50);
        shBox->setAcceptDrops(true);

        glayout->addWidget(shBox);
    }
}
