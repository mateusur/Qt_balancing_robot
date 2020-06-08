#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QGraphicsEllipseItem>
//#include <QDebug>

namespace Ui {

class MyWidget;
}
/*!
* \brief Pozwala na prostą animacje robota.
*
* Klasa odpowiada za rysowanie prostej animacji robota na podstawie odebranego kąta.
*/
class MyWidget : public QWidget
{
    Q_OBJECT
    /*!
    * \brief Wskaźnik na timer określający częstotliwość odświeżania.
    */
    QTimer *timer1;
public:
    /*!
    * \brief Konstruktor.
    */
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();
    /*!
    * \brief Zmienna przechowująca kąt obrotu robota.
    */
    float degrees=0;
    /*!
    * \brief Zmienna przechowująca czy kąt rośnie.
    */
    bool rising= true;
protected:
    /*!
    * \brief Metoda rysująca robota.
    */
    void paintEvent(QPaintEvent *);
//    void paintEvent(QPaintEvent * event){
//            QRect rect(0,0,40,100);
//            QPainter painter(this);
//            painter.translate(60,100);
//            //painter.drawRect(rect);
//            //static qreal degree=0;
//            painter.rotate(degrees);
//            painter.translate(-rect.width()/2,-rect.height()/2);
//            painter.setBrush(QColor(255, 0, 0, 127));
//            painter.drawRect(rect);
//            painter.drawPoint(rect.center());
//            //qDebug() << "Lewy dol: " << rect.bottomLeft() << " Prawy dol: " << rect.bottomRight();
//            QRect rect2(-20,50,40,40);
//            QPainter painter2(this);
//            painter2.setBrush(QColor(0, 0, 255, 127));
//            painter2.translate(60,100);
//            painter2.rotate(degrees);
//            //painter2.translate(-rect2.width()/2,-rect2.height()/2);
//            painter2.drawEllipse(rect2);
//            painter2.drawPoint(rect2.center());
//            QTimer::singleShot(100,this, SLOT(update()));
//        }

private slots:
    /*!
    * \brief Metoda odświeżająca wykres.
    */
    void update_degrees();
private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
