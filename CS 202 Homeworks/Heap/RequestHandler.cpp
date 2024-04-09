/*
* Author : Orhun Ege Çelik
* ID: 22202321
* Section : 3
* Homework : 2
* Description : Implementation for the request handler class.
* It has 2 methods, readFile reads the input log file, then calls simulate, which
* finds the minimum amount of computers needed.
*/
#include "RequestHandler.h"
#include <iomanip>
RequestHandler::RequestHandler()
{
    logs = nullptr;
    computers = nullptr;
    logSize = 0;
    compSize = 0;
    processingCompSize = 0;
    freeCompSize = 0;
}

RequestHandler::~RequestHandler()
{
    if(logs)
        delete[] logs;
    if(computers)
        delete[] computers;
    logs = nullptr;
    computers = nullptr;
}

void RequestHandler::readFile(string inputFile)
{
    string line;
    string delimiter = "\t";
    string delimeter2 = " ";
    ifstream file(inputFile);

    if (file.is_open()) {
        getline(file, line);
        int maxLogSize = stoi(line);
        logs = new Log[maxLogSize];
        while (getline(file, line)) {
            int pos = 0;

            pos = line.find(delimiter);
            if(pos == -1){
                pos = line.find(delimeter2);
            }
            int id = stoi(line.substr(0, pos));
            line.erase(0, pos);
            while(!isdigit(line[0])){
                line.erase(0, 1); // number of characters to remove is index of space + 1.
            }
            

            pos = line.find(delimiter);
            if(pos == -1){
                pos = line.find(delimeter2);
            }
            int priority = stoi(line.substr(0, pos));
            line.erase(0, pos);
            while(!isdigit(line[0])){
                line.erase(0, 1); // number of characters to remove is index of space + 1.
            }

            pos = line.find(delimiter);
            if(pos == -1){
                pos = line.find(delimeter2);
            }
            int requestTime = stoi(line.substr(0, pos));
            line.erase(0, pos);
            while(!isdigit(line[0])){
                line.erase(0, 1); // number of characters to remove is index of space + 1.
            } 

            int processTime = stoi(line.substr(0, line.length())); 

            logs[logSize++] = Log(id, priority, requestTime, processTime);                      
        }
        file.close();
    }   
}

bool RequestHandler::simulate(int computerCount, double waitTimeBoundary)
{
    string toReturn;
    compSize = computerCount;
    computers = new Computer[compSize];
    Heap<Log*> logHeap;
    Heap<Computer*> freeComputerHeap, processingComputerHeap;
    freeComputerHeap.setSize(computerCount);
    processingComputerHeap.setSize(computerCount);
    logHeap.setSize(logSize);

    for(int i = 0; i < compSize; i++){
        computers[i].id = i;
        freeComputerHeap.heapInsert(&computers[i]);
    }
    int currentTime = logs[0].requestTime;
    int prevTime = currentTime;
    int totalWaitTime = 0;
    int currentWaitTime = 0;
    int logsIndex = 0;
    int deltaT = 0;     //difference between last time and current time.
    // deltaT can be the change of time between any of the following:
    // two incoming logs
    // an incoming log and process ending
    // two process endings
    // all computers currently processing must be affected by deltaT.
    // at the end, update prevTime
    while(logsIndex != logSize || !processingComputerHeap.heapIsEmpty()){

        if(processingComputerHeap.heapIsEmpty()){
            currentTime = logs[logsIndex].requestTime;
            logHeap.heapInsert(&logs[logsIndex++]);
            deltaT = 0;
            while(logsIndex != logSize && logs[logsIndex].requestTime == logHeap.top()->requestTime){
                logHeap.heapInsert(&logs[logsIndex++]);
            }            
        }
        else if(logsIndex == logSize){
            currentTime += processingComputerHeap.top()->timeLeft;
            deltaT = currentTime - prevTime;
        }
        else{ // Logs still exist and processing computers heap is not empty
            //If new time is caused by process ending
            if(currentTime + processingComputerHeap.top()->timeLeft < logs[logsIndex].requestTime){
                currentTime += processingComputerHeap.top()->timeLeft;
                deltaT = currentTime - prevTime;
            }
            else if(currentTime + processingComputerHeap.top()->timeLeft == logs[logsIndex].requestTime){
                currentTime += processingComputerHeap.top()->timeLeft;
                deltaT = currentTime - prevTime;
                logHeap.heapInsert(&logs[logsIndex++]);
                while(logsIndex != logSize && logs[logsIndex].requestTime == logHeap.top()->requestTime){
                    logHeap.heapInsert(&logs[logsIndex++]);
                } 
            }
            else{ // If the change in time is caused by an incoming log
                logHeap.heapInsert(&logs[logsIndex]);
                currentTime = logs[logsIndex].requestTime;
                deltaT = currentTime - prevTime;
                logsIndex++;
                while(logsIndex != logSize && logs[logsIndex].requestTime == logHeap.top()->requestTime){
                    logHeap.heapInsert(&logs[logsIndex++]);
                } 
            }
           
        }
        
        // Update all the computers, put them into free computer heap if the time left is 0.
        int loopProcess = processingCompSize;
        for(int i = 0; i < loopProcess; i++){
            processingComputerHeap.items[i]->timeLeft -= deltaT;
        }
        
        for(int i = 0; i < loopProcess; i++){
            if(processingComputerHeap.top()->timeLeft == 0){
                freeComputerHeap.heapInsert(processingComputerHeap.top());
                freeCompSize++;
                processingComputerHeap.heapDelete();
                processingCompSize--;
            }
        }

        // If there are available computers, insert all the logs in the heap inside a computer.
        while(!logHeap.heapIsEmpty() && !freeComputerHeap.heapIsEmpty()){
            currentWaitTime = currentTime - logHeap.top()->requestTime;
            freeComputerHeap.top()->timeLeft = logHeap.top()->processDuration+1;
            processingComputerHeap.heapInsert(freeComputerHeap.top());
            toReturn += "Computer " + to_string(freeComputerHeap.top()->id) + " takes request " + to_string(logHeap.top()->id) + " at ms " + to_string(currentTime)
            + " (wait: " + to_string(currentWaitTime) + " ms)\n";
            freeComputerHeap.heapDelete();
            freeCompSize--;
            processingCompSize++;
            logHeap.heapDelete();
            totalWaitTime += currentWaitTime;
        }
        prevTime = currentTime;
    }
    double averageWaitTime = static_cast<double>(totalWaitTime)/logSize;

    delete[] computers;
    computers = nullptr;
    computers = 0;
    processingCompSize = 0;
    freeCompSize = 0;
    compSize = 0;
    logsIndex = 0;
    if(averageWaitTime <= waitTimeBoundary){
        cout << "Minimum number of computers required: " << computerCount << endl;
        cout << "\nSimulation with " << computerCount << " computers:" << endl;
        cout<<endl;
        cout<<toReturn;
        cout << std::setprecision(2)<<fixed;
        cout << "\nAverage waiting time: " << averageWaitTime << " ms" << endl;
        return false;
    }
    return true;
}
