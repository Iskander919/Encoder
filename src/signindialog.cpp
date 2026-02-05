#include "signindialog.h"
#include <iostream>

SignInDialog::SignInDialog(QWidget *parent) : QDialog(parent) {

    this -> usernameToRequest = "";

    setWindowModality(Qt::WindowModality::WindowModal);
    setFixedSize(200, 150);

    setSignInDialogUi();
    setSignInDialogConnections();

}

/**
 * @brief SignInDialog::setSignInDialogUi
 */
void SignInDialog::setSignInDialogUi() {

    setWindowTitle("Sign In");

    QVBoxLayout *signInLayout = new QVBoxLayout(this);

    // defining login label
    QLabel *labelLogin = new QLabel;
    labelLogin -> setText("Login: ");

    // defining password label
    QLabel *labelPassword = new QLabel;
    labelPassword -> setText("Password: ");

    loginForm    = new QLineEdit(this);

    passwordForm = new QLineEdit(this);

    signInLayout -> addWidget(labelLogin); // "Enter login" label
    signInLayout -> addWidget(loginForm);  // login line edit


    signInLayout -> addWidget(labelPassword); // "Enter password" label
    signInLayout -> addWidget(passwordForm);  // password line edit

    // defining "Confirm" button:

    confirmButton = new QPushButton("Confirm", this);
    signInLayout -> addWidget(confirmButton);
    confirmButton -> setEnabled(false);


}

/**
 * @brief SignInDialog::setSignInDialogConnections
 */
void SignInDialog::setSignInDialogConnections() {

    connect(confirmButton, &QPushButton::clicked, this, &SignInDialog::confirmClicked);

    connect(loginForm, &QLineEdit::textChanged, this, &SignInDialog::loginFormChanged);

    connect(passwordForm, &QLineEdit::textChanged, this, &SignInDialog::passwordFormChanged);

}

/**
 * @brief SignInDialog::confirmClicked
 */
void SignInDialog::confirmClicked() {

    DatabaseDriver dbDriver(DATABASE_NAME, DATABASE_HOST_NAME, DATABASE_USER_NAME, DATABASE_PASSWORD);
    dbDriver.setConnection(); // setting connection to a database
    std::cout << "Database connection status: " << dbDriver.connectionOk << std::endl;

    if(!dbDriver.connectionOk) {

        std::cout << "Database connection lost" << std::endl;

        return;

    }

    else {

        //std::cout << "User exists: " << dbDriver.userExists() << std::endl;

    }

}

/**
 * @brief SignInDialog::loginFormChanged
 */
void SignInDialog::loginFormChanged() {

    updateConfirmButton();

}

/**
 * @brief SignInDialog::passwordFormChanged
 */
void SignInDialog::passwordFormChanged() {

    updateConfirmButton();

}

void SignInDialog::updateConfirmButton() {

    bool loginIsEmpty = loginForm -> text().isEmpty();
    bool passwordIsEmpty = passwordForm -> text().isEmpty();

    confirmButton -> setEnabled(!loginIsEmpty && !passwordIsEmpty);

}
