#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include  <QCameraImageCapture>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QByteArray>
#include <QFileInfo>
#include <QTextCodec>
#include <QString>
#include <analyse.h>
#include "dialog1.h"
#include <QTimer>
#include <QString>
#include <QDateTime>
#include<QSplashScreen>
#include<QPixmap>



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);


    ~MainWindow();

public slots:
    void  time_recive();

private slots:
    void on_pushButton_video_clicked();

    void on_pushButton_music_clicked();

    void on_pushButton_weather_clicked();

    void on_btn_lightkey_clicked();

    void send_request_info(QString &city);

    void encod_utf_8(QString &data);

    void recoive_info();

    void on_btn_air_conditionner_key_clicked();

    void on_btn_exit_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manger;

    QNetworkReply *replay;
    analyse *anl;
    QString  low_temp;
    QString  high_temp;
    QString  type;
    QString wind;

    QTimer *time;

};

#endif // MAINWINDOW_H
