#ifndef DATAHANDLER_H
#define DATAHANDLER_H
#include <QString>
#include <QMap>
#include <qsqldatabase.h>

class DataHandler
{
public:
    DataHandler();

    QMap<QString, QStringList> classes() const;

    bool loadClasses();
    void writeClasses();
    void addClass(QString sYear, QString sDescription);
    void removeClass(QString sYear, QString sDescription);

private:

    QSqlDatabase m_db;
    QMap<QString, QStringList>  m_classes;
};

#endif // DATAHANDLER_H
