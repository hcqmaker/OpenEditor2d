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

#include "datahelp.h"


bool trimImage(QRect &rect, const QImage &img)
{
    int xmin = img.width();
    int xmax = 0;
    int ymin = img.height();
    int ymax = 0;
    int oldWidth = img.width();
    int oldHeight = img.height();
    for (int y = 0; y < oldHeight; ++y)
    {
     for (int x = 0; x < oldWidth; ++x)
     {
      QRgb c = img.color(y * oldWidth + x);
      if (qAlpha(c) != 0)
      {
       if (y < ymin) ymin = y;
       if (y > ymax) ymax = y;
       if (x < xmin) xmin = x;
       if (x > xmax) xmax = x;
      }
     }
    }

    rect.setCoords(xmin, ymin, xmax, ymax);
    return false;
}

ImagePackData *createImagePackDataByUrl(const QUrl& url)
{
    ImagePackData *d = new ImagePackData();
    d->url = url;
    d->nImage = QImage(url.toLocalFile());
    d->rSize = d->nImage.size();
    trimImage(d->nRect, d->nImage);
    return d;
}

bool updateImagePackPos(QList<ImagePackData*>& list)
{
    return true;
}

DataHelp::DataHelp()
{
}
DataHelp::~DataHelp()
{

}

DataHelp *DataHelp::Instance()
{
    static DataHelp _instance;
    return &_instance;
}

void DataHelp::setImagePackList(const QList<QUrl> &list)
{
    clearImagePack();

    this->mImagePackList = list;
    foreach(QUrl url, this->mImagePackList)
    {
        ImagePackData *d = createImagePackDataByUrl(url);
        this->mImagePackDataList.push_back(d);
    }
}

void DataHelp::addImagePack(const QUrl &url)
{
    foreach(QUrl ourl, this->mImagePackList)
    {
        if (ourl == url)
            return;
    }
    ImagePackData *d = createImagePackDataByUrl(url);
    this->mImagePackDataList.push_back(d);
}

void DataHelp::delImagePack(int i)
{
    //QAssert(i < this->mImagePackList.size());
    ImagePackData *d = mImagePackDataList.at(i);
    delete d;
    this->mImagePackDataList.removeAt(i);
    this->mImagePackList.removeAt(i);
}

void DataHelp::clearImagePack()
{
    foreach(ImagePackData *data, this->mImagePackDataList)
    {
        delete data;
    }
    this->mImagePackDataList.clear();
    this->mImagePackList.clear();
}
