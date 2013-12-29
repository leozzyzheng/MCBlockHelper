#ifndef DATA_H
#define DATA_H

#include <QString>

class BlockData
{

public:
    QString meName() const;
    void setMeName(const QString &meName);

    QString cnName() const;
    void setCnName(const QString &cnName);

    QString enName() const;
    void setEnName(const QString &enName);

    unsigned int nID() const;
    void setNID(unsigned int nID);

    QString getInfo();

private:
    QString         m_cnName;
    QString         m_enName;
    QString         m_meName;
    unsigned int    m_nID;
};

class ItemData
{

public:
    unsigned int nDurability() const;
    void setNDurability(unsigned int nDurability);

    QString enName() const;
    void setEnName(const QString &enName);

    QString meName() const;
    void setMeName(const QString &meName);

    unsigned int nID() const;
    void setNID(unsigned int nID);

    QString cnName() const;
    void setCnName(const QString &cnName);

    QString getInfo();

private:
    QString         m_cnName;
    QString         m_enName;
    QString         m_meName;
    unsigned int    m_nID;
    unsigned int    m_nDurability;
};

#endif // DATA_H






