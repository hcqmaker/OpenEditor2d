#ifndef OPENEDITOR2D_H
#define OPENEDITOR2D_H

#include <QMainWindow>

namespace Ui {
    class OpenEditor2d;
}

class OpenEditor2d : public QMainWindow
{
    Q_OBJECT

public:
    explicit OpenEditor2d(QWidget *parent = 0);
    ~OpenEditor2d();

private:
    Ui::OpenEditor2d *ui;
};

#endif // OPENEDITOR2D_H
