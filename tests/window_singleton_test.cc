#include <QApplication>
#include <lab1/window_singleton.h>



int main(int argc,char** argv){
   QApplication a(argc, argv);
   lab1::MainWindow m("test singleton");
   m.show();
   return a.exec();
}