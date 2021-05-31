
#include "Ui/MainWindow.h"
#include <QApplication>
#include <qsharedmemory.h>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    QSharedMemory shared("AdoraPlayer");

    if (shared.create(512, QSharedMemory::ReadWrite) == false) {

        exit(0);
    }

    MainWindow w;
    w.show();
    return a.exec();
}
