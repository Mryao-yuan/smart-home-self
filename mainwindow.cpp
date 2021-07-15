#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"widget.h"
#include "login.h"
#include "dialog.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manger =new QNetworkAccessManager(this);

    anl=new analyse;

    time = new QTimer(this);

    connect(time,SIGNAL(timeout()),this,SLOT(time_recive()));

    time->start(1000);
}


MainWindow::~MainWindow()
{
    delete ui;
}
//进入视频界面
void MainWindow::on_pushButton_video_clicked()
{
    Dialog1 *dialog=new Dialog1;
    dialog->show();
    this->close();

}
//进入音乐播放器界面
void MainWindow::on_pushButton_music_clicked()
{

    //将音乐播放器的状态和音乐按钮相连，点击音乐按钮关闭之前的播放歌曲
   //connect(this,&Widget::music,this,SLOT(close()));
    Widget *wg=new Widget;
    wg->show();
    this->close();

}

//查询天气
void MainWindow::on_pushButton_weather_clicked()
{
    //得到输入的城市（中文汉字）
    QString city=ui->lineEdit_city->text();

    //进行中文编码为url编码
    encod_utf_8(city);

    //发送输入城市的请求信息
    send_request_info(city);
}

//灯开关
void MainWindow::on_btn_lightkey_clicked()
{
    static bool ISledon=false;
    ISledon=!ISledon;
    if(ISledon){
     ui->btn_light->setStyleSheet("image: url(:/image/image/yourpicture/灯open.png);border-radius:10px;");
     ui->btn_lightkey->setStyleSheet("image: url(:/image/image/yourpicture/开关关.png);border-radius:10px;");
     ui->label_light_status->setText("灯已打开");
    }
    else{
        ui->btn_light->setStyleSheet("image: url(:/image/image/yourpicture/灯close.png);border-radius:10px;");
        ui->btn_lightkey->setStyleSheet("image: url(:/image/image/yourpicture/开关开.png);border-radius:10px;");
        ui->label_light_status->setText("灯已关闭");
    }
}

//发送请求信息
void MainWindow::send_request_info(QString &city)
{
    //请求网址
   QString  url="http://wthrcdn.etouch.cn/weather_mini?city="+city;

   QNetworkRequest request (url);

   replay=manger->get(request);

   connect(replay,SIGNAL(finished()),
           this,SLOT(recoive_info()));

}
//将输入的城市进行转码为url(利用utf_8)
void MainWindow::encod_utf_8(QString &city)
{
    //创建一个utf_8格式的编码指针
    QTextCodec *codec=QTextCodec::codecForName("utf_8");

     //把中文汉字填充到编码指针中
    QByteArray byte=codec->fromUnicode(city);

    QByteArray encoded=byte.toPercentEncoding();

    //清除原来输入的城市信息
    city.clear();

     //完成编码city变为utf_8形式编码
   city=encoded.data();

}


void MainWindow::recoive_info()
{
    //读取所有接收到的信息保存在data做
    QByteArray data=replay->readAll();

    //通过解析函数得到天气，温度，风力的信息
    anl->analyse_data(data, low_temp,high_temp,type,wind);

    //将得到的信息写入label中
    ui->label_high_temp->setText(high_temp);
    ui->label_low_temp->setText(low_temp);
    ui->label_wind->setText(wind);
    ui->label_weather->setText(type);

}
//空调开关
void MainWindow::on_btn_air_conditionner_key_clicked()
{
    static bool ISledon=false;
    ISledon=!ISledon;
    if(ISledon){
     ui->btn_air_conditionner_key->setStyleSheet("image: url(:/image/image/yourpicture/开关关.png);border-radius:10px;");
     ui->btn_air_conditionner->setStyleSheet("image: url(:/image/image/yourpicture/空调open.png);border-radius:10px;");
     ui->label_aircondition_status->setText("空调已打开");
    }
    else{              //image: url(:/new/空调close.png);
        ui->btn_air_conditionner_key->setStyleSheet("image: url(:/image/image/yourpicture/开关开.png);border-radius:10px;");
        ui->btn_air_conditionner->setStyleSheet("image: url(:/image/image/yourpicture/空调close.png);border-radius:10px;");
        ui->label_aircondition_status->setText("空调已关闭");
    }

}

void MainWindow::on_btn_exit_clicked()
{
    login *log=new login;
    log->show();
    this->close();

}


void MainWindow::time_recive()
{
    QDateTime time=QDateTime::currentDateTime();

    QString str =time.toString("yyyy_MM_dd hh:mm:ss");

    ui->label_TIME->setText(str);


}
