#ifndef INTERFACEWINDOW_H
#define INTERFACEWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QDateTime>
#include <QDebug>
#include <QTimer>
#include <QComboBox>
#include <QAbstractButton>
#include <QWidget>
#include <QMouseEvent>
#include "plot.h"
#include "mywidget.h"
#include <QElapsedTimer>
namespace Ui {
class InterfaceWindow;
}
/*!
* \brief Główne okno aplikacji wyświetlające dane telemetryczne.
*
* Główne okno aplikacji, po lewej stronie zawiera aktualne dane o kącie, statusie silników oraz przyciski pozwalające na interakcje z robotem.
* W środkowej części umieszczono wykresy.
* Po prawej stronie znajduję się wizualizacja odchylenia robota od pionu.
*/
class InterfaceWindow : public QMainWindow
{
    Q_OBJECT
    //int degrees=0;
public:
    /*!
    * \brief Konstruktor.
    */
    explicit InterfaceWindow(QWidget *parent = nullptr);
    ~InterfaceWindow();
    /*!
    * \brief Wskaźnik na wykres.
    */
    Plot *graph1, *graph2;
public slots:
//    void draw();
//    void draw2();
    /*!
    * \brief Metoda odbierająca dane z robota.
    */
    void recive_data();
//    void STOP_PLOT();
//    void STOP_PLOT2();
private:
    Ui::InterfaceWindow *ui;

//    QTimer *timer1;
    /*!
    * \brief Wskaźnik na timer odpowiadający za częstotliowść odbieranych danych.
    */
    QTimer *tim_data;
//    QTimer *timer3;
    /*!
    * \brief Zmienna przechowująca czas trwania programu.
    */
    QElapsedTimer tim_elapsed;
    //bool stop_wcisniety=false;
    /*!
    * \brief Metoda ustawiająca ikone dla etykiety.
    */
    void set_pixmap(QLabel *label, const QString &path);
    /*!
    * \brief Metoda ustawiająca wiele ikon dla wielu etykiet.
    */
    void set_icons();

signals:
    /*!
    * \brief Sygnał wysyłający punkt do odpowiedniego wykresu.
    */
    void send_point(QString,const QCPGraphData &liczba);
};

extern InterfaceWindow* interfaceWindow;

#endif // INTERFACEWINDOW_H
