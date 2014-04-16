#include <QtGui/QApplication>
#include "openeditor2d.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OpenEditor2d w;
    w.show();

    return a.exec();
}
