/*
* Author : Orhun Ege Çelik
* ID: 22202321
* Section : 3
* Homework : 2
* Description : Header file for each log.
* Computers contain id and timeLeft.
*/
#ifndef COMPUTER_H
#define COMPUTER_H
class Computer{
public:
    Computer(int id, double timeLeft);
    Computer();
    double getKey();
    //Default copy constructor and destructor
    int id;
    double timeLeft;
};
#endif