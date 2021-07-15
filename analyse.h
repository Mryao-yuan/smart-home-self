#ifndef ANALYSE_H
#define ANALYSE_H

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QByteArray>
#include <QDebug>


class analyse
{
public:
    analyse();
    ~analyse();

    //功能：解析data数据，获得当前的最低温度,最高温度,天气类型,风向
	// @data       需要解析的天气数据
	// @low_temp   最低温度
	// @high_temp  最高温度
	// @type       天气类型 
	// @wind       风向
    void analyse_data(const QByteArray &data,QString &low_temp,QString &high_temp,QString &type,QString  &wind);
};

#endif // ANALYSE_H
