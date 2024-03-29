#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money=0;
    void changeMoney(int diff);
    void changeLCDState();

private slots:
    void on_pb_Coin10_clicked();

    void on_pb_Coin100_clicked();

    void on_pb_Coin500_clicked();

    void on_pb_Coin50_clicked();

    void on_pb_Coffee_clicked();

    void on_pb_Tea_clicked();

    void on_pb_Tang_clicked();

    void on_pb_Reset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
