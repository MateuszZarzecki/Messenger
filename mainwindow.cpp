#include "mainwindow.h"
#include "ui_mainwindow.h"

//tworzenie nowych okien

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , serverHttpConn_("http://130.162.35.167", 1880)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    authorisationThread_ = new std::thread();
}

MainWindow::~MainWindow()
{
    if(authorisationThread_->joinable())
    {
        authorisationThread_->join();
    }
    delete ui;
    delete authorisationThread_;

}

// dla wątków - atomic runningStatusAuthorisation = false
// w przypadku wcisniecia drugiego przycisku runningStatusAuthorisation sie zmienia i odczytuje to dzialajacy watek w peti
//i wychodzi jak tylko sie o tym dowie
//wtedy dziala nowy proces
//autoryzacja na jednym watku - nie ma sensu tworzyc dwoch oddzielnych watkow do Login i Register bo nie moga one dzialac rozwnoczesnie


void MainWindow::useThread(std::thread* threadProcess)
{
    if(authorisationThread_->joinable())
    {
        authorisationThread_->join();
        delete authorisationThread_;
    }
    authorisationThread_ = threadProcess;
}
void MainWindow::on_checkConnectionButton_clicked()
{
    useThread(new std::thread (checkConnection, std::ref(serverHttpConn_)));
}

void MainWindow::on_loginButton_clicked()
{
    useThread(new std::thread(loginUser, std::ref(serverHttpConn_), username_.toStdString(), password_.toStdString()));
}

void MainWindow::on_registerButton_clicked()
{
    useThread(new std::thread(registerUser, std::ref(serverHttpConn_), username_.toStdString(), password_.toStdString()));
}

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


void MainWindow::on_usernameInput_textChanged(const QString &input)
{
    qDebug() << input;
    username_ = input;
}


void MainWindow::on_passwordInput_textChanged(const QString &input)
{
    qDebug() << input;
    password_ = input;
}

