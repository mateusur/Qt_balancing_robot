#ifndef CONNECTWINDOW_H
#define CONNECTWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>

namespace Ui {
class ConnectWindow;
}

class ConnectWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConnectWindow(QWidget *parent = nullptr);
    ~ConnectWindow();
private:
    /*!
    * \brief Metoda ustawiająca ikone dla etykiety.
    */
     void set_pixmap(QLabel *label,const QString &icon);
public slots:
     /*!
     * \brief Metoda ustawiająca wiele ikon dla wielu etykiet.
     */
    void set_icon(const QString &text);
private slots:
    void on_pushButton_clicked();

private:
    Ui::ConnectWindow *ui;


};

extern ConnectWindow* connectWindow;

#endif // CONNECTWINDOW_H
