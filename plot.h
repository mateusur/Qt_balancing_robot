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
    * \brief Wektor przechowujący dane o mocy lewego silnika.
    */
    QVector<QCPGraphData> LMP;
    /*!
    * \brief Wektor przechowujący dane o mocy prawego silnika.
    */
    QVector<QCPGraphData> RMP;
    /*!
    * \brief Wektor przechowujący dane o enkoderze lewego silnika.
    */
    QVector<QCPGraphData> MLD;
    /*!
    * \brief Wektor przechowujący dane o enkoderze prawego silnika.
    */
    QVector<QCPGraphData> MRD;
    /*!
    * \brief Wektor przechowujący dane o kącie YAW.
    */
    QVector<QCPGraphData> PY;
    /*!
    * \brief Wektor przechowujący dane o napięciu baterii.
    */
    QVector<QCPGraphData> BV;
    /*!
    * \brief Wektor przechowujący dane o jakości połączenia.
    */
    QVector<QCPGraphData> PWQ;
    /*!
    * \brief Wektor przechowujący dane o sile połaczenia.
    */
    QVector<QCPGraphData> PWS;

    /*!
    * \brief Wskaźnik na timer odpowiadający za częstotliwość odświeżania wykresu.
    */
    QTimer *refresh_tim;
public:
    /*!
    * \brief Konstruktor.
    * \param[in] parent
    * \param[in] Graph - wskaźnik na okno wykresu.
    * \param[in] Box - wskaźnik na listę rozwijaną.
    */
    explicit Plot(QObject *parent = nullptr,QCustomPlot *Graph= nullptr,QComboBox *Box = nullptr);
    /*!
    * \brief Metoda ustawiająca opis osi Y.
    *
    * Metoda ustawiająca opis osi Y.
    * \param[in] label - nowa nazwa osi Y.
    */
    void set_Ylabel(QString label);
    /*!
    * \brief Metoda ustawiająca opis osi X.
    *
    * Metoda ustawiająca opis osi X.
    * \param[in] label - nowa nazwa osi X.
    */
    void set_Xlabel(QString label);

public slots:
    /*!
    * \brief Metoda odpowiadająca na dodanie punktu do odpowiedniego wektora.
    *
    * Metoda odpowiadająca na dodanie punktu do odpowiedniego wektora.
    * \param[in] nazwa - nazwa wektora do którego chcemy dodać punkt.
    * \param[in] liczba - para składająca się z czasu odebrania punktu oraz wartości.
    */
    void add_point(const QString &nazwa,const QCPGraphData &liczba);

private slots:
    /*!
    * \brief Metoda pozwalająca na wstrzymanie rysowania.
    *
    * Metoda pozwalająca na wstrzymanie rysowania.
    */
    void stop_plotting();
    /*!
    * \brief Metoda odświeżająca wykres oraz wybranie odpowiednich danych.
    *
    * Metoda odświeżająca wykres oraz wybranie odpowiednich danych.
    */
    void draw();
signals:

};

#endif // PLOT_H
