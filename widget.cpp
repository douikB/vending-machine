#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    changeLCDState();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
    changeLCDState();
}

void Widget::changeLCDState()
{
    ui->pb_Reset->setEnabled(money>0);
    ui->pb_Coffee->setEnabled(money>=100);
    ui->pb_Tea->setEnabled(money>=150);
    ui->pb_Tang->setEnabled(money>=200);
}

void Widget::on_pb_Coin10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb_Coin50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb_Coin100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb_Coin500_clicked()
{
    changeMoney(500);
}

void Widget::on_pb_Coffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pb_Tea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pb_Tang_clicked()
{
    changeMoney(-200);
}


void Widget::on_pb_Reset_clicked()
{
    QMessageBox mb;

    int a, b, c, d;
    a = money / 500;
    money %= 500;
    b = money / 100;
    money %= 100;
    c = money / 50;
    money %= 50;
    d = money / 10;
    money %= 10;

    QString text = QString("500 : %1\n100 : %2\n50 : %3\n10 : %4\n").arg(a).arg(b).arg(c).arg(d);

    mb.information(nullptr, "Title", text);
    changeMoney(0);
}

