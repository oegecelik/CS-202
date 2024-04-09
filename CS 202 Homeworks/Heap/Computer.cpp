/*
* Author : Orhun Ege Çelik
* ID: 22202321
* Section : 3
* Homework : 2
* Description : Implementation file for each computer.
*/
#include "Computer.h"
#include <cmath>

Computer::Computer(int id, double timeLeft):id{id}, timeLeft{timeLeft}
{
}

Computer::Computer()
{
    id = 0;
    timeLeft = 0;
}

// The get key method for a computer prioritizes the time left to finish its current process, then secondly checks its index.
// The computer with the lowest time left and the lowest id has the highest priority, however the time and id should act independently.
// Hence, this getKey() method is implemented so that it returns (-timeLeft.id) as a decimal number. 
// Note that as time left decreases in absolute value, the returned number increases, therefore priority increases.
// Similarly, for any two computers with the same time left, as id decreases, the returned number increases, therefore priority increases.
double Computer::getKey()
{
    int digitsOfId;
    digitsOfId = log10(id) + 1;
    if(id == 0){
        digitsOfId = 0;
    }
    double afterDecimalPoint = id * pow(0.1, digitsOfId);
    return -(timeLeft + afterDecimalPoint);
}
