#ifndef BATTERY_H
#define BATTERY_H
/*!
* \brief Rysuje kształt baterii.
*
* Klasa odpowiada za rysowanie odpowiedniego kształtu oraz
* ustawienie odpowiedniego koloru wypełnienia
*/
#include <QWidget>
class Battery : public QWidget
{
    Q_OBJECT    
public:
    /*!
    * \brief Konstruktor baterii.
    * \param parent
    */
    explicit Battery(QWidget *parent = 0);
    ~Battery();
protected:
    /*!
    * \brief Metoda odpowiadająca za rysowanie baterii.
    */
    void paintEvent(QPaintEvent *);
    /*!
    * \brief Metoda odpowiadająca za rysowanie granicy baterii.
    */
    void drawBorder(QPainter *painter);
    /*!
    * \brief Metoda odpowiadająca za rysowanie tła baterii.
    */
    void drawBg(QPainter *painter);
    /*!
    * \brief Metoda odpowiadająca za rysowanie główki baterii.
    */
    void drawHead(QPainter *painter);

private slots:
    /*!
    * \brief Metoda odpowiadająca za zaktualizowanie wartości.
    *
    * Metoda odpowiadająca za zaktualizowanie wartości.
    */
    void updateValue();

private:
    /*!
    * \brief Minimalna wartość (zakres).
    *
    * Minimalna wartość (zakres).
    */
    double minValue;
    /*!
    * \brief Maksymalna wartość (zakres).
    *
    * Maksymalna wartość (zakres).
    */
    double maxValue;
    /*!
    * \brief Ustawiana wartość.
    *
    * Ustawiana wartość.
    */
    double value;
    /*!
    * \brief Wartość alarmowa po przekroczeniu której jest zmieniany kolor wypełnienia.
    *
    * Wartość alarmowa po przekroczeniu której jest zmieniany kolor wypełnienia.
    */
    double alarmValue;
    /*!
    * \brief Wartość odpowiadająca za skok wypełnienia.
    *
    * Wartość odpowiadająca za skok wypełnienia.
    */
    double step;
    /*!
    * \brief Promień zaokrąglenia granicy baterii.
    *
    * Promień zaokrąglenia granicy baterii.
    */
    int borderRadius;
    /*!
    * \brief Promień zaokrąglenia wypełnienia baterii.
    *
    * Promień zaokrąglenia wypełnienia baterii.
    */
    int bgRadius;
    /*!
    * \brief Promień zaokrąglenia główki baterii.
    *
    * Promień zaokrąglenia główki baterii.
    */
    int headRadius;
    /*!
    * \brief Początkowy kolor ramki.
    *
    * Początkowy kolor ramki.
    */
    QColor borderColorStart;
    /*!
    * \brief Końcowy kolor ramki.
    *
    * Końcowy kolor ramki.
    */
    QColor borderColorEnd;
    /*!
    * \brief Początkowy kolor alarmu.
    *
    * Początkowy kolor alarmu.
    */
    QColor alarmColorStart;
    /*!
    * \brief Końcowy kolor alarmu.
    *
    * Końcowy kolor alarmu.
    */
    QColor alarmColorEnd;
    /*!
    * \brief Początkowy kolor wypełnienia.
    *
    * Początkowy kolor wypełnienia.
    */
    QColor normalColorStart;
    /*!
    * \brief Końcowy kolor wypełnienia.
    *
    * Końcowy kolor wypełnienia.
    */
    QColor normalColorEnd;
    /*!
    * \brief Określa czy wypełnienie sie zwiększa.
    *
    * Określa czy wypełnienie sie zwiększa.
    */
    bool isForward;
    /*!
    * \brief Aktualna wartość.
    *
    * Aktualna wartość.
    */
    double currentValue;
    /*!
    * \brief Kwadrat do ramki baterii.
    *
    * Kwadrat do ramki baterii.
    */
    QRectF batteryRect;
    /*!
    * \brief Wskaźnik na timer określający częstotliwość odświeżania.
    *
    * Wskaźnik na timer określający częstotliwość odświeżania.
    */
    QTimer *timer;

public:
    /*!
    * \brief Metoda pobierająca minimalna wartość.
    *
    * Metoda pobierająca minimalna wartość.
    * \return Minimalna wartość.
    */
    double getMinValue()            const;
    /*!
    * \brief Metoda pobierająca maksymalną wartość.
    *
    * Metoda pobierająca maksymalną wartość.
    * \return Maksymalna wartość.
    */
    double getMaxValue()            const;
    /*!
    * \brief Metoda pobierająca wartość.
    *
    * Metoda pobierająca wartość.
    * \return Aktualna wartość.
    */
    double getValue()               const;
    /*!
    * \brief Metoda pobierająca wartość alramującą.
    *
    * Metoda pobierająca wartość alramującą.
    * \return Wartość alarmująca.
    */
    double getAlarmValue()          const;
    /*!
    * \brief Metoda pobierająca wartość skoku.
    *
    * Metoda pobierająca wartość skoku.
    * \return Wartość skosku.
    */
    double getStep()                const;
    /*!
    * \brief Metoda pobierająca wartość promienia ramki.
    *
    * Metoda pobierająca wartość promienia ramki.
    * \return Wartość promienia obramowania.
    */
    int getBorderRadius()           const;
    /*!
    * \brief Metoda pobierająca wartość promienia tła.
    *
    * Metoda pobierająca wartość promienia tła.
    * \return Wartość promienia tła.
    */
    int getBgRadius()               const;
    /*!
    * \brief Metoda pobierająca wartość promienia główki baterii.
    *
    * Metoda pobierająca wartość promienia główki baterii.
    * \return Wartość promienia główki baterii.
    */
    int getHeadRadius()             const;
    /*!
    * \brief Metoda pobierająca kolor początkowy ramki.
    *
    * Metoda pobierająca kolor początkowy ramki.
    * \return Kolor początkowy obramowania.
    */
    QColor getBorderColorStart()    const;
    /*!
    * \brief Metoda pobierająca kolor końcowy ramki.
    *
    * Metoda pobierająca kolor końcowy ramki.
    * \return Kolor końcowy obramowania.
    */
    QColor getBorderColorEnd()      const;
    /*!
    * \brief Metoda pobierająca kolor początkowy alramu.
    *
    * Metoda pobierająca kolor początkowy alramu.
    * \return Kolor początkowy alarmu.
    */
    QColor getAlarmColorStart()     const;
    /*!
    * \brief Metoda pobierająca kolor końcowy alramu.
    *
    * Metoda pobierająca kolor końcowy alramu.
    * \return Kolor końcowy alarmu.
    */
    QColor getAlarmColorEnd()       const;
    /*!
    * \brief Metoda pobierająca kolor początkowy normalnego trybu.
    *
    * Metoda pobierająca kolor początkowy normalnego trybu.
    * \return Kolor początkowy normalnego stanu.
    */
    QColor getNormalColorStart()    const;
    /*!
    * \brief Metoda pobierająca kolor końcowy normalnego trybu.
    *
    * Metoda pobierająca kolor końcowy normalnego trybu.
    * \return Kolor końcowy normalnego stanu.
    */
    QColor getNormalColorEnd()      const;
    /*!
    * \brief Metoda pobierająca sugerowany rozmiar.
    *
    * Metoda pobierająca sugerowany rozmiar.
    * \return Sugerowany rozmiar.
    */
    QSize sizeHint()                const;
    /*!
    * \brief Metoda pobierająca minimalny rozmiar.
    *
    * Metoda pobierająca minimalny rozmiar.
    * \return minimalny rozmiar.
    */
    QSize minimumSizeHint()         const;

public slots:
    /*!
    * \brief Metoda ustawiająca zakres (dla typu double).
    *
    * Metoda ustawiająca zakres (dla typu double).
    * \param minValue - minimalna wartość.
    * \param maxValue - maksymalna wartość.
    */
    void setRange(double minValue, double maxValue);
    /*!
    * \brief Metoda ustawiająca zakres (dla typu int).
    *
    * Metoda ustawiająca zakres (dla typu int).
    * \param minValue - minimalna wartość.
    * \param maxValue - maksymalna wartość.
    */
    void setRange(int minValue, int maxValue);
    /*!
    * \brief Metoda ustawiająca minimalną wartość.
    *
    * Metoda ustawiająca minimalną wartość.
    * \param minValue - minimalna wartość.
    */
    void setMinValue(double minValue);
    /*!
    * \brief Metoda ustawiająca maksymalną wartość.
    *
    * Metoda ustawiająca maksymalną wartość.
    * \param maxValue - maksymalna wartość.
    */
    void setMaxValue(double maxValue);
    /*!
    * \brief Metoda ustawiająca wartość (typu double).
    *
    * Metoda ustawiająca wartość (typu double).
    * \param value - aktualna wartość.
    */
    void setValue(double value);
    /*!
    * \brief Metoda ustawiająca wartość (typu int).
    *
    * Metoda ustawiająca wartość (typu int).
    * \param value - aktualna wartość.
    */
    void setValue(int value);
    /*!
    * \brief Metoda ustawiająca wartość alarmującą (typu double).
    *
    * Metoda ustawiająca wartość alarmującą (typu double).
    * \param alarmValue - alarmująca wartość.
    */
    void setAlarmValue(double alarmValue);
    /*!
    * \brief Metoda ustawiająca wartość alarmującą (typu int).
    *
    * Metoda ustawiająca wartość alarmującą (typu int).
    * \param alarmValue - alarmująca wartość.
    */
    void setAlarmValue(int alarmValue);
    /*!
    * \brief Metoda ustawiająca wartość skoku (typu double).
    *
    * Metoda ustawiająca wartość skoku (typu double).
    * \param step - wartość skoku.
    */
    void setStep(double step);
    /*!
    * \brief Metoda ustawiająca wartość skoku (typu int).
    *
    * Metoda ustawiająca wartość skoku (typu int).
    * \param step - wartość skoku.
    */
    void setStep(int step);
    /*!
    * \brief Metoda ustawiająca wartość promienia ramki.
    *
    * Metoda ustawiająca wartość promienia ramki.
    * \param borderRadius - wartość promienia ramki.
    */
    void setBorderRadius(int borderRadius);
    /*!
    * \brief Metoda ustawiająca wartość promienia tła.
    *
    * Metoda ustawiająca wartość promienia tła.
    * \param bgRadius - wartość promienia tła.
    */
    void setBgRadius(int bgRadius);
    /*!
    * \brief Metoda ustawiająca wartość promienia główki baterii.
    *
    * Metoda ustawiająca wartość promienia główki baterii.
    * \param headRadius - wartość promienia główki baterii.
    */
    void setHeadRadius(int headRadius);
    /*!
    * \brief Metoda ustawiająca kolor początkowy ramki.
    *
    * Metoda ustawiająca kolor początkowy ramki.
    * \param borderColorStart - kolor początkowy ramki.
    */
    void setBorderColorStart(const QColor &borderColorStart);
    /*!
    * \brief Metoda ustawiająca kolor końcowy ramki.
    *
    * Metoda ustawiająca kolor końcowy ramki.
    * \param borderColorEnd - kolor końcowy ramki.
    */
    void setBorderColorEnd(const QColor &borderColorEnd);
    /*!
    * \brief Metoda ustawiająca kolor początkowy alarmu.
    *
    * Metoda ustawiająca kolor początkowy alarmu.
    * \param alarmColorStart - kolor początkowy alarmu.
    */
    void setAlarmColorStart(const QColor &alarmColorStart);
    /*!
    * \brief Metoda ustawiająca kolor końcowy alarmu.
    *
    * Metoda ustawiająca kolor końcowy alarmu.
    * \param alarmColorEnd - kolor końcowy alarmu.
    */
    void setAlarmColorEnd(const QColor &alarmColorEnd);
    /*!
    * \brief Metoda ustawiająca początkowy kolor wypełnienia.
    *
    * Metoda ustawiająca początkowy kolor wypełnienia.
    * \param normalColorStart - kolor początkowy wypełnienia.
    */
    void setNormalColorStart(const QColor &normalColorStart);
    /*!
    * \brief Metoda ustawiająca końcowy kolor wypełnienia.
    *
    * Metoda ustawiająca końcowy kolor wypełnienia.
    * \param normalColorEnd - kolor końcowy wypełnienia.
    */
    void setNormalColorEnd(const QColor &normalColorEnd);

signals:
    /*!
    * \brief Sygnał zmiany wartości.
    *
    * Sygnał zmiany wartości.
    * \param value - aktualna wartość naładowania.
    */
    void valueChanged(double value);
};

#endif // BATTERY_H
