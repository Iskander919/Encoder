#ifndef SIGNINDIALOG_H
#define SIGNINDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "dbdriver.h"
#include "dbconfig.h"

class SignInDialog : public QDialog {
public:

    explicit SignInDialog(QWidget *parent = nullptr);

private:
    QPushButton *confirmButton = nullptr;

    QLineEdit *loginForm = nullptr;

    QLineEdit *passwordForm = nullptr;

    void setSignInDialogUi();
    void setSignInDialogConnections();

    QString usernameToRequest;

    void updateConfirmButton();

private slots:
    void confirmClicked();

    void passwordFormChanged();
    void loginFormChanged();

};

#endif // SIGNINDIALOG_H
