#include "DataParse.h"

#define ROOT_TAG    "root"
#define BLOCKS_TAG  "Blocks"
#define ITEMS_TAG   "Items"
#define BLOCK_TAG   "Block"
#define ITEM_TAG    "Item"

#define CN_NAME     "ChineseName"
#define EN_NAME     "EnglishName"
#define ME_NAME     "MaterialName"
#define ME_ID       "MaterialID"
#define ME_DURA     "MaterialDurability"

bool DataParse::openFile(QString path)
{   
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug()<<"读取文件错误!";
        return false;
    }

    m_pReader = new QXmlStreamReader(&file);

    while (!m_pReader->atEnd())
    {
        m_pReader->readNext();

        if (m_pReader->name() == ROOT_TAG)
        {
            if(!readRoot())
            {
                m_pReader->clear();
                delete m_pReader;
                m_pReader = NULL;
                file.close();
                return false;
            }
        }
    }

    if (m_pReader->hasError())
    {
        error();
        file.close();
        return false;
    }

    m_pReader->clear();
    delete m_pReader;
    m_pReader = NULL;
    file.close();
    return true;
}

void DataParse::test()
{
    for(int i = 0; i < m_vBlockData.size(); ++i)
        qDebug()<<m_vBlockData[i].getInfo();

    for(int i = 0; i < m_vItemData.size(); ++i)
        qDebug()<<m_vItemData[i].getInfo();
}

void DataParse::error()
{
    qDebug()<<"数据文件有误，无法正常读取!";
    m_pReader->clear();
    delete m_pReader;
    m_pReader = NULL;
}

bool DataParse::readRoot()
{
    while (!m_pReader->atEnd())
    {
        m_pReader->readNext();

        if (m_pReader->name() == BLOCKS_TAG && m_pReader->isStartElement())
        {
            if(!readBlocks())
                return false;
        }
        else if (m_pReader->name() == ITEMS_TAG && m_pReader->isStartElement())
        {
            if(!readItems())
                return false;
        }
    }

    if (m_pReader->hasError())
    {
        error();
        return false;
    }

    return true;
}

bool DataParse::readBlocks()
{
    while (!m_pReader->atEnd())
    {
        m_pReader->readNext();

        if (m_pReader->name() == BLOCK_TAG && m_pReader->isStartElement())
        {
            if(!readBlock())
                return false;
        }
        else if(m_pReader->name() == BLOCKS_TAG && m_pReader->isEndElement())
        {
            return true;
        }
    }

    if (m_pReader->hasError())
    {
        error();
        return false;
    }

    return true;
}

bool DataParse::readItems()
{
    while (!m_pReader->atEnd())
    {
        m_pReader->readNext();

        if (m_pReader->name() == ITEM_TAG && m_pReader->isStartElement())
        {
            if(!readItem())
                return false;
        }
        else if(m_pReader->name() == ITEMS_TAG && m_pReader->isEndElement())
        {
            return true;
        }
    }

    if (m_pReader->hasError())
    {
        error();
        return false;
    }

    return true;
}

bool DataParse::readBlock()
{
    BlockData blockData;

    while (!m_pReader->atEnd())
    {
        m_pReader->readNext();

        if(m_pReader->isStartElement())
        {
            if (m_pReader->name() == CN_NAME )
            {
                blockData.setCnName(m_pReader->readElementText());
            }
            else if(m_pReader->name() == EN_NAME )
            {
                blockData.setEnName(m_pReader->readElementText());
            }
            else if(m_pReader->name() == ME_NAME )
            {
                blockData.setMeName(m_pReader->readElementText());
            }
            else if(m_pReader->name() == ME_ID )
            {
                blockData.setNID(m_pReader->readElementText().toInt());
            }
        }
        else if(m_pReader->isEndElement() && m_pReader->name() == BLOCK_TAG)
        {
            break;
        }
    }

    if (m_pReader->hasError())
    {
        error();
        return false;
    }

    m_vBlockData.push_back(blockData);
    return true;
}

bool DataParse::readItem()
{
    ItemData itemData;

    while (!m_pReader->atEnd())
    {
        m_pReader->readNext();

        if(m_pReader->isStartElement())
        {
            if (m_pReader->name() == CN_NAME)
            {
                itemData.setCnName(m_pReader->readElementText());
            }
            else if(m_pReader->name() == EN_NAME)
            {
                itemData.setEnName(m_pReader->readElementText());
            }
            else if(m_pReader->name() == ME_NAME)
            {
                itemData.setMeName(m_pReader->readElementText());
            }
            else if(m_pReader->name() == ME_ID)
            {
                itemData.setNID(m_pReader->readElementText().toInt());
            }
            else if(m_pReader->name() == ME_DURA)
            {
                itemData.setNDurability(m_pReader->readElementText().toInt());
            }
        }
        else if(m_pReader->isEndElement())
        {
            if(m_pReader->name() == ITEM_TAG)
                break;
        }
    }

    if (m_pReader->hasError())
    {
        error();
        return false;
    }

    m_vItemData.push_back(itemData);
    return true;
}


