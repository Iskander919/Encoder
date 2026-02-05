#ifndef AUTHDIALOG_H
#define AUTHDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QWidget>

/**
 * @brief The AuthDialog class is a class for authenctification form
 * @param
 * @return
 */

class AuthDialog : public QDialog {
public:

    explicit AuthDialog(QWidget *parent = nullptr);

private:

    QPushButton *confirmButton = nullptr;

    QLineEdit *loginForm = nullptr;

    QLineEdit *passwordForm = nullptr;

    QLineEdit *passwordConfirmationForm = nullptr;

    void setAuthDialogUi();
    void setAuthDialogConnections();

private slots:

    void confirmClicked();              // "Sign up" button clicked" slot
    void passwordTextChanged();         // "Password or confirm text changed" slot

};

#endif // AUTHDIALOG_H
