#include "dbdriver.h"
/**
 * @brief DatabaseDriver::DatabaseDriver
 * @param dbName
 * @param hostName
 * @param userName
 * @param password
 */
DatabaseDriver::DatabaseDriver (std::string dbName,
                                std::string hostName,
                                std::string userName,
                                std::string password) {

    this -> databaseObj = QSqlDatabase::addDatabase("QPSQL");

    databaseObj.setHostName(QString::fromStdString(hostName));
    databaseObj.setDatabaseName(QString::fromStdString(dbName));
    databaseObj.setUserName(QString::fromStdString(userName));
    databaseObj.setPassword(QString::fromStdString(password));

    this -> connectionOk = false;

}

/**
 * @brief DatabaseDriver::setConnection
 */
void DatabaseDriver::setConnection() {

    this -> connectionOk = databaseObj.open();

}

/**
 * @brief DatabaseDriver::userExists
 * @param userLogin - user's login to check if exists in database
 * @param userPassword - password to check
 * @return
 */
bool DatabaseDriver::userExists(const QString& userLogin, const QString& userPassword) {

    if (!databaseObj.isOpen() && !databaseObj.isValid()) {

        //qdebug:: something
        return false;

    }

    QSqlQuery query(databaseObj);

    // getting user's login
    query.prepare("SELECT user_login FROM users WHERE user_login = :user_login_requested");

    // binding userLogin to query
    query.bindValue(":user_login_requested", userLogin);

    // checking if user exists and it's login unique
    if (query.exec() && !query.next()) {

        return true;

    }

    else {

        qDebug() << "Query failed to execute: " << query.lastError().text();
        return false;

    };

}



