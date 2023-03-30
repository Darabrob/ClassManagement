#include "datahandler.h"
#include <QFile>
#include <QMessageBox>
#include <qsqlquery.h>
#include <qsqlrecord.h>
#include <qsqlerror.h>
#include <qsqlresult.h>

DataHandler::DataHandler()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("../ClassManagement/data/data.sqlite");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}

QMap<QString, QStringList> DataHandler::classes() const
{
    return m_classes;
}

bool DataHandler::loadClasses()
{
    m_classes.clear();
    QSqlQuery yearQuery(m_db);
    yearQuery.prepare("Select Year from classes;");
    if( !yearQuery.exec() )
    {
      qDebug() << "Fehler: " <<  yearQuery.lastError().text();
      return false;
    }
    QStringList yearList;
    while (yearQuery.next())
    {
        QString sYear = yearQuery.value(0).toString();
        yearList.append(sYear);
    }

    for(int nIx = 0; nIx < yearList.length(); nIx++) {
        QSqlQuery query(m_db);
           query.prepare("Select Description FROM classes WHERE Year = (:year)");
           query.bindValue(":year", yearList.at(nIx));
           bool bSuccess = query.exec();

           if(!bSuccess)
           {
               qDebug() << query.lastError();
               return false;
           } else {
               QStringList classes;
               while (query.next())
               {
                   QString sDescription = query.value(0).toString();
                   classes.append(sDescription);
               }
               m_classes.insert(yearList.at(nIx), classes);
           }
    }
    return true;
}

void DataHandler::writeClasses()
{
    QFile file("../ClassManagement/data/classes.dat");
    if(!file.open(QIODevice::ReadWrite|QFile::Truncate)) {
        QMessageBox::information(0,"error",file.errorString());
    }

    QTextStream stream(&file);

    QMapIterator<QString, QStringList> i(m_classes);
    while (i.hasNext()) {
        i.next();
        qDebug() << i.key() << ": " << i.value();
        QString sLine = i.key();
        sLine.append(":");
        for(int nIx=0; nIx < i.value().size(); nIx++) {
            sLine.append(i.value().at(nIx));
            sLine.append(";");
        }
        sLine.remove(sLine.size()-1,1);
        sLine.append("\n");

        stream << sLine;
    }

    file.close();
}

void DataHandler::addClass(QString sYear, QString sDescription)
{
    QMapIterator<QString, QStringList> i(m_classes);
    bool bAddedToExistingYear = false;
    while (i.hasNext()) {
        i.next();
        if(sYear == i.key()) {
            QStringList classes = i.value();
            classes.append(sDescription);
            m_classes.insert(i.key(), classes);
            bAddedToExistingYear = true;
        }
    }
    if(!bAddedToExistingYear) {
        m_classes.insert(sYear, {sDescription} );
    }
    writeClasses();
}

void DataHandler::removeClass(QString sYear, QString sDescription)
{
    QMapIterator<QString, QStringList> i(m_classes);
    while (i.hasNext()) {
        i.next();
        if(sYear == i.key()) {
            QStringList classes = i.value();
            for(int nIx = 0; nIx < classes.size(); nIx++) {
                if(classes.at(nIx) == sDescription) {
                    classes.remove(nIx);
                    m_classes.remove(i.key());
                    m_classes.insert(i.key(), classes);
                    writeClasses();
                }
            }
        }
    }
}
