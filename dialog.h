#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"mainwindow.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void reshow(){this->show();}

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
