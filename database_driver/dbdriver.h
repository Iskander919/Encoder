#ifndef DBDRIVER_H
#define DBDRIVER_H

#include <string>

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class DatabaseDriver {

public:

    bool connectionOk;

    DatabaseDriver(std::string dbName,
                   std::string hostName,
                   std::string userName,
                   std::string password);

    void setConnection();
    void closeConnection();
    bool userExists(const QString& userLogin, const QString& userPassword);

private:

    QSqlDatabase databaseObj;

};

#endif // DBDRIVER_H
