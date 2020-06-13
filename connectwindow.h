#ifndef CONNECTWINDOW_H
#define CONNECTWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>

namespace Ui {
class ConnectWindow;
}
/*!
* \brief Okno służące do łączenia z robotem.
*
* Okno służące do nawiązywania połączenia z robotem.
*/
class ConnectWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
    * \brief Konstruktor.
    *
    * \param[in] parent.
    */
    explicit ConnectWindow(QWidget *parent = nullptr);
    ~ConnectWindow();
private:
    /*!
    * \brief Metoda ustawiająca ikone dla etykiety.
    *
    * Metoda ustawiająca ikone dla etykiety.
    * \param[in] label - wkaźnik na etykiete.
    * \param[in] icon - string ze ścieżką do ikony.
    */
     void set_pixmap(QLabel *label,const QString &icon);
public slots:
     /*!
     * \brief Metoda ustawiająca wiele ikon dla wielu etykiet.
     *
     * Metoda ustawiająca wiele ikon dla wielu etykiet.
     * \param[in] text - string aktualnie wpisany w okna łączenia.
     */
    void set_icon(const QString &text);
private slots:
    /*!
    * \brief Metoda nawiązująca połączenie z robotem.
    *
    * Metoda nawiązująca połączenie z robotem.
    */
    void on_pushButton_clicked();

private:
    Ui::ConnectWindow *ui;


};

extern ConnectWindow* connectWindow;

#endif // CONNECTWINDOW_H
