#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_24->setText("<a href=\"www.cvosrobot.com\">关于我们");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString vel = this->ui->lineEdit->text();//转速
    QString dia = this->ui->lineEdit_2->text();//轮胎直径
    double velt = vel.toDouble();
    double diat = dia.toDouble();
    velt = velt  *60; //转换成1分钟走多少cm
   double  diad =  diat * 3.14;//一圈周长

   double res = velt / diad;

   QString resstr = QString::number(res, 10, 4);

   this->ui->lineEdit_3->setText(resstr);


}

void MainWindow::on_pushButton_2_clicked()
{
    QString niuju = this->ui->lineEdit_4->text();//转速

    double niujud = niuju.toDouble();

   double  zhuanju = niujud  *0.01 * 9.8; //转换成1 kgcm  *0.01 *9.8N =0.098 NM




   QString resstr = QString::number(zhuanju, 10, 4);

   this->ui->lineEdit_5->setText(resstr);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString m = this->ui->lineEdit_6->text();//质量kg

    double  mm= m.toDouble();
    QString mfactor = this->ui->lineEdit_8->text();//摩擦因子
    double factorm = mfactor.toDouble();//
    QString geshu = this->ui->lineEdit_10->text();//gesshu
    double num = geshu.toDouble();//
    //转换成1 kg*9.8N

    QString dia = this->ui->lineEdit_2->text();//轮胎直径

    double diat = dia.toDouble();
    double r = diat /2;//轮胎半径

    double T= factorm * mm * 9.8 *r*0.01;
    double T_d= T / num;
    double T_1 = T_d/9.8/0.01;
   QString resstr = QString::number(T, 10, 4);
   this->ui->lineEdit_7->setText(resstr);

   QString dan = QString::number(T_d, 10, 4);
   this->ui->lineEdit_9->setText(dan);

   QString T1 = QString::number(T_1, 10, 4);
   this->ui->lineEdit_11->setText(T1);
}
