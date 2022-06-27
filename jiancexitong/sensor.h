#ifndef SENSOR_H
#define SENSOR_H
#include<QString>

class Sensor
{
public:
    Sensor();
    Sensor (int id,QString name,QString pos,QString re);\
    QString getSensorName();
    QString getSensorPos();
    QString getSensorRe();
        int getSensorId();

public:
   int PointId=0;
   QString PointName;
   QString PointPos;
   QString PointRe;
   //Sensor (int id,QString name,QString pos,QString re);



};

#endif // SENSOR_H
