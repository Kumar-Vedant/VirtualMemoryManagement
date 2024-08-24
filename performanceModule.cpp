#include <bits/stdc++.h>
#include <chrono>

#include "include/IOModule.h"

using namespace std;
using namespace std::chrono;

class PerformanceModule
{
    public:
        PerformanceModule()
        {
            // create 3 implementations of IOModule
            // measure the execution time of each implementation
            
            // single level page table
            auto start = high_resolution_clock::now();
            IOModule ioModuleSingleLevel(0);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            executionTimes[0] = duration.count();
            
            // two level page table
            auto start = high_resolution_clock::now();
            IOModule ioModuleTwoLevel(1);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            executionTimes[1] = duration.count();
            
            // map page table
            auto start = high_resolution_clock::now();
            IOModule ioModuleMap(2);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            executionTimes[2] = duration.count();
            

            // for each implementation, report:

            // - execution time

            // - physical memory allocated to each task
            // ioModule.getTaskMemoryAllocated();

            // total memory for page table
            // - free physical memory
        }

    private:
        float executionTimes[3];
};