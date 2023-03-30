#ifndef PERSON_H
#define PERSON_H
#include <QString>

class Person
{
public:
    Person(const QString& sName, const QString& sSurname);

    const QString& name() const;
    void setName(const QString& sName);
    const QString& surname() const;
    void setSurname(const QString& sSurname);

private:
    QString m_sName;
    QString m_sSurname;
};

#endif // PERSON_H
