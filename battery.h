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
    */
    void updateValue();

private:
    /*!
    * \brief Minimalna wartość (zakres).
    */
    double minValue;
    /*!
    * \brief Maksymalna wartość (zakres).
    */
    double maxValue;
    /*!
    * \brief Ustawiana wartość.
    */
    double value;
    /*!
    * \brief Wartość alarmowa po przekroczeniu której jest zmieniany kolor wypełnienia.
    */
    double alarmValue;
    /*!
    * \brief Wartość odpowiadająca za skok wypełnienia.
    */
    double step;
    /*!
    * \brief Promień zaokrąglenia granicy baterii.
    */
    int borderRadius;
    /*!
    * \brief Promień zaokrąglenia wypełnienia baterii.
    */
    int bgRadius;
    /*!
    * \brief Promień zaokrąglenia główki baterii.
    */
    int headRadius;
    /*!
    * \brief Początkowy kolor ramki.
    */
    QColor borderColorStart;
    /*!
    * \brief Końcowy kolor ramki.
    */
    QColor borderColorEnd;
    /*!
    * \brief Początkowy kolor alarmu.
    */
    QColor alarmColorStart;
    /*!
    * \brief Końcowy kolor alarmu.
    */
    QColor alarmColorEnd;
    /*!
    * \brief Początkowy kolor wypełnienia.
    */
    QColor normalColorStart;
    /*!
    * \brief Końcowy kolor wypełnienia.
    */
    QColor normalColorEnd;
    /*!
    * \brief Określa czy wypełnienie sie zwiększa.
    */
    bool isForward;
    /*!
    * \brief Aktualna wartość.
    */
    double currentValue;
    /*!
    * \brief Kwadrat do ramki baterii.
    */
    QRectF batteryRect;
    /*!
    * \brief Wskaźnik na timer określający częstotliwość odświeżania.
    */
    QTimer *timer;

public:
    /*!
    * \brief Metoda pobierająca minimalna wartość.
    */
    double getMinValue()            const;
    /*!
    * \brief Metoda pobierająca maksymalną wartość.
    */
    double getMaxValue()            const;
    /*!
    * \brief Metoda pobierająca wartość.
    */
    double getValue()               const;
    /*!
    * \brief Metoda pobierająca wartość alramującą.
    */
    double getAlarmValue()          const;
    /*!
    * \brief Metoda pobierająca wartość skoku.
    */
    double getStep()                const;
    /*!
    * \brief Metoda pobierająca wartość promienia ramki.
    */
    int getBorderRadius()           const;
    /*!
    * \brief Metoda pobierająca wartość promienia tła.
    */
    int getBgRadius()               const;
    /*!
    * \brief Metoda pobierająca wartość promienia główki.
    */
    int getHeadRadius()             const;
    /*!
    * \brief Metoda pobierająca kolor początkowy ramki.
    */
    QColor getBorderColorStart()    const;
    /*!
    * \brief Metoda pobierająca kolor końcowy ramki.
    */
    QColor getBorderColorEnd()      const;
    /*!
    * \brief Metoda pobierająca kolor początkowy alramu.
    */
    QColor getAlarmColorStart()     const;
    /*!
    * \brief Metoda pobierająca kolor końcowy alramu.
    */
    QColor getAlarmColorEnd()       const;
    /*!
    * \brief Metoda pobierająca kolor początkowy normalnego trybu.
    */
    QColor getNormalColorStart()    const;
    /*!
    * \brief Metoda pobierająca kolor końcowy normalnego trybu.
    */
    QColor getNormalColorEnd()      const;
    /*!
    * \brief Metoda pobierająca sugerowany rozmiar.
    */
    QSize sizeHint()                const;
    /*!
    * \brief Metoda pobierająca minimalny rozmiar.
    */
    QSize minimumSizeHint()         const;

public slots:
    /*!
    * \brief Metoda ustawiająca zakres (dla typu double).
    */
    void setRange(double minValue, double maxValue);
    /*!
    * \brief Metoda ustawiająca zakres (dla typu int).
    */
    void setRange(int minValue, int maxValue);
    /*!
    * \brief Metoda ustawiająca minimalną wartość.
    */
    void setMinValue(double minValue);
    /*!
    * \brief Metoda ustawiająca maksymalną wartość.
    */
    void setMaxValue(double maxValue);
    /*!
    * \brief Metoda ustawiająca wartość (typu double).
    */
    void setValue(double value);
    /*!
    * \brief Metoda ustawiająca wartość (typu int).
    */
    void setValue(int value);
    /*!
    * \brief Metoda ustawiająca wartość alarmującą (typu double).
    */
    void setAlarmValue(double alarmValue);
    /*!
    * \brief Metoda ustawiająca wartość alarmującą (typu int).
    */
    void setAlarmValue(int alarmValue);
    /*!
    * \brief Metoda ustawiająca wartość skoku (typu double).
    */
    void setStep(double step);
    /*!
    * \brief Metoda ustawiająca wartość skoku (typu int).
    */
    void setStep(int step);
    /*!
    * \brief Metoda ustawiająca wartość promienia ramki.
    */
    void setBorderRadius(int borderRadius);
    /*!
    * \brief Metoda ustawiająca wartość promienia tła.
    */
    void setBgRadius(int bgRadius);
    /*!
    * \brief Metoda ustawiająca wartość promienia główki baterii.
    */
    void setHeadRadius(int headRadius);
    /*!
    * \brief Metoda ustawiająca kolor początkowy ramki.
    */
    void setBorderColorStart(const QColor &borderColorStart);
    /*!
    * \brief Metoda ustawiająca kolor końcowy ramki.
    */
    void setBorderColorEnd(const QColor &borderColorEnd);
    /*!
    * \brief Metoda ustawiająca kolor początkowy alarmu.
    */
    void setAlarmColorStart(const QColor &alarmColorStart);
    /*!
    * \brief Metoda ustawiająca kolor końcowy alarmu.
    */
    void setAlarmColorEnd(const QColor &alarmColorEnd);
    /*!
    * \brief Metoda ustawiająca początkowy kolor wypełnienia.
    */
    void setNormalColorStart(const QColor &normalColorStart);
    /*!
    * \brief Metoda ustawiająca końcowy kolor wypełnienia.
    */
    void setNormalColorEnd(const QColor &normalColorEnd);

signals:
    /*!
    * \brief Sygnał zmiany wartości.
    */
    void valueChanged(double value);
};

#endif // BATTERY_H
