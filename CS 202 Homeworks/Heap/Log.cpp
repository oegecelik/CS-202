/*
* Author : Orhun Ege Çelik
* ID: 22202321
* Section : 3
* Homework : 2
* Description : Implementation file for each log.
*/
#include "Log.h"

Log::Log(int id, int priority, int requestTime, int processDuration):id{id}, priority{priority}, 
requestTime{requestTime}, processDuration{processDuration}
{
}

Log::Log()
{
}

// The getKey() for each log prioritizes its priority value, and then its request time.
// The returned value looks like: (priority.decimal...) 
// It is ensured that the static_cast<double>(1)/requestTime <= 1, therefore the effect of the priority value is higher.
double Log::getKey()
{
    return priority + static_cast<double>(1)/requestTime;
}
