#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QString input_year;
    QString input_benjin;
    QString input_rate;
    int flag = 0;

private slots:

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    double cal_res(QString year, QString benjin, QString rate);

    void on_pushButton_res_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
