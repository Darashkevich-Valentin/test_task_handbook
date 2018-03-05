#include "ui/startwindow.h"
#include <QApplication>
#include <model-impl/xmlrepository.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow w;
    Repository *repo = new XMLRepository;

    w.setRepository(repo);
    w.show();



    return a.exec();
}
