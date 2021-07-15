#include "dialog1.h"
#include "ui_dialog1.h"

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    camera = new QCamera;

    finder =new QCameraViewfinder(this);

    //在camera中截图故要在camera不是this
    //cap是捕获截图的新建类
    cap=new QCameraImageCapture(camera);

}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_btn_start_clicked()
{
    ui->horizontalLayout->addWidget(finder);

    camera->setViewfinder(finder);

    connect(cap,SIGNAL(imageCaptured(int,QImage)),this,SLOT(display_picture(int,QImage)));

     camera->start();
}

void Dialog1::on_btn_prograph_clicked()
{

    cap->capture();//截图
}

void Dialog1::on_btn_save_clicked()
{
    QString path_name=QFileDialog::getSaveFileName(this,tr("另存为"),
              QDir::homePath(),//默认用户路径
            tr("Images(*.jpg)"));//保存的格式
    if(path_name.isEmpty()){
        return;
    }else{
        //得到label标签的信息
        const QPixmap *p=ui->label_image->pixmap();
        p->save(path_name);
    }

}

void Dialog1::on_btn_stop_clicked()
{
     camera->stop();


}

void Dialog1::on_btn_exit_clicked()
{
    camera->stop();
    MainWindow * mainwindow =new MainWindow;
    mainwindow->show();
    this->close();


}

void Dialog1::display_picture(int num, QImage img)
{
    //把保存的照片用像素进行显示
    ui->label_image->setPixmap(QPixmap::fromImage(img));
    //显示在label中，自适应label大小
    ui->label_image->setScaledContents(true);

}
