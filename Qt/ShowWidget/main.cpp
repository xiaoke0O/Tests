#include <QApplication>
#include <QWidget>

class mywidget : public QWidget
{
public:
    mywidget();
};

mywidget::mywidget()
{
    resize(500, 500);
    setWindowTitle(QString::fromLocal8Bit("testWindow"));
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    mywidget w;
    w.show();
    return app.exec();
}
