#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_0,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));
    connect(ui->btn_1,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));
    connect(ui->btn_2,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));
    connect(ui->btn_3,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));
    connect(ui->btn_4,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));
    connect(ui->btn_5,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));
    connect(ui->btn_6,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));
    connect(ui->btn_7,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));
    connect(ui->btn_8,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));
    connect(ui->btn_9,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));
    connect(ui->btn_10,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));
    connect(ui->btn_11,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));
    connect(ui->btn_12,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));
    connect(ui->btn_13,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));
    connect(ui->btn_14,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));
    connect(ui->btn_15,SIGNAL(clicked()),this,SLOT(on_btn_clicked()));

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_clicked()
{
   QPushButton *button=(QPushButton *) sender();
   if(button==pButton_0) return;
   int t=button->text().toInt();
   int i=0;
   int find=-1;
   for(;i<16;i++)
       if (Array_Numbers[i]==t)break;

   if (((i)/4)>0)
       if (Array_Numbers[i-4]==0)
         find=i-4;

   if (((i)/4)<3)
       if (Array_Numbers[i+4]==0)
          find=i+4;

   if (((i)%4)>0)
       if (Array_Numbers[i-1]==0)
        find=i-1;

   if (((i)%4)<3)
       if (Array_Numbers[i+1]==0)
          find=i+1;

      if (find==-1) return;

      Array_Numbers[find]=t;
      Array_Numbers[i]=0;
      pButton_0->setText(QString::number(t));
      pButton_0->setEnabled(true);
      button->setText("");
      button->setEnabled(false);
      pButton_0=button;

     for(i=0;i<15;i++)
         if(Array_Numbers[i]!=i+1) return;
     timer->stop();
     QMessageBox::information(this, "Внимание","Игра окончена!");
}

void MainWindow::slotTimerAlarm()
{
    Seconds++;

    char str[5];
    sprintf(&str[0],"%2d:%2d",Seconds/60,Seconds%60);
    if (Seconds/60<10)str[0]='0';
    if (Seconds%60<10)str[3]='0';

    ui->label->setText(&str[0] );

}

void MainWindow::on_pushButton_clicked()
{
    int start_array_numbers[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    Array_Numbers[15]=0;
    srand(time(0));
    for(int i=15;i>1;i--)
    {   int t=rand()%i;
        Array_Numbers[i-1]=start_array_numbers[t];
        start_array_numbers[t] =start_array_numbers[i-1];
        start_array_numbers[i-1]=Array_Numbers[i-1];
    }
     Array_Numbers[0]=start_array_numbers[0];
     if (pButton_0!=NULL)
        pButton_0->setEnabled(true);

     pButton_0= ui->btn_0;

     ui->btn_0->setText("");
     ui->btn_0->setEnabled(false);

     ui->btn_1->setText(QString::number(Array_Numbers[0]));
     ui->btn_2->setText(QString::number(Array_Numbers[1]));
     ui->btn_3->setText(QString::number(Array_Numbers[2]));
     ui->btn_4->setText(QString::number(Array_Numbers[3]));
     ui->btn_5->setText(QString::number(Array_Numbers[4]));
     ui->btn_6->setText(QString::number(Array_Numbers[5]));
     ui->btn_7->setText(QString::number(Array_Numbers[6]));
     ui->btn_8->setText(QString::number(Array_Numbers[7]));
     ui->btn_9->setText(QString::number(Array_Numbers[8]));
     ui->btn_10->setText(QString::number(Array_Numbers[9]));
     ui->btn_11->setText(QString::number(Array_Numbers[10]));
     ui->btn_12->setText(QString::number(Array_Numbers[11]));
     ui->btn_13->setText(QString::number(Array_Numbers[12]));
     ui->btn_14->setText(QString::number(Array_Numbers[13]));
     ui->btn_15->setText(QString::number(Array_Numbers[14]));
     timer->start(1000);
     Seconds=0;

}



