#include "group.h"

Group::Group(const QString &sYear, const QString &sDescription)
{
    m_sYear = sYear;
    m_sDescription = sDescription;
}

const QString &Group::year() const
{
    return m_sYear;
}

void Group::setYear(const QString &sYear)
{
    m_sYear = sYear;
}

const QString &Group::description() const
{
    return m_sDescription;
}

void Group::setDescription(const QString &sDescription)
{
    m_sDescription = sDescription;
}
