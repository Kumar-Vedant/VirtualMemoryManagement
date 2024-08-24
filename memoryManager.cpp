#include <bits/stdc++.h>

using namespace std;

// values to be read from config.h
const int PAGE_SIZE = 1024; // 1KB
const int PHYSICAL_MEMORY_SIZE = 65536; // 64KB
const int VIRTUAL_MEMORY_SIZE = 65536; // 64KB

class MemoryManager
{
    public:
        // create the required no. of pages initially
        MemoryManager(int numberOfTasks)
        {
            
        }
        
        // gives a physical page address 
        vector<int> allocatePage(int taskID, int size)
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

    private:
        // initialize all elements in the physical page table to 0(unallocated)
        int physicalPages[PHYSICAL_MEMORY_SIZE / PAGE_SIZE] = {0};
};