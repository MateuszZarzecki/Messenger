#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <SFML/Network.hpp>
#include "services/servercommunication.hpp"
#include <thread>
#include <QLabel>
#include <QThread>
#include "chrono"
#include <atomic>
#include <iostream>

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

    sf::Http serverHttpConn_;
    std::thread* authorisationThread_;
private slots:

    void on_checkConnectionButton_clicked();

    void on_loginButton_clicked();

    void on_registerButton_clicked();

    void on_usernameInput_textChanged(const QString &arg1);

    void on_passwordInput_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QString username_;
    QString password_;

    void useThread(std::thread* threadProcess);
};
#endif // MAINWINDOW_H
