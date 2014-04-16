#include "openeditor2d.h"
#include "ui_openeditor2d.h"

OpenEditor2d::OpenEditor2d(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OpenEditor2d)
{
    ui->setupUi(this);
}

OpenEditor2d::~OpenEditor2d()
{
    delete ui;
}
