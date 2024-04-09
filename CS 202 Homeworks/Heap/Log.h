/*
* Author : Orhun Ege Çelik
* ID: 22202321
* Section : 3
* Homework : 2
* Description : Header file for each log.
* Logs contain id, priority, requestTime and
* Process Duration.
*/
#ifndef LOG_H
#define LOG_H
class Log{
public:
    Log(int id, int priority, int requestTime, int processDuration);
    Log();
    double getKey();
    //Default copy constructor and destructor
    int id;
    int priority;
    int requestTime;
    int processDuration;
};
#endif