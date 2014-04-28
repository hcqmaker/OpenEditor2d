/*
The MIT License (MIT)

Copyright (c) 2014 holmes

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "imagepack.h"
#include "ui_imagepack.h"
#include "ui_imagepackleft.h"
#include "ui_imagepackright.h"

#include <QSplitter>
#include <QDragEnterEvent>
#include <QUrl>
#include <QDropEvent>
#include <QStringList>


ImagePack::ImagePack(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImagePack),
    uil(new Ui::ImagePackLeft),
    uir(new Ui::ImagePackRight)
{
    this->setAcceptDrops(true);
    QHBoxLayout *layout = new QHBoxLayout(this);
    QSplitter *splitter = new QSplitter();

    QWidget *left = new QWidget();
    QWidget *center = new QWidget();
    QWidget *right = new QWidget();

    uil->setupUi(left);
    ui->setupUi(center);
    uir->setupUi(right);

    splitter->addWidget(left);
    splitter->addWidget(center);
    splitter->addWidget(right);

    layout->addWidget(splitter);
    this->setLayout(layout);

}

ImagePack::~ImagePack()
{
    delete ui;
}

//--------------------------------------------------------------------
//
void ImagePack::dragEnterEvent(QDragEnterEvent * event)
{
    if(event->mimeData()->hasFormat("text/uri-list")) {
            event->acceptProposedAction();
    }
}

void ImagePack::dropEvent(QDropEvent *event)
{
    const QMimeData *tmpData = event->mimeData();
    if (tmpData){
            QList<QUrl> tmpList = tmpData->urls();
            QStringList tmpSList;
            for (int i = 0; i < tmpList.size(); ++i)
            {
                tmpSList.push_back(tmpList.at(i).toLocalFile());
            }

            tmpSList.sort();

            uir->mListWidget->addItems(tmpSList);
            //ui->mListWidget->addItems(tmpSList);
            //addAnim();
            //mScene->addImages(tmpSList);
    }
}
