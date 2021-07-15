#include "analyse.h"

analyse::analyse()
{

}

analyse::~analyse()
{

}

//功能：解析data数据，获得当前的最低温度,最高温度,天气类型,风向
void analyse::analyse_data(const QByteArray &data,QString &low_temp,QString &high_temp,QString &type,QString &wind)
{
    //将数据解析成QJsonDocument对象
    QJsonDocument Jsondocument = QJsonDocument::fromJson(data);
    //在将QJsonDocument解析成QJsonObJect对象
    QJsonObject jsonobject = Jsondocument.object();
    //获取QJsonObJect对象里面的值
    QJsonObject dataobject = jsonobject["data"].toObject();
    //访问QJsonArry里面成员的值
    QJsonArray forecast = dataobject["forecast"].toArray();
    QJsonObject forecastobject = forecast[0].toObject();


    low_temp    =  forecastobject["low"].toString();
    high_temp   =  forecastobject["high"].toString();
    type        =  forecastobject["type"].toString();
    wind        = forecastobject["fengxiang"].toString();

//    qDebug() << "low_temp" << low_temp << endl;
//    qDebug() << "high_temp" << high_temp << endl;
//    qDebug() << "wind" << wind << endl;
//    qDebug() << "type" << type << endl;

}






