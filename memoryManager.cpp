#include <bits/stdc++.h>

#include "include/config.h"

using namespace std;

// const int PAGE_SIZE = 1024; // 1KB
// const int PHYSICAL_MEMORY_SIZE = 65536; // 64KB
// const int VIRTUAL_MEMORY_SIZE = 65536; // 64KB

class MemoryManager
{
    public:
        // create the required no. of pages initially
        MemoryManager()
        {
            // read the config.h file to get the values of PAGE_SIZE, PHYSICAL_MEMORY_SIZE, VIRTUAL_MEMORY_SIZE
        }
        
        // gives a physical page address 
        vector<int> allocatePages(int size)
        {
            vector<int> physicalPagesAllocated;

            // calculate no. of pages required using size
            int numberOfPages = size / PAGE_SIZE;

            // iterate through the physicalPages array to find the first element whose value is 0
            for (int i = 0; i < sizeof(physicalPages) / sizeof(int); i++)
            {
                // allocate the first available page
                if (physicalPages[i] == 0)
                {
                    // set the page allocated to 1
                    physicalPages[i] = 1;
                    // store the index of the page allocated
                    physicalPagesAllocated.push_back(i);
                }

                // if no page is available, return error
                
                // if all required pages are allocated, break
                if (physicalPagesAllocated.size() == numberOfPages)
                {
                    break;
                }
            }
            // return the indexes of the physical pages allocated
            return physicalPagesAllocated;
        }

        int getPageSize()
        {
            return PAGE_SIZE;
        }

        int getPhysicalMemorySize()
        {
            return PHYSICAL_MEMORY_SIZE;
        }

        int getFreePhysicalMemory()
        {
            int freeMemory = 0;
            for (int i = 0; i < sizeof(physicalPages) / sizeof(int); i++)
            {
                if (physicalPages[i] == 0)
                {
                    freeMemory += PAGE_SIZE;
                }
            }
            return freeMemory;
        }

    private:
        // initialize all elements in the physical page table to 0(unallocated)
        int physicalPages[PHYSICAL_MEMORY_SIZE / PAGE_SIZE] = {0};
};