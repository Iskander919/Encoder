#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

#include "signupdialog.h"
#include "signindialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:

    // decalring widgets as class fields
    QPushButton *signInButton = nullptr;
    QPushButton *signUpButton = nullptr;

    QPushButton *closeButton = nullptr;



    explicit MainWindow(QWidget *parent = nullptr);
private:

    void setupUi();
    void setupConnections();

private slots:

    void signUpClicked();
    void signInClicked();


};

#endif // MAINWINDOW_H
