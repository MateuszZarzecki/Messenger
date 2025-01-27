#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <SFML/Network.hpp>
#include "services/servercommunication.hpp"
#include <thread>

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

private slots:

    void on_checkConnectionButton_clicked();

    void on_loginButton_clicked();

    void on_registerButton_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
