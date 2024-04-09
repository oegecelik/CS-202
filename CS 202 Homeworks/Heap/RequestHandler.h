/*
* Author : Orhun Ege Çelik
* ID: 22202321
* Section : 3
* Homework : 2
* Description : Header file for the main code.
* Distributes logs to computers.
*/
#ifndef REQUEST_HANDLER
#define REQUEST_HANDLER
#include <iostream>
#include <fstream>
#include "Heap.h"
#include "Log.h"
#include "Computer.h"
using namespace std;

class RequestHandler{
public:
    RequestHandler();
    ~RequestHandler();
    void readFile(string inputFile);
    bool simulate(int computerCount, double waitTime);

private:
    Log* logs;
    Computer* computers;
    int processingCompSize;
    int freeCompSize;
    int logSize;
    int compSize;

};
#endif