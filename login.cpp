#include "login.h"
#include "ui_login.h"
#include<QSplashScreen>
#include<QPixmap>
#include"widget.h"
#include "mainwindow.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    //设置输入密码不显示
    ui->lineEdit_PASSWORD->setEchoMode(QLineEdit::Password);
   //设置提示字
    ui->lineEdit_ID->setPlaceholderText("账号");
    ui->lineEdit_PASSWORD->setPlaceholderText("密码不得小于6位");

}

login::~login()
{
    delete ui;
}

void login::on_btn_login_clicked()
{
//        Widget *w=new Widget;
//        w->setWindowIcon(QIcon("ooopic_1520340986.ico"));
//        w->setWindowTitle(("我的音乐"));
//        w->show();
//        this->close();
    QString id=ui->lineEdit_ID->text();
    QString pass=ui->lineEdit_PASSWORD->text();
    if(id.isEmpty()||pass.isEmpty()){
        QMessageBox::information(this,"提示","用户名不能为空");

    }
    else if(pass.isEmpty()||pass.isEmpty()){
        QMessageBox::information(this,"提示","密码不能为空");

    }

    else if(id=="1"&&pass=="1"){
    MainWindow *mainwindow=new MainWindow;
    mainwindow->show();
    this->close();
    }
}
