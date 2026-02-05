#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow{parent} {

    setupUi();
    setupConnections();

}

/**
 * @brief MainWindow::setupUi that setups ui elements of MainWindow
 * @param
 * @return
 */
void MainWindow::setupUi() {

    /*
     * definig central widget(MainWindow) and layout
     */
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(central);
    setCentralWidget(central);


    /*
     * defining head leabel
     */

    QLabel *header = new QLabel("Security App", central);
    layout -> addWidget(header);
    header -> setStyleSheet("border: 3px solid black; font-size: 16px;");
    header -> setAlignment(Qt::AlignCenter);


    /*
     * defining buttons
     */

    signInButton = new QPushButton("Sign in");
    signUpButton = new QPushButton("Sign up");

    closeButton = new QPushButton("Close app");


    layout -> addWidget(signInButton);
    layout -> addWidget(signUpButton);
    layout -> addWidget(closeButton);

    resize(400, 400);
    setWindowTitle("Iskander's Security App");

}

/**
 * @brief MainWindow::setupConnections() - function that setups connections between slots and signals
 * @param
 * @return
 */
void MainWindow::setupConnections() {

    connect(closeButton, &QPushButton::clicked, this, &QWidget::close); // connecting Close button

    connect(signUpButton, &QPushButton::clicked, this, &MainWindow::signUpClicked); // connecting Sign up button

    connect(signInButton, &QPushButton::clicked, this, &MainWindow::signInClicked); // connecting Sign in button

}

void MainWindow::signUpClicked() {

    AuthDialog authDialog(this); // "this" is a parent widget (MainWindow)

    authDialog.exec();

}

void MainWindow::signInClicked() {

    SignInDialog SignInDialogObj(this); // "this" is a parent widget (MainWindow)

    SignInDialogObj.exec();

}



