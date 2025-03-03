#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkConnectionButton_clicked()
{
   checkConnection (conn->serverHttpConn);
}

void MainWindow::on_loginButton_clicked()
{
    if() {
        //authorisationThread_ = new std::thread(loginUser, this, std::ref(serverHttpConn_), username_.toStdString(), password_.toStdString());
    }
    else {
        qDebug() << "Login Failed";
    }
}

void MainWindow::on_registerButton_clicked()
{
    // if(validateRegisterInput()) {
    //     //authorisationThread_ = new std::thread(registerUser, this, std::ref(serverHttpConn_), username_.toStdString(), password_.toStdString());
    // }
    // else {
    //     qDebug() << "Register Failed";
    // }
}

void MainWindow::on_usernameInput_textChanged(const QString &input)
{
    conn->username = input.toStdString();
    qDebug() << input;

}
void MainWindow::on_passwordInput_textChanged(const QString &input)
{
    conn->password = input.toStdString();
    qDebug() << input ;
}

