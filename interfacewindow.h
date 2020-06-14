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
    * \param[in] parent
    */
    explicit InterfaceWindow(QWidget *parent = nullptr);
    ~InterfaceWindow();
    /*!
    * \brief Wskaźnik na wykres.
    */
    Plot *graph1;
    /*!
    * \brief Wskaźnik na wykres.
    */
    Plot *graph2;
    /*!
    * \brief Wskaźnik na wykres.
    */
    Plot *graph3;
public slots:
    /*!
    * \brief Metoda odbierająca dane z robota.
    */
    void recive_data();
private:
    Ui::InterfaceWindow *ui;
    /*!
    * \brief Wskaźnik na timer odpowiadający za częstotliowść odbieranych danych.
    */
    QTimer *tim_data;
    /*!
    * \brief Zmienna przechowująca czas trwania programu.
    */
    QElapsedTimer tim_elapsed;
    /*!
    * \brief Metoda ustawiająca ikone dla etykiety.
    *
    * Metoda ustawiająca ikone dla etykiety.
    * \param[in, out] label - wkaźnik na etykiete.
    * \param[in] path - string ze ścieżką do ikony.
    */
    void set_pixmap(QLabel *label, const QString &path);
    /*!
    * \brief Metoda ustawiająca wiele ikon dla wielu etykiet.
    *
    * Metoda ustawiająca wiele ikon dla wielu etykiet.
    */
    void set_icons();

signals:
    /*!
    * \brief Sygnał wysyłający punkt do odpowiedniego wykresu.
    *
    * Sygnał wysyłający punkt do odpowiedniego wykresu.
    * \param[in] name - nazwa wektora do którego jest wysyłana para.
    * \param[in] pair - para punktów - czas, wartość.
    */
    void send_point(const QString &name,const QCPGraphData &pair); //void send_point(QString,const QCPGraphData &liczba);
    void send_degrees(const double &wartosc);
    void hello(const double &wartosc);
};

extern InterfaceWindow* interfaceWindow;

#endif // INTERFACEWINDOW_H
