#include "dialog.h"
#include "ui_dialog.h"
#include<cmath>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_radioButton_clicked()
{
    flag = 0;
}


void Dialog::on_radioButton_2_clicked()
{
    flag = 1;
}

double Dialog::cal_res(QString year, QString benjin, QString rate){
    double y = year.toDouble();
    double bj = benjin.toDouble();
    double r = rate.toDouble();
    switch (flag) {
    case 0:
        return pow((1+r),y)*bj;
    case 1:
        return (1+r*y)*bj;
    }
    return 0;
}





void Dialog::on_pushButton_res_clicked()
{
    // 获取三个QLineEdit的文本内容
    QString yearText = ui->lineEdit_year->text();
    QString benjinText = ui->lineEdit_money->text();
    QString rateText = ui->lineEdit_rate->text();

    // 调用cal_res函数进行计算
    double result = cal_res(yearText, benjinText, rateText);
    QString outpu = QString::number(result);
    ui->lineEdit_total->setText(outpu);
}

