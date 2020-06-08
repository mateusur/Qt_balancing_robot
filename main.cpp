#include <QApplication>

#include "interfacewindow.h"
#include "connectwindow.h"

/*! \mainpage Dokumentacja aplikacji Robot balansujący - KIRA
 * \section Wprowadzenie
 * Aplikacja odbierająca dane telemetryczne z robota samobalansującego a następnie wizualizująca je na wiele sposobów.
 * \section Interface_window Główne okno
 * Główne okno aplikacji, po lewej stronie zawiera aktualne dane o kącie, statusie silników oraz przyciski pozwalające na interakcje z robotem.
 * W środkowej części umieszczono wykresy. Po prawej stronie znajduję się wizualizacja odchylenia robota od pionu. Klasa implementująca okno:\ref InterfaceWindow
 * \section Connect_window Okno łączenia
 * W oknie connect window zawarta jest implementacja narzędzi potrzebnych do połączenia się z robotem. Klasa implementująca okno:\ref ConnectWindow
 * \section Dokumentacja Dokumentacja
 * Dokumentacja została wygenerowana za pomocą aplikacji Doxygen.
 */
int main(int argc, char *argv[])
{
    qputenv("QT_AUTO_SCREEN_SCALE_FACTOR", "1");

    QApplication app(argc, argv);

    interfaceWindow = new InterfaceWindow;
    connectWindow = new ConnectWindow;

    connectWindow->show();

    return app.exec();
}
