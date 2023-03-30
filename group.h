#ifndef GROUP_H
#define GROUP_H
#include <QString>

class Group
{
public:
    Group(const QString& sYear, const QString& sDescription);

    const QString &year() const;
    void setYear(const QString &newSYear);

    const QString &description() const;
    void setDescription(const QString &sDescription);

private:
    QString m_sYear;
    QString m_sDescription;
};

#endif // GROUP_H
