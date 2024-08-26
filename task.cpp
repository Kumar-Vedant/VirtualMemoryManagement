#include <bits/stdc++.h>
#include <sstream>
#include <bitset>

#include "include/memoryManager.h"
#include "include/config.h"

using namespace std;

class TaskMap
{
    public:
        TaskMap(int taskID, MemoryManager memoryManager)
        {
            this->taskID = taskID;
            this->memoryManager = memoryManager;
        }
        void allocateMemory(string logicalAddress, long long size)
        {
            // call the memory manager's allocatePages function for the required size
            vector<int> physicalPages = memoryManager.allocatePages(size);
            
            // calculate the logical address of the first page required
            string binaryAddress = hexToBin(logicalAddress);
            // remove the offset bits from the logical address
            long startingPageNumber = trimBinaryToDecimal(binaryAddress, BITS_PAGE_SIZE);

            // store the physical address returned by the memory manager
            for (int i = 0; i < physicalPages.size(); i++)
            {
                // if the page number is already allocated, report page table hit
                if (pageTable.count(startingPageNumber + i) != 0)
                {
                    cout << "Page table hit" << endl;
                }
                pageTable[startingPageNumber + i] = physicalPages[i];
            }
        }
        int getTaskID()
        {
            return taskID;
        }

    private:
        int taskID;
        MemoryManager memoryManager;

        // make a map for page tables
        map<int, int> pageTable;
};

class TaskSingleLevel
{
    public:
        TaskSingleLevel(int taskID, MemoryManager memoryManager)
        {
            this->taskID = taskID;
            this->memoryManager = memoryManager;
        }
        void allocateMemory(string logicalAddress, long long size)
        {
            // call the memory manager's allocatePages function for the required size
            vector<int> physicalPages = memoryManager.allocatePages(size);
            
            // calculate the page number of the first page required from the logical address

            string binaryAddress = hexToBin(logicalAddress);
            // remove the offset bits from the logical address
            long startingPageNumber = trimBinaryToDecimal(binaryAddress, BITS_PAGE_SIZE);

            // store the physical address returned by the memory manager
            for (int i = 0; i < physicalPages.size(); i++)
            {
                // if the page number is greater than the number of virtual pages, report page table miss
                if (startingPageNumber + i >= VIRTUAL_PAGES)
                {
                    cout << "Page table miss" << endl;
                }
                // if the page is already allocated, report page table hit
                if (pageTable[startingPageNumber + i] != 0)
                {
                    cout << "Page table hit" << endl;
                }
                pageTable[startingPageNumber + i] = physicalPages[i];
            }
        }
        int getTaskID()
        {
            return taskID;
        }
    private:
        int taskID;
        MemoryManager memoryManager;
        int pageTable[VIRTUAL_PAGES];

};
class TaskTwoLevel
{
    public:
        TaskTwoLevel(int taskID, MemoryManager memoryManager)
        {
            this->taskID = taskID;
            this->memoryManager = memoryManager;
        }
        void allocateMemory(string logicalAddress, long long size)
        {
            // call the memory manager's allocatePages function for the required size
            vector<int> physicalPages = memoryManager.allocatePages(size);

            // convert the logical address to binary
            string binaryAddress = hexToBin(logicalAddress);
            // remove the offset bits from the logical address
            long startingPageNumber = trimBinaryToDecimal(binaryAddress, BITS_PAGE_SIZE);
            
            // calculate the page number of the first page required in the 1st level page table from the logical address
            long startingPageNumber1 = trimBinaryToDecimal(to_string(startingPageNumber), PTS_1);

            // calculate the page number of the first page required in the 2nd level page table from the logical address
            long startingPageNumber2 = trimBinaryToDecimal(to_string(startingPageNumber).substr(PTS_2), 0);

            // store the physical address returned by the memory manager
            for (int i = 0; i < physicalPages.size(); i++)
            {
                // if the page number is greater than the number of virtual pages, report page table miss
                if (startingPageNumber1 >= PAGE_TABLE_SIZE_1 || startingPageNumber2 + i >= PAGE_TABLE_SIZE_2)
                {
                    cout << "Page table miss" << endl;
                }
                // if the page is already allocated, report page table hit
                if (pageTable[startingPageNumber1][startingPageNumber2 + i] != 0)
                {
                    cout << "Page table hit" << endl;
                }

                // store the physical page number in the correct matrix element
                pageTable[startingPageNumber1][startingPageNumber2 + i] = physicalPages[i];
            }
        }
        int getTaskID()
        {
            return taskID;
        }

    private:
        int taskID;
        MemoryManager memoryManager;

        // make a matrix for page tables
        int pageTable[PAGE_TABLE_SIZE_1][PAGE_TABLE_SIZE_2];

};

string hexToBin(const string& s) 
{
    stringstream ss;
    ss << hex << s;
    unsigned n;
    ss >> n;
    bitset<32> bin(n);

    // Convert the resulting binary back to a string
    return bin.to_string();
}

long trimBinaryToDecimal(string binary, int bits)
{
    bitset<32> bin(binary);

    bin >> bits;

    return bin.to_ulong();
}