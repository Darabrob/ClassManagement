#include "person.h"

Person::Person(const QString &sName, const QString &sSurname)
{
    m_sName = sName;
    m_sSurname = sSurname;
}

const QString &Person::name() const
{
    return m_sName;
}

void Person::setName(const QString &sName)
{
    m_sName = sName;
}

const QString &Person::surname() const
{
    return m_sSurname;
}

void Person::setSurname(const QString &sSurname)
{
    m_sSurname = sSurname;
}
