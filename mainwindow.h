#pragma once
#include "ui_mainwindow.h"
#include "services/apihandler.hpp"
#include <QLabel>
#include <QThread>
#include <chrono>
#include <atomic>
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void on_checkConnectionButton_clicked();

    void on_loginButton_clicked();

    void on_registerButton_clicked();

    void on_usernameInput_textChanged(const QString &arg1);

    void on_passwordInput_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    Connection* conn = new Connection();
    AuthorizationClient authClient;
    ChatClient chatClient;
};
