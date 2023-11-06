#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include<QString>
#include<QStack>
#include<QTime>
#include<iterator>
#include<QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString input = "0";

private slots:
    void on_pushButton_1_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_pushButton_0_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_equal_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_sub_clicked();

    void on_pushButton_div_clicked();

    void on_pushButton_mult_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_CE_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_mod_clicked();

    void on_pushButton_left_clicked();

    void on_pushButton_right_clicked();

    int getPriority (QChar op);

    QString getPostfixExpression(QString str);

    double postExpresionAl(QString str);

    void on_pushButton_pow_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
