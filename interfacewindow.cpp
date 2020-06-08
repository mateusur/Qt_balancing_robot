#include "interfacewindow.h"
#include "ui_interfacewindow.h"

#include "UDPclient.h"
#include <string>
#include <iostream>

InterfaceWindow* interfaceWindow;

InterfaceWindow::InterfaceWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InterfaceWindow)
{
    ui->setupUi(this);
    //Wykres pierwszy
    graph1 = new Plot(this,ui->wykres,ui->comboBox);
    //Wykres 2
    graph2 = new Plot(this,ui->wykres2,ui->comboBox2);

    //timer1=new QTimer;
    tim_data=new QTimer;
    //timer3=new QTimer;

//    connect(timer1,SIGNAL(timeout()),this,SLOT(draw()));
//    connect(timer3,SIGNAL(timeout()),this,SLOT(draw2()));
    connect(tim_data,SIGNAL(timeout()),this,SLOT(recive_data()));
    //timer1->start(20);
    tim_data->start(5);
    //timer3->start(20);
    //Mozliwosc stopowania rysowania przez powdwojne klikniecie na wykres
//    connect(ui->wykres,SIGNAL(mouseDoubleClick(QMouseEvent*)),this,SLOT(STOP_PLOT()));
//    connect(ui->wykres2, SIGNAL(mouseDoubleClick(QMouseEvent*)), this, SLOT(STOP_PLOT2()));
    ui->widget_battery->setValue(45);

    set_icons();
    connect(this,SIGNAL(send_point(QString, QCPGraphData)),graph1,SLOT(add_point(QString , QCPGraphData)));
    connect(this,SIGNAL(send_point(QString, QCPGraphData)),graph2,SLOT(add_point(QString , QCPGraphData)));
//    emit zwroc_liczbe("LMP",{2,3});
//    emit zwroc_liczbe("LMP",{12,3});
//    emit zwroc_liczbe("RMP",{2,21});
    tim_elapsed.start();
}

//Zeby byla mozliwosc stopowania rysowania, powinny byc 2 funckje draw (wywolujace inne "wykresiki") - nwm jak to ominac
//void InterfaceWindow::draw()
//{
//}
//void InterfaceWindow::draw2()
//{
//}
//Metoda pozwalajaca na zatrzymywanie wykresu poprzez podwójne klikniecie
//void InterfaceWindow::STOP_PLOT()
//{
//    if(stop_wcisniety==false){
//    stop_wcisniety=true;
//    timer1->stop();
//    //qDebug() <<"STOP "<< endl;
//    }
//    else {
//        stop_wcisniety=false;
//        timer1->start();
//        //qDebug() <<"START "<< endl;
//    }
//}
//void InterfaceWindow::STOP_PLOT2()
//{
//    if (stop_wcisniety == false) {
//        stop_wcisniety = true;
//        timer3->stop();
//        //qDebug() <<"STOP "<< endl;
//    }
//    else {
//        stop_wcisniety = false;
//        timer3->start();
//        //qDebug() <<"START "<< endl;
//    }
//}

void InterfaceWindow::set_pixmap(QLabel *label, const QString &path)
{
    QPixmap pix_error(path);
    int w = label->width();
    int h = label->height();
    label->setPixmap(pix_error.scaled(w,h,Qt::KeepAspectRatioByExpanding));
}

void InterfaceWindow::set_icons()
{
    set_pixmap(ui->label_cpu,":/icons/raspberry_48.png");
   set_pixmap(ui->label_signal,":/icons/signal_48.png");
   set_pixmap(ui->label_rotation,":/icons/pitch_yaw_roll.png");
   set_pixmap(ui->label_motor_status,":/icons/engine3-50.png");
   //    QPixmap pixmap(":/icons/shutdown_48.png");
   //    QIcon ButtonIcon(pixmap);
   //    QSize iconSize(ui->pushButton->height(),ui->pushButton->height());
   //    ui->pushButton->setIcon(ButtonIcon);
   //    ui->pushButton->setIconSize(iconSize);
}
InterfaceWindow::~InterfaceWindow()
{
    delete ui;
}
//Docelowo te funckje powinny byc zastopiane danymi odbieranymi z czujnikow
void InterfaceWindow::recive_data()
{
    static char buffRec[0xFF];
//    static QTime time(QTime::currentTime());
//    double key = time.elapsed()/1000.0;
    double key = tim_elapsed.elapsed()/1000.0;
    UDPclient_getResp(buffRec, 0xFF);

    QString data = buffRec+5;
    if(!strcmp((char*)buffRec+1, "MLP"))
    {
        ui->progressBar_4->setValue(50+data.toInt()/20);
        //left motor power
        emit send_point("MLP",{key,50+data.toDouble()/20});
    }
    else if(!strcmp((char*)buffRec+1, "MRP"))
    {
        ui->progressBar_2->setValue(50+data.toInt()/20);
        emit send_point("MRP",{key,50+data.toDouble()/20});
    }
    else if(!strcmp((char*)buffRec+1, "MLD"))
    {
        ui->lineEdit_10->setText(data);
        emit send_point("MLD",{key,data.toDouble()});
    }
    else if(!strcmp((char*)buffRec+1, "MRD"))
    {
        ui->lineEdit_8->setText(data);
        emit send_point("MRD",{key,data.toDouble()});
    }
    else if(!strcmp((char*)buffRec+1, "PY"))
    {
        double value = data.toInt() / 1000.0;
        ui->lineEdit_3->setText(QString("%1").arg(value));
        emit send_point("PY",{key,value});
    }
    else if(!strcmp((char*)buffRec+1, "BV"))
    {
        ui->widget_battery->setValue(data.toInt()/10);
        emit send_point("BV",{key,data.toDouble()/10});
        //ui->widget_battery->setValue(data.toDouble()/10);
    }
    else if(!strcmp((char*)buffRec+1, "PWQ"))
    {
        ui->lineEdit_2->setText(data);
        emit send_point("PWQ",{key,data.toDouble()});
    }
    else if(!strcmp((char*)buffRec+1, "PWS"))
    {
        ui->lineEdit->setText(data);

        QString val;
        val.append(data[0]);
        val.append(data[1]);
        val.append(data[2]);
        double value = val.toInt();
        emit send_point("PWS",{key,value});
    }
    else if(!strcmp((char*)buffRec+1, "PCU"))
    {
        ui->lineEdit_13->setText(data);
        emit send_point("PCU",{key,data.toDouble()});
    }
    else if(!strcmp((char*)buffRec+1, "PCT"))
    {
        ui->lineEdit_7->setText(data);
        emit send_point("PCU",{key,data.toDouble()});
    }
}

