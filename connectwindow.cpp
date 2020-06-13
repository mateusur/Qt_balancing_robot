#include "connectwindow.h"
#include "ui_connectwindow.h"

#include "interfacewindow.h"

#include "UDPclient.h"

ConnectWindow* connectWindow;

ConnectWindow::ConnectWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ConnectWindow)
{
    ui->setupUi(this);
    setFixedSize(maximumSize());

    ui->errorConnectionMsg->hide();

    int w = ui->label_pic1->width();
    int h = ui->label_pic1->height();
    QPixmap pix_error(":/icons/icons_error.png");
    QPixmap pix_check(":/icons/check.png");
    ui->label_pic1->setPixmap(pix_check.scaled(w,h,Qt::KeepAspectRatioByExpanding));
    ui->label_pic2->setPixmap(pix_check.scaled(w,h,Qt::KeepAspectRatioByExpanding));
    ui->label_pic3->setPixmap(pix_check.scaled(w,h,Qt::KeepAspectRatioByExpanding));
    connect( ui->ipServer, SIGNAL(textChanged(const QString &)), this, SLOT(set_icon(const QString &)));
    connect( ui->portServer, SIGNAL(textChanged(const QString &)), this, SLOT(set_icon(const QString &)));
    connect( ui->portClient, SIGNAL(textChanged(const QString &)), this, SLOT(set_icon(const QString &)));

}

ConnectWindow::~ConnectWindow()
{
    delete ui;
}

void ConnectWindow::set_pixmap(QLabel *label, const QString &icon)
{
    QPixmap pix_error(":/icons/icons_error.png");
    QPixmap pix_check(":/icons/check.png");
    int w = label->width();
    int h = label->height();
    if(icon == "error")
      label->setPixmap(pix_error.scaled(w,h,Qt::KeepAspectRatioByExpanding));
    else
        label->setPixmap(pix_check.scaled(w,h,Qt::KeepAspectRatioByExpanding));
}

void ConnectWindow::set_icon(const QString &text)
{
    QObject *psender = sender();
//    qDebug() << sender();
    QString name = psender->objectName();
    if(text =="192.168.1.102" && name =="ipServer")
        set_pixmap(ui->label_pic1,"check");
    else if (text !="192.168.1.102" && name =="ipServer")
        set_pixmap(ui->label_pic1,"error");
    else if (text =="8080" && name =="portServer")
        set_pixmap(ui->label_pic2,"check");
    else if(text !="8080" && name =="portServer")
        set_pixmap(ui->label_pic2,"error");
    else if(text =="25000" && name =="portClient")
        set_pixmap(ui->label_pic3,"check");
    else if(text !="25000" && name =="portClient")
        set_pixmap(ui->label_pic3,"error");
    if( (text =="192.168.1.102" && name =="ipServer") && (text =="8080" && name =="portServer") && (text =="25000" && name =="portClient") )
        ui->pushButton->setCheckable(true);
    else
        ui->pushButton->setCheckable(false);
}

void ConnectWindow::on_pushButton_clicked()
{
    std::string serverIP = ui->ipServer->text().toStdString();
    int serverPort = ui->portServer->text().toInt();
    int clientPort = ui->portClient->text().toInt();
    if( !UDPclient_init(clientPort) ||
        !UDPclient_setSeverIPAddress(serverIP.c_str(), serverPort))
    {
        ui->errorConnectionMsg->show();
        QTimer::singleShot(1000, ui->errorConnectionMsg, SLOT(hide()));

        return;
    }

    UDPclient_sendReq("heheh", 5);

    interfaceWindow->show();

    close();
}
