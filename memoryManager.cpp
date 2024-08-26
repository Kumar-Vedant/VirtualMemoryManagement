#include <bits/stdc++.h>

#include "include/config.h"

using namespace std;

class MemoryManager
{
    public:
        // gives a physical page address 
        vector<int> allocatePages(long long size)
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

                
                // if all required pages are allocated, break
                if (physicalPagesAllocated.size() == numberOfPages)
                {
                    break;
                }
            }
            // if no page is available, return error
            if (physicalPagesAllocated.size() < numberOfPages)
            {
                cout << "Error: Not enough memory available" << endl;
            }
            
            // return the indexes of the physical pages allocated
            return physicalPagesAllocated;
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
        int physicalPages[PHYSICAL_PAGES] = {0};
};