#ifndef DIALOG1_H
#define DIALOG1_H

#include <QDialog>
#include <QWidget>
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraViewfinder>
#include <QFileDialog>
#include <QPixmap>
#include <mainwindow.h>
#include <widget.h>


namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = 0);
    ~Dialog1();

private slots:
    void on_btn_start_clicked();

    void on_btn_prograph_clicked();

    void on_btn_save_clicked();

    void on_btn_stop_clicked();

    void on_btn_exit_clicked();

    void display_picture(int num, QImage img);

private:
    Ui::Dialog1 *ui;
    QCamera * camera;
    QCameraViewfinder * finder;
    QCameraImageCapture * cap;
};

#endif // DIALOG1_H
