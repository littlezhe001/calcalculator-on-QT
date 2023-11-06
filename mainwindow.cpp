#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<cstdlib>
#include<limits.h>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}


int MainWindow::getPriority (QChar op) {
    // 获得运算符优先级
    if (op == ')') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '%') return 3;
    if (op == '^') return 4;
    if (op == '(') return 5;
    return -1;
}

QString MainWindow::getPostfixExpression(QString str) {
    // 中缀表达式转后缀表达式
    QString result;
    stack<QChar> opstack;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            // 操作数之间的间隔符
            if (i && !(str[i - 1] >= '0' && str[i - 1] <= '9')
                && result.size() && result[result.size() - 1] >= '0' && result[result.size() - 1] <= '9') result += '#';

            result += str[i];
        }
        else {
            if (opstack.empty() || getPriority(str[i]) > getPriority(opstack.top())) {
                opstack.push(str[i]);
            }
            else {
                while (!opstack.empty() && opstack.top() != '(' && getPriority(str[i]) <= getPriority(opstack.top())) {
                    result += opstack.top();
                    opstack.pop();
                }
                if (str[i] == ')') opstack.pop();
                else opstack.push(str[i]);
            }
        }
    }
    // 将运算符栈剩余符号除'('外压入输出栈
    while (!opstack.empty() && opstack.top() != '(') {
        result += opstack.top();
        opstack.pop();
    }
    return result;
}

double MainWindow::postExpresionAl(QString str) {
    // 计算后缀表达式
    stack <double> numstack;
    int i = 0;
    while (i < str.size()) {
        if (str[i] == '#') {
            i++;
            continue;
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            double nums = 0;
            // 压入操作数
            while (str[i] >= '0' && str[i] <= '9') {
                nums = nums * 10 + str[i].unicode() - '0';
                i++;
            }
            numstack.push(nums);
        }
        else {
            double a = numstack.top();
            numstack.pop();
            double b = numstack.top();
            numstack.pop();
            switch (str[i].unicode()) {
            case '+':
                numstack.push(b + a);
                break;
            case '-':
                numstack.push(b - a);
                break;
            case '*':
                numstack.push(b * a);
                break;
            case '/':
                numstack.push(b / a);
                break;
            case '%':
                numstack.push(int(b) % int(a));
                break;
            case '^':
                numstack.push(pow(b,a));
            default:
                break;
            }
            i++;
        }
    }
    return numstack.top();
}




void MainWindow::on_pushButton_1_clicked()
{
    if(input == "0") input = "1";
    else input = input + "1";
    ui->lineEdit->setText(input);
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    return ;
}


void MainWindow::on_pushButton_0_clicked()
{
    if(input == "0") input = "0";
    else input = input + "0";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_2_clicked()
{
    if(input == "0") input = "2";
    else input = input + "2";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_4_clicked()
{
    if(input == "0") input = "4";
    else input = input + "4";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_5_clicked()
{
    if(input == "0") input = "5";
    else input = input + "5";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_6_clicked()
{
    if(input == "0") input = "6";
    else input = input + "6";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_7_clicked()
{
    if(input == "0") input = "7";
    else input = input + "7";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_8_clicked()
{
    if(input == "0") input = "8";
    else input = input + "8";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_9_clicked()
{
    if(input == "0") input = "9";
    else input = input + "9";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_equal_clicked()
{
    QString str = getPostfixExpression(input);
    double re = postExpresionAl(str);
    input = input.number(re);
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_add_clicked()
{
    if(input == "0") input = "+";
    else input = input + "+";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_sub_clicked()
{
    if(input == "0") input = "-";
    else input = input + "-";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_div_clicked()
{
    if(input == "0") input = "/";
    else input = input + "/";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_mult_clicked()
{
    if(input == "0") input = "*";
    else input = input + "*";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_3_clicked()
{
    if(input == "0") input = "3";
    else input = input + "3";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_CE_clicked()
{
    input = "0";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_back_clicked()
{
    input.remove(input.length()-1,1);
    if(input.isEmpty()){
        input = "0";
    }
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_mod_clicked()
{
    if(input == "0") input = "%";
    else input = input + "%";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_left_clicked()
{
    if(input == "0") input = "(";
    else input = input + "(";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_right_clicked()
{
    if(input == "0") input = ")";
    else input = input + ")";
    ui->lineEdit->setText(input);
}


void MainWindow::on_pushButton_pow_clicked()
{
    if(input == "0") input = "^";
    else input = input + "^";
    ui->lineEdit->setText(input);
}


