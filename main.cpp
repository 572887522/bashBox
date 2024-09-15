#include "bashbox.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bashBox w;
    w.show();
    return a.exec();
}
