/*
* Author : Orhun Ege Çelik
* ID: 22202321
* Section : 3
* Homework : 2
* Description : Runner code for the homework.
*/
#include "RequestHandler.h"

int main(int argc, char const *argv[])
{
    RequestHandler simulation;
    simulation.readFile(argv[1]);
    bool simContinue = true;
    int i = 1;
    double timeLimit = stod(argv[2]);
    while(simContinue){
        simContinue = simulation.simulate(i++,timeLimit);
    }
    return 0;
}

