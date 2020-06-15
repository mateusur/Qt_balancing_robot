#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QGraphicsEllipseItem>
//#include <QDebug>
#include <QtMath>

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
    *
    * Wskaźnik na timer określający częstotliwość odświeżania.
    */
    QTimer *timer1;
    /*!
    * \brief Zmienna przechowująca kąt obrotu robota.
    *
    * Zmienna przechowująca kąt obrotu robota.
    */
    double degrees=0;
    /*!
    * \brief Zmienna przechowująca czy kąt rośnie.
    *
    * Zmienna przechowująca czy kąt rośnie.
    */
    bool rising= true;
    /*!
    * \brief Zmienna przechowująca stałą do zamiany radianów na stopnie.
    *
    * Zmienna przechowująca stałą do zamiany radianów na stopnie.
    */
    const double radToDegrees = 180 / M_PI;
public:
    /*!
    * \brief Konstruktor.
    */
    explicit MyWidget(QWidget *parent = nullptr);
    ~MyWidget();


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
    * \param[in] value - kąt na jaki robot ma się wychylić.
    */
    void update_angle(const double &value);
private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
