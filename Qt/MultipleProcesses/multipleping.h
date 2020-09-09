#ifndef MULTIPLEPING_H
#define MULTIPLEPING_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MultiplePing; }
QT_END_NAMESPACE

class MultiplePing : public QWidget
{
    Q_OBJECT

public:
    explicit MultiplePing(QWidget *parent = nullptr);
    ~MultiplePing() override;

private:
    Ui::MultiplePing *ui;

private slots:
    void startPing();
};
#endif // MULTIPLEPING_H
