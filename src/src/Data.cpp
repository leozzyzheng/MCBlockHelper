#include "Data.h"

QString BlockData::meName() const
{
return m_meName;
}

void BlockData::setMeName(const QString &meName)
{
m_meName = meName;
}
QString BlockData::cnName() const
{
return m_cnName;
}

void BlockData::setCnName(const QString &cnName)
{
m_cnName = cnName;
}
QString BlockData::enName() const
{
return m_enName;
}

void BlockData::setEnName(const QString &enName)
{
m_enName = enName;
}
unsigned int BlockData::nID() const
{
return m_nID;
}

void BlockData::setNID(unsigned int nID)
{
    m_nID = nID;
}

QString BlockData::getInfo()
{
    return QString("ChineseName:" + m_cnName +
            ",EnglishName:" + m_enName +
            ",MaterialName:" + m_meName +
            ",MaterialID:" + QString::number(m_nID));
}




unsigned int ItemData::nDurability() const
{
return m_nDurability;
}

void ItemData::setNDurability(unsigned int nDurability)
{
m_nDurability = nDurability;
}
QString ItemData::enName() const
{
return m_enName;
}

void ItemData::setEnName(const QString &enName)
{
m_enName = enName;
}
QString ItemData::meName() const
{
return m_meName;
}

void ItemData::setMeName(const QString &meName)
{
m_meName = meName;
}
unsigned int ItemData::nID() const
{
return m_nID;
}

void ItemData::setNID(unsigned int nID)
{
m_nID = nID;
}
QString ItemData::cnName() const
{
return m_cnName;
}

void ItemData::setCnName(const QString &cnName)
{
    m_cnName = cnName;
}

QString ItemData::getInfo()
{
    return QString("ChineseName:" + m_cnName +
            ",EnglishName:" + m_enName +
            ",MaterialName:" + m_meName +
            ",MaterialID:" + QString::number(m_nID) +
            ",MaterialDurability:" + QString::number(m_nDurability));
}
