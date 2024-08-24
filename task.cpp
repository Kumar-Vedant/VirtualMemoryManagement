#include <bits/stdc++.h>


const int PAGE_SIZE = 1024; // 1KB
const int PHYSICAL_MEMORY_SIZE = 65536; // 64KB
const int VIRTUAL_MEMORY_SIZE = 65536; // 64KB

class Task
{
    public:
        Task(int taskID, int logicalAddress, int size)
        {
            // call the memory manager's allocateMemory function for the required size
            // vector<int> physicalPages = memoryManager.allocateMemory(taskID, logicalAddress, size);
            
            // calculate the logical address of the first page required
            // int pageNumber = ;

            // store the physical address returned by the memory manager
            // for (int i = 0; i < physicalPages.size(); i++)
            // {
            //     // pageTable[pageNumber] = physicalPages[i];
            // }
            
        }

    private:
        int pageTable[VIRTUAL_MEMORY_SIZE / PAGE_SIZE];
};