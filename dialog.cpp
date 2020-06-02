#include "dialog.h"
#include "ui_dialog.h"
#include <QTimer>
#include <QMediaPlayer>
#include <QMouseEvent>
//#include <QMessageBox>
#include <iostream>
using namespace std;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->width(),this->height());//窗格大小锁定
    //全部音效加载
    appear.setVolume(30);
    appear.setMedia(QUrl("qrc:/music/sound/appear.mp3"));
    setow.setVolume(30);
    setow.setMedia(QUrl("qrc:/music/sound/setTower.mp3"));
    levelup.setVolume(30);
    levelup.setMedia(QUrl("qrc:/music/sound/levelUP.mp3"));
    del.setVolume(30);
    del.setMedia(QUrl("qrc:/music/sound/delete.mp3"));
    attack1.setVolume(30);
    attack1.setMedia(QUrl("qrc:/music/sound/attack1.mp3"));
    attack2.setVolume(30);
    attack2.setMedia(QUrl("qrc:/music/sound/attack2.mp3"));
    attack3.setVolume(30);
    attack3.setMedia(QUrl("qrc:/music/sound/attack3.mp3"));
    die1.setVolume(20);
    die1.setMedia(QUrl("qrc:/music/sound/die1.mp3"));
    die2.setVolume(20);
    die2.setMedia(QUrl("qrc:/music/sound/die2.mp3"));
    die3.setVolume(20);
    die3.setMedia(QUrl("qrc:/music/sound/die3.mp3"));
    die4.setVolume(20);
    die4.setMedia(QUrl("qrc:/music/sound/die4.mp3"));
    crash.setVolume(50);
    crash.setMedia(QUrl("qrc:/music/sound/Crash.mp3"));
    trash.setVolume(40);
    trash.setMedia(QUrl("qrc:/music/sound/trash.mp3"));
    //新建一批障碍物
    Point p(140,280);
    Stone s1(p);stone.push_back(s1);
    p.setX(280);p.setY(210);
    Stone s2(p);stone.push_back(s2);
    p.setX(490);p.setY(210);
    Stone s3(p);stone.push_back(s3);
    p.setX(630);p.setY(280);
    Stone s4(p);stone.push_back(s4);
    p.setX(350);p.setY(350);
    Stone s5(p);stone.push_back(s5);

    timer0 = new QTimer(this);
    connect(timer0,SIGNAL(timeout()),this,SLOT(moveArmy()));//全局时间槽
    timer0->start(10);//10ms
}

Dialog::~Dialog()
{
    delete ui;
    delete timer0;
}

void Dialog::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QBrush brush(QColor(255, 255, 255), Qt::Dense2Pattern);

    if(enemy[0].getLife()<=0){gameOver(painter);gameover=1;}//失败
    else if(enemy[0].getMap()==2&&wavenum==3){gameWin(painter);gameover=1;}//赢
    else{
        if(enemy[0].getMap()==1)painter.drawPixmap(rect(), QPixmap("://image/map.jpg"));
        else painter.drawPixmap(rect(), QPixmap("://image/map2.jpg"));
        time0++;
        //敌人和塔
        painter.setPen(QPen(Qt::white,4));
        for(auto it=stone.begin();it!=stone.end();){
            if(it->getAct()==0){stone.erase(it);}
            else {it->show(painter);
                if(it->getAct()==0)trash.play();
                it++;}
        }
        for(auto it=enemy.begin();it!=enemy.end();){
            if(it->getAct()==0){enemy.erase(it);virusnum[0]--;time0-=50;}//得逞的敌人清除
            else {it->show(painter);//敌人显示
                if(it->getAct()==0)crash.play();//掉命预警
                it++;}
        }
        for(auto it=enemy2.begin();it!=enemy2.end();){
            if(it->getAct()==0){enemy2.erase(it);virusnum[1]--;time0-=50;}
            else {it->show(painter);
                if(it->getAct()==0)crash.play();
                it++;}
        }
        for(auto it=enemy3.begin();it!=enemy3.end();){
            if(it->getAct()==0){enemy3.erase(it);virusnum[2]--;time0-=100;}
            else {it->show(painter);
                if(it->getAct()==0)crash.play();
                it++;}
        }
        for(auto it=enemy4.begin();it!=enemy4.end();){
            if(it->getAct()==0){enemy4.erase(it);virusnum[3]--;time0-=200;}
            else {it->show(painter);
                if(it->getAct()==0)crash.play();
                it++;}
        }
        if(time0%30<15)towerpic.load("://image/LevelUp.png");//提示升级图片加载
        else towerpic.load("://image/LevelUp2.png");
        for(auto it=tower2.begin();it!=tower2.end();++it){
            it->show(painter);
            if(coins>=it->getMoney()&&it->getLevel()<3)//提示升级图片显示
                painter.drawImage(it->getCoor().getX()+20,it->getCoor().getY()-15, towerpic);
        }
        for(auto it=tower3.begin();it!=tower3.end();++it){
            it->show(painter);
            if(coins>=it->getMoney()&&it->getLevel()<3)
                painter.drawImage(it->getCoor().getX()+20,it->getCoor().getY()-15, towerpic);
        }
        for(auto it=tower.begin();it!=tower.end();++it){
            it->show(painter);
            if(coins>=it->getMoney()&&it->getLevel()<3)
                painter.drawImage(it->getCoor().getX()+20,it->getCoor().getY()-15, towerpic);
        }
        //选择建立新塔
        int _x=p_click.getX(),_y=p_click.getY();
        if(_x>=0){
            painter.setPen(QPen(Qt::white,4));
            brush.setColor(Qt::lightGray);
            painter.setBrush(brush);
            painter.drawRoundedRect(_x+5,_y+5,60,60,20,20);//建塔位置显示
            painter.drawLine(_x+35,_y+30,_x+35,_y+40);
            painter.drawLine(_x+30,_y+35,_x+40,_y+35);
            int x_gain=-70;//考虑到点击边缘处建塔时三种标志的位置有所改变，设置了x增益
            if(_x==0)x_gain=0;
            else if(_x==770)x_gain=-140;
            if(coins>=100)brush.setColor(Qt::darkGreen);//第一种塔
            else brush.setColor(Qt::darkRed);
            painter.setBrush(brush);//底色
            painter.drawRoundedRect(_x+x_gain+3,_y+70+3,70-6,70-6,15,15);
            towerpic.load("://image/injection.png");//塔标
            painter.drawImage(_x+x_gain,_y+70, towerpic);
            if(coins>=120)brush.setColor(Qt::darkGreen);//第二种塔
            else brush.setColor(Qt::darkRed);
            painter.setBrush(brush);
            painter.drawRoundedRect(_x+x_gain+70+3,_y+70+3,70-6,70-6,15,15);
            towerpic.load("://image/facemask.png");
            painter.drawImage(_x+x_gain+70,_y+70, towerpic);
            if(coins>=150)brush.setColor(Qt::darkGreen);//第三种塔
            else brush.setColor(Qt::darkRed);
            painter.setBrush(brush);
            painter.drawRoundedRect(_x+x_gain+140+3,_y+70+3,70-6,70-6,15,15);
            towerpic.load("://image/doctor.png");
            painter.drawImage(_x+x_gain+140,_y+70, towerpic);
        }
        //数据显示
        /*painter.setPen(QPen(Qt::white,4));brush.setColor(Qt::black);painter.setBrush(brush);
        if(_x>0){painter.drawEllipse(_x-5,_y-5,10,10);}*/
        ui->label->setText(QString::number(coins));//金币数
        //+" ; "+QString::number(_x)+" , "+QString::number(_y)
        ui->label_2->setText("  "+QString::number(enemy[0].getLife()));//生命数
        ui->label_3->setText("第 "+QString::number(wavenum+1)+" / 3 波病毒");//敌人波数
    }
    //for(int i=0;i<15;i++){painter.drawLine(70*i,0,70*i,700);painter.drawLine(0,70*i,1000,70*i);}
}

void Dialog::mousePressEvent(QMouseEvent *event){
    if(gameover){emit sendsignal();this->close();}
    int x = event->x(),y = event->y();
    int mx=floor((double)x/70)*70,my=floor((double)y/70)*70;//格点取整操作
    //已建塔的维护
    int judge=1,jud=1;
    if(buttonCover==0){//没有建塔的操作时
        for(auto it=tower.begin();it!=tower.end();++it){
            if((int)it->getCoor().getX()==mx&&(int)it->getCoor().getY()==my){
                if(event->button()==Qt::LeftButton){
                    if(it->getLevel()<3&&coins>=it->getMoney()){//升级，下同
                        coins-=it->getMoney();
                        it->LevelUp();
                        levelup.play();
                    }
                }else if(event->button()==Qt::RightButton){//拆塔，下同
                    if(it->getLevel()==1)coins+=it->getMoney()*0.8;
                    else if(it->getLevel()==2)coins+=it->getMoney()*1.0;
                    else if(it->getLevel()==3)coins+=it->getMoney()*1.1;
                    tower.erase(it);
                    del.play();
                }
                judge=0;break;
            }
        }
        if(judge)for(auto it=tower2.begin();it!=tower2.end();++it){
            if((int)it->getCoor().getX()==mx&&(int)it->getCoor().getY()==my){
                if(event->button()==Qt::LeftButton){
                    if(it->getLevel()<3&&coins>=it->getMoney()){
                        coins-=it->getMoney();
                        it->LevelUp();
                        levelup.play();
                    }
                }else if(event->button()==Qt::RightButton){
                    if(it->getLevel()==1)coins+=it->getMoney()*0.8;
                    else if(it->getLevel()==2)coins+=it->getMoney()*1.0;
                    else if(it->getLevel()==3)coins+=it->getMoney()*1.0;
                    tower2.erase(it);
                    del.play();
                }
                judge=0;break;
            }
        }
        if(judge)for(auto it=tower3.begin();it!=tower3.end();++it){
            if((int)it->getCoor().getX()==mx&&(int)it->getCoor().getY()==my){
                if(event->button()==Qt::LeftButton){
                    if(it->getLevel()<3&&coins>=it->getMoney()){
                        coins-=it->getMoney();
                        it->LevelUp();
                        levelup.play();
                    }
                }else if(event->button()==Qt::RightButton){
                    if(it->getLevel()==1)coins+=it->getMoney()*0.7;
                    else if(it->getLevel()==2)coins+=it->getMoney()*0.9;
                    else if(it->getLevel()==3)coins+=it->getMoney()*0.9;
                    tower3.erase(it);
                    del.play();
                }
                judge=0;break;
            }
        }
    }
    //建立新塔
    if(judge){//judge判断此处是否有塔
        if(p_click.getX()<0){
            if(enemy[0].getMap()==1){//分地图来看
                for(int i=0;i<map.getLenth();i++)
                    if(mx==map.getRoad(i,0)*70&&my==map.getRoad(i,1)*70){jud=0;break;}
            }else{
                for(int i=0;i<map2.getLenth();i++)
                    if(mx==map2.getRoad(i,0)*70&&my==map2.getRoad(i,1)*70){jud=0;break;}
            }
            for(auto it=stone.begin();it!=stone.end();it++)//判断此处是否有障碍
                if(mx==it->getCoor().getX()&&my==it->getCoor().getY()){it->setTar();jud=0;break;}
            if(jud&&my>0&&my<490){p_click.setX(mx);p_click.setY(my);buttonCover=1;}//jud判断是否在敌人的进攻路线上
        }
        else{
            int _x=p_click.getX(),_y=p_click.getY();
            if(_y+70==my){
                if((_x>0&&_x<770&&_x-70==mx)||(_x==0&&_x==mx)||(_x==770&&_x-140==mx)){
                    if(coins>=100){
                        Tower t;
                        t.setCoor(p_click);
                        coins-=t.getMoney();
                        t.LevelUp();//上一行先扣钱，再初始化为1级
                        tower.push_back(t);
                        setow.play();
                    }
                }else if((_x>0&&_x<770&&_x==mx)||(_x==0&&_x+70==mx)||(_x==770&&_x-70==mx)){
                    if(coins>=120){
                        Tower2 t2;
                        t2.setCoor(p_click);
                        coins-=t2.getMoney();
                        t2.LevelUp();
                        tower2.push_back(t2);
                        setow.play();
                    }
                }
                else if((_x>0&&_x<770&&_x+70==mx)||(_x==0&&_x+140==mx)||(_x==770&&_x==mx)){
                    if(coins>=150){
                        Tower3 t3;
                        t3.setCoor(p_click);
                        coins-=t3.getMoney();
                        t3.LevelUp();
                        tower3.push_back(t3);
                        setow.play();
                    }
                }
            }
            if(_x!=mx||_y!=my){p_click.setX(-1);p_click.setY(-1);buttonCover=0;}
        }
    }
}

bool comp(Enemy & e1,Enemy & e2){//排序比较函数
    return e1.getTime()>e2.getTime();
}

void Dialog::moveArmy()
{
    if(gameover==1){this->repaint();return;}
    //刷新敌人
    if(enemy.count()<virusnum[0]&&time0>=50*enemy.count()+500){//新建敌人
        Enemy e;
        enemy.push_back(e);
        appear.play();
    }
    sort(enemy.begin(),enemy.end(),comp);//位置排序，明确先攻击谁
    if(enemy2.count()<virusnum[1]&&time0>=100*enemy2.count()+50*virusnum[0]+500){
        Enemy2 e2;
        enemy2.push_back(e2);
        appear.play();
    }
    sort(enemy2.begin(),enemy2.end(),comp);
    if(enemy3.count()<virusnum[2]&&time0>=150*enemy3.count()+50*virusnum[0]+100*virusnum[1]+500){
        Enemy3 e3;
        enemy3.push_back(e3);
        appear.play();
    }
    sort(enemy3.begin(),enemy3.end(),comp);
    if(enemy4.count()<virusnum[3]&&time0>=500+250*enemy4.count()+50*virusnum[0]+100*virusnum[1]+150*virusnum[2]+500){
        Enemy4 e4;
        enemy4.push_back(e4);
        appear.play();
    }
    sort(enemy4.begin(),enemy4.end(),comp);

    if(!enemy.count()&&!enemy2.count()&&!enemy3.count()&&!enemy4.count()
            &&time0>500+250*virusnum[3]+50*virusnum[0]+100*virusnum[1]+150*virusnum[2]+500){//全部歼灭
        time0=0;wavenum++;//新一轮敌人
        if(enemy[0].getMap()==1&&wavenum==3){//更换地图
            enemy[0].setMap(2);wavenum=0;
            coins+=500;
            ui->label_2->setGeometry(ui->label_2->x(),360,
                                     ui->label_2->height(),ui->label_2->width());//肺部生命值的位置改变
            tower.clear();tower2.clear();tower3.clear();stone.clear();

            Point p(140,280);//新建一批障碍物
            Stone s1(p);stone.push_back(s1);
            p.setX(280);p.setY(210);
            Stone s2(p);stone.push_back(s2);
            p.setX(490);p.setY(210);
            Stone s3(p);stone.push_back(s3);
            p.setX(630);p.setY(210);
            Stone s4(p);stone.push_back(s4);
            p.setX(350);p.setY(350);
            Stone s5(p);stone.push_back(s5);

            virussum[0]=5;virussum[1]=8;virussum[2]=5;virussum[3]=1;
        }
        //难度加大，攻击方式弱AI改变
        virussum[0]+=tower.count();virussum[1]+=tower.count()/2+tower2.count();
        virussum[2]+=tower2.count()/2+tower3.count();virussum[3]++;
        if(virusnum[0]>=10){virusnum[0]-=5;virussum[2]+=2;}
        if(tower.count()+tower2.count()+tower3.count()>=10){virussum[2]+=2;virussum[3]++;}
        //数量复位
        virusnum[0]=virussum[0];
        virusnum[1]=virussum[1];
        virusnum[2]=virussum[2];
        virusnum[3]=virussum[3];
    }
    //塔发射子弹的判断和设置子弹位置
    for(auto it=tower.begin();it!=tower.end();++it){//遍历塔1，下同
        bool attacked=0;
        for(auto ta=stone.begin();ta!=stone.end();++ta)if(ta->getTar()){//当障碍物为目标时
            int a=it->Attack(ta->getCoor());
            if(a==1)attack1.play();
            else if(a==3){
                ta->reduceHP(it->getAttack());
                if(ta->getAct()==0){coins+=ta->getMoney();trash.play();}
            }
            if(a!=0){attacked=1;break;}
        }
        if(!attacked&&enemy2.begin()->getTime()>=enemy.begin()->getTime()-150)//确定先攻击哪种敌人
          for(auto ta=enemy2.begin();ta!=enemy2.end();++ta){//遍历敌人2，下同
            int a=it->Attack(ta->getCoor());//攻击状态确认
            if(a==1)attack1.play();
            else if(a==3){
                ta->reduceHP(it->getAttack());//敌人减血
                if(ta->getAct()==0){coins+=ta->getMoney();die2.play();}//杀敌奖励金币
            }
            if(a!=0){attacked=1;break;}//确认攻击对象后弹出
        }
        if(!attacked)for(auto ta=enemy.begin();ta!=enemy.end();++ta){
            int a=it->Attack(ta->getCoor());
            if(a==1)attack1.play();
            else if(a==3){
                ta->reduceHP(it->getAttack());
                if(ta->getAct()==0){coins+=ta->getMoney();die1.play();}
            }
            if(a!=0){attacked=1;break;}
        }
        if(!attacked)for(auto ta=enemy3.begin();ta!=enemy3.end();++ta){
            int a=it->Attack(ta->getCoor());
            if(a==1)attack1.play();
            else if(a==3){
                ta->reduceHP(it->getAttack());
                if(ta->getAct()==0){coins+=ta->getMoney();die3.play();}
            }
            if(a!=0){attacked=1;break;}
        }
        if(!attacked)for(auto ta=enemy4.begin();ta!=enemy4.end();++ta){
            int a=it->Attack(ta->getCoor());
            if(a==1)attack1.play();
            else if(a==3){
                ta->reduceHP(it->getAttack());
                if(ta->getAct()==0){coins+=ta->getMoney();die4.play();}
            }
            if(a!=0){attacked=1;break;}
        }
        if(!attacked)it->resetPoint();
    }
    for(auto it=tower2.begin();it!=tower2.end();++it){
        bool attacked=0;
        for(auto ta=stone.begin();ta!=stone.end();++ta)if(ta->getTar()){
            int a=it->Attack(ta->getCoor());
            if(a==1)attack1.play();
            else if(a==3){
                ta->reduceHP(it->getAttack());
                if(ta->getAct()==0){coins+=ta->getMoney();trash.play();}
            }
            if(a!=0){attacked=1;break;}
        }
        if(!attacked)for(auto ta=enemy2.begin();ta!=enemy2.end();++ta){
            int a=it->Attack(ta->getCoor());
            if(a==1)attack2.play();
            else if(a==3){
                ta->slowSpeed(it->getLevel());//减速算法
                ta->reduceHP(it->getAttack());
                if(ta->getAct()==0){coins+=ta->getMoney();die2.play();}
            }
            if(a!=0){attacked=1;break;}
            else if(it->reSpeedjud(ta->getCoor())==1)ta->reSpeed();//敌人出攻击圈时速度恢复
        }
        if(!attacked)for(auto ta=enemy3.begin();ta!=enemy3.end();++ta){
            int a=it->Attack(ta->getCoor());
            if(a==1)attack2.play();
            else if(a==3){
                ta->slowSpeed(it->getLevel());
                ta->reduceHP(it->getAttack());
                if(ta->getAct()==0){coins+=ta->getMoney();die3.play();}
            }
            if(a!=0){attacked=1;break;}
            else if(it->reSpeedjud(ta->getCoor())==1)ta->reSpeed();
        }
        if(!attacked)for(auto ta=enemy.begin();ta!=enemy.end();++ta){
            int a=it->Attack(ta->getCoor());
            if(a==1)attack2.play();
            else if(a==3){
                ta->slowSpeed(it->getLevel());
                ta->reduceHP(it->getAttack());
                if(ta->getAct()==0){coins+=ta->getMoney();die1.play();}
            }
            if(a!=0){attacked=1;break;}
            else if(it->reSpeedjud(ta->getCoor())==1)ta->reSpeed();
        }
        if(!attacked)for(auto ta=enemy4.begin();ta!=enemy4.end();++ta){
            int a=it->Attack(ta->getCoor());
            if(a==1)attack2.play();
            else if(a==3){
                ta->slowSpeed(it->getLevel());
                ta->reduceHP(it->getAttack());
                if(ta->getAct()==0){coins+=ta->getMoney();die4.play();}
            }
            if(a!=0){attacked=1;break;}
            else if(it->reSpeedjud(ta->getCoor())==1)ta->reSpeed();
        }
        if(!attacked)it->resetPoint();
    }
    for(auto it=tower3.begin();it!=tower3.end();++it){
        bool attackjudge=0;//攻击状态
        for(auto ta=enemy4.begin();ta!=enemy4.end();++ta){
            int a=it->Attack(ta->getCoor());//攻击状态确认函数
            if(a>0){
                attackjudge=1;
                if(a==2){
                    ta->reduceHP(it->getAttack());//发动攻击
                    if(ta->getAct()==0){coins+=ta->getMoney();die4.play();}//杀敌
                }
            }
        }
        for(auto ta=enemy3.begin();ta!=enemy3.end();++ta){
            int a=it->Attack(ta->getCoor());
            if(a>0){
                attackjudge=1;
                if(a==2){
                    ta->reduceHP(it->getAttack());
                    if(ta->getAct()==0){coins+=ta->getMoney();die3.play();}
                }
            }
        }
        for(auto ta=enemy2.begin();ta!=enemy2.end();++ta){
            int a=it->Attack(ta->getCoor());
            if(a>0){
                attackjudge=1;
                if(a==2){
                    ta->reduceHP(it->getAttack());
                    if(ta->getAct()==0){coins+=ta->getMoney();die2.play();}
                }
            }
        }
        for(auto ta=enemy.begin();ta!=enemy.end();++ta){
            int a=it->Attack(ta->getCoor());
            if(a>0){
                attackjudge=1;
                if(a==2){
                    ta->reduceHP(it->getAttack());
                    if(ta->getAct()==0){coins+=ta->getMoney();die1.play();}
                }
            }
        }
        for(auto ta=stone.begin();ta!=stone.end();++ta)if(ta->getTar()||attackjudge==1){
            int a=it->Attack(ta->getCoor());
            if(a>0){
                attackjudge=1;
                if(a==2){
                    ta->reduceHP(it->getAttack());
                    if(ta->getAct()==0){coins+=ta->getMoney();trash.play();}
                }
            }
        }
        if(attackjudge){//处在某一区域内敌人的群体伤害
            int a=it->Attack();//攻击效果判断
            if(a==1)attack3.play();
        }else it->resetPoint();//子弹重置
    }
    this->repaint();
}

void Dialog::reset(){//全部变量重置
    enemy[0].reset();
    enemy.clear();enemy2.clear();enemy3.clear();enemy4.clear();
    tower.clear();tower2.clear();tower3.clear();stone.clear();
    p_click.setX(-1);p_click.setY(-1);
    buttonCover=0;time0=0;wavenum=0;coins=500;gameover=0;
    virussum[0]=8;virussum[1]=5;virussum[2]=2;virussum[3]=0;
    virusnum[0]=8;virusnum[1]=5;virusnum[2]=2;virusnum[3]=0;
    //重置一批障碍物
    Point p(140,280);
    Stone s1(p);stone.push_back(s1);
    p.setX(280);p.setY(210);
    Stone s2(p);stone.push_back(s2);
    p.setX(490);p.setY(210);
    Stone s3(p);stone.push_back(s3);
    p.setX(630);p.setY(280);
    Stone s4(p);stone.push_back(s4);
    p.setX(350);p.setY(350);
    Stone s5(p);stone.push_back(s5);
    //标签重新显示
    ui->label_2->setGeometry(ui->label_2->x(),130,
                             ui->label_2->height(),ui->label_2->width());//肺部生命值的位置改变
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
}

void Dialog::gameOver(QPainter &painter) {//游戏失败
    ui->label->hide();//标签隐藏
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    painter.drawPixmap(rect(), QPixmap("://image/lose.jpg"));
}

void Dialog::gameWin(QPainter &painter) {//游戏成功
    ui->label->hide();//标签隐藏
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    painter.drawPixmap(rect(), QPixmap("://image/win.jpg"));
}
