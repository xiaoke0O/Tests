#include "multipleping.h"

#include <QApplication>
#include<QTranslator>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //!检测本机Locale,安装对应语言
    auto *getpmtt = new QTranslator(&a);
    getpmtt->load(QLocale::system(), "MultipleProcesses", "_", ":/i18n");
    QApplication::installTranslator(getpmtt);

    MultiplePing w;
    w.show();
    return QApplication::exec();
}
