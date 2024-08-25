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
            for (int i = 0; i < 3; i++)
            {
                switch (i)
                {
                    case 0:
                        // report execution time
                        cout << "Execution time for implementation : " << "Map" << ": " << executionTimes[i] << " microseconds" << endl;
                        // physical memory allocated to each task
                        // cout << "Physical memory allocated to each task: " <<  ioModuleMap.getTaskMemoryAllocated() << endl;

                        // memory for page table
                        // cout << VIRTUAL_PAGES * (BITS_VIRTUAL_SPACE / 8) << "Bytes" << endl;
                        
                        // free physical memory
                        cout << "Free physical memory: " << ioModuleMap.getFreePhysicalMemory() << endl;

                        break;
                    case 1:
                        // report execution time
                        cout << "Execution time for implementation : " << "Single-level" << ": " << executionTimes[i] << " microseconds" << endl;

                        // memory for page table
                        cout << "Memory for Page Table: " << VIRTUAL_PAGES * (BITS_VIRTUAL_SPACE / 8) << "Bytes" << endl;

                        // free physical memory
                        cout << "Free physical memory: " << ioModuleSingleLevel.getFreePhysicalMemory() << endl;
                        break;
                    case 2:
                        // report execution time
                        cout << "Execution time for implementation ; " << "Two-level" << ": " << executionTimes[i] << " microseconds" << endl;

                        // memory for page table
                        cout << "Memory for Page Table: " << PAGE_TABLE_SIZE_1 * (PTE_SIZE_1 / 8) + PAGE_TABLE_SIZE_2 * (PTE_SIZE_2 / 8) << "Bytes" << endl;

                        // free physical memory
                        cout << "Free physical memory: " << ioModuleTwoLevel.getFreePhysicalMemory() << endl;
                        break;
                    
                }

                // 2/3- total memory for page table

                // page table as a map
                // single level page table
                // two level page table
            }
        }

    private:
        float executionTimes[3];
};