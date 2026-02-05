#include "signupdialog.h"

/**
 * @brief AuthDialog::AuthDialog
 * @param parent
 */
AuthDialog::AuthDialog(QWidget *parent) : QDialog(parent) {

    setWindowModality(Qt::WindowModality::ApplicationModal);
    setFixedSize(200, 250);


    setAuthDialogUi();
    setAuthDialogConnections();

}

/**
 * @brief AuthDialog::setAuthDialogUi
 * @param
 * @return
 */
void AuthDialog::setAuthDialogUi() {

    setWindowTitle("Sign up");

    QVBoxLayout *authDialogLayout = new QVBoxLayout(this);

    // defining login label:
    QLabel *labelLogin = new QLabel;
    labelLogin -> setText("Enter login: ");

    // defining password label:
    QLabel *labelPassword = new QLabel;
    labelPassword -> setText("Enter password: ");

    QLabel *labelConfirmPassword = new QLabel;
    labelConfirmPassword -> setText("Confirm password: ");

    // defining line edits for password and login entering:

    loginForm    = new QLineEdit(this);

    passwordForm = new QLineEdit(this);

    passwordConfirmationForm    = new QLineEdit(this);

    authDialogLayout -> addWidget(labelLogin); // "Enter login" label
    authDialogLayout -> addWidget(loginForm);  // login line edit


    authDialogLayout -> addWidget(labelPassword); // "Enter password" label
    authDialogLayout -> addWidget(passwordForm);  // password line edit

    authDialogLayout -> addWidget(labelConfirmPassword);      // "Confirm password" label
    authDialogLayout -> addWidget(passwordConfirmationForm);  // password confirmation line edit

    // defining "Confirm" button:

    confirmButton = new QPushButton("Confirm", this);
    authDialogLayout -> addWidget(confirmButton);
    //confirmButton -> setEnabled(false);


}

/**
 * @brief AuthDialog::setAuthDialogConnections
 */
void AuthDialog::setAuthDialogConnections() {

    connect(confirmButton, &QPushButton::clicked, this, &AuthDialog::confirmClicked);

    connect(passwordForm, &QLineEdit::textChanged, this, &AuthDialog::passwordTextChanged);

    connect(passwordConfirmationForm, &QLineEdit::textChanged, this, &AuthDialog::passwordTextChanged);

}

/**
 * @brief isPasswordConfirmed
 * @param password
 * @param confirmPassword
 * @return
 */
bool isPasswordConfirmed(const QString &password, const QString &confirmPassword) {

    if(confirmPassword == password && !password.isEmpty() && !confirmPassword.isEmpty()) return true;

    else return false;

}

/**
 * @brief AuthDialog::confirmClicked
 */
void AuthDialog::confirmClicked() {


}


/**
 * @brief AuthDialog::passwordTextChanged
 */
void AuthDialog::passwordTextChanged() {

    QString password = passwordForm -> text();
    QString confirmPassword = passwordConfirmationForm -> text();

    confirmButton -> setEnabled(isPasswordConfirmed(password, confirmPassword));
}




