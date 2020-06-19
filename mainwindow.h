#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>
#include <QUrl>
#include"dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void keyPressEvent(QKeyEvent *e){
        if(e->key()==Qt::Key_Escape||e->key()==Qt::Key_Backspace)this->close();
        else if(e->key()==Qt::Key_Enter||e->key()==Qt::Key_Return){d->reset();d->show();this->hide();}
        else QDesktopServices::openUrl(QUrl("https://github.com/HaomengXu/TowerDefense/releases"));
    }
    void reshow(){this->show();}

private:
    Ui::MainWindow *ui;
    Dialog *d=new Dialog();
};
#endif // MAINWINDOW_H
