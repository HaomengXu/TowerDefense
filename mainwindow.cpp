#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());//窗格大小锁定
    connect(d,SIGNAL(sendsignal()),this,SLOT(reshow()));//信号与重新显示函数连接槽
    d->setWindowTitle("TowerDefence - Resistance to disease");//标题栏
    QMediaPlayer * player = new QMediaPlayer;//全局音乐加载
    player->setMedia(QUrl("qrc:/music/sound/ToTheRescue.mp3"));
    player->setVolume(10);
    player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    d->reset();//重置
    d->show();//显示
    this->hide();//该窗格隐藏
}

void MainWindow::on_pushButton_2_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/HaomengXu/TowerDefense/releases"));//访问官网
}

void MainWindow::on_pushButton_3_clicked()
{
    this->close();//退出
}
