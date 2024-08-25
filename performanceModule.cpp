#include <bits/stdc++.h>
#include <chrono>

#include "include/IOModule.h"
#include "include/config.h"

using namespace std;
using namespace std::chrono;

class PerformanceModule
{
    public:
        PerformanceModule()
        {
            // create 3 implementations of IOModule
            // measure the execution time of each implementation
            
            // map page table
            auto start = high_resolution_clock::now();
            IOModule ioModuleMap(0);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            executionTimes[0] = duration.count();
            
            // single level page table
            auto start = high_resolution_clock::now();
            IOModule ioModuleSingleLevel(1);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            executionTimes[1] = duration.count();
            
            // single level page table
            auto start = high_resolution_clock::now();
            IOModule ioModuleTwoLevel(2);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            executionTimes[2] = duration.count();
            

            // for each implementation, report:
            // - execution time

            // - physical memory allocated to each task
            // ioModule.getTaskMemoryAllocated();

            // 2/3- total memory for page table

            // page table as a map
            

            // single level page table
            // VIRTUAL_PAGES * (BITS_VIRTUAL_SPACE / 8) bytes
            
            
            // two level page table
            // PAGE_TABLE_SIZE_1 * (PTE_SIZE_1 / 8) + PAGE_TABLE_SIZE_2 * (PTE_SIZE_2 / 8) bytes

            // - free physical memory

            // page table as a map
            // single level page table
            // two level page table
        }

    private:
        float executionTimes[3];
};