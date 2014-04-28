#include "openeditor2d.h"
#include "ui_openeditor2d.h"

#include <QToolBar>
#include <QSettings>

#include <QListView>
#include <QTreeView>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QIcon>

#include "configini.h"
#include "imagepack.h"
#include "scriptengine.h"

#include <QSplitter>

OpenEditor2d::OpenEditor2d(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OpenEditor2d)
{
    ui->setupUi(this);

    ScriptEngine::Instance()->setup();
    ConfigIni::Instance();
    QToolBar *tmpToolBar = ui->mMainToolBar;
    tmpToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    tmpToolBar->addAction(QIcon(":icon/new_file.png"),"New");
    tmpToolBar->addAction(QIcon(":icon/open_file.png"),"Open");
    tmpToolBar->addAction(QIcon(":icon/save.png"),"Save");
    tmpToolBar->addAction(QIcon(":icon/save_as.png"),"Save");
    tmpToolBar->addAction(QIcon(":icon/save_all.png"), "Save All");
    tmpToolBar->addSeparator();
    tmpToolBar->addAction("Go");

    QHBoxLayout *layout = new QHBoxLayout();
    mImagePack = new ImagePack();
    layout->addWidget(mImagePack);
    ui->mTabImagePack->setLayout(layout);
}

OpenEditor2d::~OpenEditor2d()
{
    ScriptEngine::Instance()->cleanup();
    delete ui;
}
