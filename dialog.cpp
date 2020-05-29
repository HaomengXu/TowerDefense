#include "dialog.h"
#include "ui_dialog.h"
#include <QDesktopServices>
#include <QUrl>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    MainWindow *w=new MainWindow();
    connect(w,SIGNAL(sendsignal()),this,SLOT(reshow()));
    w->setWindowTitle("TowerDefence");
    w->show();
    this->hide();
}

void Dialog::on_pushButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/HaomengXu/TowerDefense/releases"));
}

void Dialog::on_pushButton_3_clicked()
{
    this->close();
}
