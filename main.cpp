#include <iostream>
#include <QtWidgets>
#include "mainwindow.h"
#include "edit_distance.h"
#include "wordbreaker.h"
using namespace std;



int main(int argc, char** argv){

    QApplication app(argc,argv);
    MainWindow w;
    w.show();
    return app.exec();

}
