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
private:
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
    double degrees=0;
    /*!
    * \brief Zmienna przechowująca czy kąt rośnie.
    */
    bool rising= true;
protected:
    /*!
    * \brief Metoda rysująca robota.
    */
    void paintEvent(QPaintEvent *);

public slots:
    /*!
    * \brief Metoda odświeżająca wykres.
    *
    * Metoda odświeżająca wykres.
    * \param wartosc - kąt na jaki robot ma się wychylić.
    */

    void updatex(const double &wartosc);
private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
