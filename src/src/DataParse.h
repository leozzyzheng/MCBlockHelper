#ifndef DATAPARSE_H
#define DATAPARSE_H

#include <QString>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include "Data.h"

class DataParse : public QObject
{
public:
    DataParse(){}
    bool   openFile    (QString path);
    void   test        ();

private:
    void   error       ();
    bool   readRoot    ();
    bool   readBlocks  ();
    bool   readItems   ();
    bool   readBlock   ();
    bool   readItem    ();

private:
    QVector<BlockData> m_vBlockData;
    QVector<ItemData>  m_vItemData;

    QXmlStreamReader * m_pReader;
};

#endif // DATAPARSE_H
