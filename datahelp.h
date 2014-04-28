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

#ifndef DATAHELP_H
#define DATAHELP_H

#include <QTransform>
#include <QUrl>
#include <QRect>
#include <QSize>
#include <QImage>

struct ImagePackData
{
    QUrl url;
    QTransform trans;
    QSize rSize;    // real size
    QRect nRect;    // now rect
    QImage nImage;  // now image
};

bool trimImage(QRect &rect, const QImage &img);
ImagePackData *createImagePackDataByUrl(const QUrl& url);
bool updateImagePackPos(QList<ImagePackData*>& list);

class DataHelp
{
protected:
    DataHelp();
    QList<QUrl> mImagePackList;
    QList<ImagePackData*> mImagePackDataList;
public:
    ~DataHelp();

    static DataHelp *Instance();

    void setImagePackList(const QList<QUrl> &list);
    QList<ImagePackData*>& getImagePackDataList() { return mImagePackDataList; }
    QList<QUrl>& getImagePackList() { return mImagePackList; }
    void addImagePack(const QUrl &url);
    void delImagePack(int i);
    void clearImagePack();

};

#endif // DATAHELP_H
