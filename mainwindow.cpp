#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

//tworzenie nowych okien


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , serverHttpConn_("http://130.162.35.167", 1880)
{
    ui->setupUi(this);
    // QCoreApplication::setApplicationName(QString("Messenger"));
    // setWindowTitle(QCoreApplication::applicationName());

    // setAutoFillBackground(true);

    // QWidget* centralWidget = new QWidget(this);
    // setCentralWidget(centralWidget);

    // QWidget* leftWidget = new QWidget();
    // QWidget* rightWidget = new  QWidget();
    // QWidget* topWidget = new QWidget();

    // QString fullSizeStyleSheet = "margin:0;"
    //                              "padding:0;"
    //                              "height:100%;"
    //                              "width:100%;";

    // QString fontStyleSheet = "color: #dcdfe3;"
    //                          "font-family: 'HelveticaNeue-Light', 'Helvetica Neue Light', 'Helvetica Neue',"
    //                          "Helvetica, Arial, 'Lucida Grande', sans-serif;"
    //                          "font-size: 20px;";

    // QString borderStyleSheet = "border-width: 2px;"
    //                            "border-style: solid;"
    //                            "border-color: #3a3c3d;";

    // QString leftWidgetStyleSheet = "background-color: #252728;";

    // QString rightWidgetStyleSheet = "background-color: #242526;";

    // QString topWidgetStyleSheet = "background-color: #252728;";

    // leftWidget->setStyleSheet(leftWidgetStyleSheet + fontStyleSheet + fullSizeStyleSheet + borderStyleSheet);
    // rightWidget->setStyleSheet(rightWidgetStyleSheet + fontStyleSheet + fullSizeStyleSheet + borderStyleSheet);
    // topWidget->setStyleSheet(topWidgetStyleSheet + fontStyleSheet + fullSizeStyleSheet + borderStyleSheet);
    // topWidget->setFixedHeight(50);

    // QVBoxLayout* leftLayout = new QVBoxLayout();
    // QVBoxLayout* rightLayout = new QVBoxLayout();
    // QHBoxLayout* topLayout  =new QHBoxLayout();

    // leftLayout->addWidget(new QLabel("Chats"));
    // leftWidget->setContentsMargins(0, 0, 0, 0);

    // rightLayout->addWidget((new QLabel("Your current conversation")));
    // rightWidget->setContentsMargins(0, 0, 0, 0);

    // QHBoxLayout* horizontalLayout = new QHBoxLayout();
    // horizontalLayout->addWidget(leftWidget,1);
    // horizontalLayout->addWidget(rightWidget, 2);

    // topLayout->addWidget(new QLabel("Menu"));
    // topLayout->setContentsMargins(0,0,0,0);


    // QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);
    // mainLayout->addWidget(topWidget);
    // mainLayout->addLayout(horizontalLayout);

    // mainLayout->setContentsMargins(0,0,0,0);
    // mainLayout->setSpacing(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_checkConnectionButton_clicked()
{
    std::thread th(checkConnection, std::ref(serverHttpConn_));

    th.join();
}


void MainWindow::on_loginButton_clicked()
{
    std::thread th(loginUser, std::ref(serverHttpConn_), "mateusz", "abc");

    th.join();
}


void MainWindow::on_registerButton_clicked()
{
    std::thread th(registerUser, std::ref(serverHttpConn_), "mateusz", "abc");

    th.join();
}

