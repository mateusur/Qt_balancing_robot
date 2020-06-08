#ifndef PLOT_H
#define PLOT_H
/*!
* \brief Pozwala na łatwiejsze korzystanie z klasy qcustomplot.
*
* Klasa odpowiada za rysowanie odpowiednich danych na wykresie.
* Oferuje także możliwość wstrzymania rysowania wykresu (pauzy).
*/
#include <QObject>
#include <QComboBox>
#include <QMouseEvent>
#include "qcustomplot.h"
class Plot : public QObject
{
    Q_OBJECT
    /*!
    * \brief Wskaźnik na wykres.
    */
    QCustomPlot *graph;
    /*!
    * \brief Wskaźnik na liste rozwijaną.
    */
    QComboBox *box;
    /*!
    * \brief Wektory przechowujące dane telemetryczne.
    */
    QVector<QCPGraphData> LMP, RMP,MLD,MRD,PY,BV,PWQ,PWS,PCU,PCT ;
    /*!
    * \brief Wskaźnik na timer odpowiadający za częstotliwość odświeżania wykresu.
    */
    QTimer *refresh_tim;
public:
    /*!
    * \brief Konstruktor.
    */
    explicit Plot(QObject *parent = nullptr,QCustomPlot *Graph= nullptr,QComboBox *Box = nullptr);
    /*!
    * \brief Metoda ustawiająca opis osi Y.
    */
    void set_Ylabel(QString label);
    /*!
    * \brief Metoda ustawiająca opis osi X.
    */
    void set_Xlabel(QString label);

public slots:
    /*!
    * \brief Metoda odpowiadająca na dodanie punktu do odpowiedniego wektora.
    */
    void add_point(const QString &nazwa,const QCPGraphData &liczba);

private slots:
    /*!
    * \brief Metoda pozwalająca na wstrzymanie rysowania.
    */
    void stop_plotting();
    /*!
    * \brief Metoda odświeżająca wykres oraz wybranie odpowiednich danych.
    */
    void draw();
signals:

};

#endif // PLOT_H
