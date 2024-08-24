#include <bits/stdc++.h>

#include "include/memoryManager.h"

const int PAGE_SIZE = 1024; // 1KB
const int PHYSICAL_MEMORY_SIZE = 65536; // 64KB
const int VIRTUAL_MEMORY_SIZE = 65536; // 64KB

class TaskSingleLevel
{
    public:
        TaskSingleLevel(int taskID, MemoryManager memoryManager)
        {
            this->taskID = taskID;
            this->memoryManager = memoryManager;
        }
        void allocateMemory(int logicalAddress, int size)
        {
            // call the memory manager's allocatePages function for the required size
            vector<int> physicalPages = memoryManager.allocatePages(size);
            
            // calculate the logical address of the first page required
            // int startingPageNumber = ;

            // store the physical address returned by the memory manager
            for (int i = 0; i < physicalPages.size(); i++)
            {
                // pageTable[startingPageNumber + i] = physicalPages[i];
            }
        }

    private:
        int taskID;
        MemoryManager memoryManager;
        int pageTable[VIRTUAL_MEMORY_SIZE / PAGE_SIZE];
};
class TaskTwoLevel
{
    public:
        TaskTwoLevel(int taskID, MemoryManager memoryManager)
        {
            this->taskID = taskID;
            this->memoryManager = memoryManager;
        }
        void allocateMemory(int logicalAddress, int size)
        {
            // call the memory manager's allocatePages function for the required size
            vector<int> physicalPages = memoryManager.allocatePages(size);
            
            // calculate the logical address of the first page required
            // int startingPageNumber = ;

            // store the physical address returned by the memory manager
            for (int i = 0; i < physicalPages.size(); i++)
            {
                // store the physical page number in the correct matrix element

                // pageTable[startingPageNumber + i][] = physicalPages[i];
            }
        }

    private:
        int taskID;
        MemoryManager memoryManager;

        // make a matrix for page tables
        // int pageTable[VIRTUAL_MEMORY_SIZE / PAGE_SIZE][VIRTUAL_MEMORY_SIZE / PAGE_SIZE];

};
class TaskMap
{
    public:
        TaskMap(int taskID, MemoryManager memoryManager)
        {
            this->taskID = taskID;
            this->memoryManager = memoryManager;
        }
        void allocateMemory(int logicalAddress, int size)
        {
            // call the memory manager's allocatePages function for the required size
            vector<int> physicalPages = memoryManager.allocatePages(size);
            
            // calculate the logical address of the first page required
            // int startingPageNumber = ;

            // store the physical address returned by the memory manager
            for (int i = 0; i < physicalPages.size(); i++)
            {
                // pageTable[startingPageNumber + i] = physicalPages[i];
            }
        }

    private:
        int taskID;
        MemoryManager memoryManager;

        // make a map for page tables
        map<int, int> pageTable;
};