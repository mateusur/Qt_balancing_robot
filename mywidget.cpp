#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    timer1=new QTimer;

    connect(timer1,SIGNAL(timeout()),this,SLOT(update_degrees()));
    timer1->start(50);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QTransform transform;
    transform.translate(60,160);
    transform.rotate(0);
    transform.scale(1, 1);
    painter.setTransform(transform);

    QRect rect(-20,-120,40,100);

    QRect rect2(-20,-20,40,40);
    painter.setBrush(QColor(157,157,157));
    painter.drawEllipse(rect2);
    painter.drawPoint(rect2.center());
    painter.rotate(degrees);
    painter.setBrush(QColor(117,117,117));
    painter.drawRect(rect);
    //qDebug() << "Srodek : " << rect2.center();


    QTimer::singleShot(100,this, SLOT(update()));
}

void MyWidget::update_degrees()
{
    if(rising){
        degrees+=0.4;
        if(degrees>20) rising=false;
    }
    else{
        degrees-=0.4;
        if(degrees<-20) rising=true;
    }

}
