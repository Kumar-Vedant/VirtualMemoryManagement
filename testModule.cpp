#include <iostream>
#include <fstream>

#include "include/IOModule.h"
#include "include/performanceModule.h"
#include "include/config.h"

using namespace std;

int main()
{
    int numberOfTasks = getNumberOfTasks();
    
    // generate trace file with the format taskID:logicalAddress:size
    generateTraceFile(numberOfTasks);

    // initialize the performance module
    PerformanceModule performanceModule;

    return 0;
}

int getNumberOfTasks() 
{
    int numberOfTasks;
    cout << "Enter the number of tasks: ";
    cin >> numberOfTasks;
    return numberOfTasks;
}

void generateTraceFile(int numberOfTasks)
{
    ofstream traceFile;
    traceFile.open("trace.txt");
    for (int i = 0; i < 1000000; i++)
    {
        int taskID = rand() % numberOfTasks + 1;

        int logicalAddress = rand() % 1000;

        // convert to hexadecimal
        // string logicalAddressHex = to_string(logicalAddress);
        // logicalAddressHex = "0x" + logicalAddressHex;
        
        int size = rand() % 100;
        
        traceFile << "T" << taskID << ":" << logicalAddress << ":" << size << endl;
    }
    traceFile.close();
}