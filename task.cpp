#include <bits/stdc++.h>
#include <sstream>
#include <bitset>

#include "include/memoryManager.hpp"
#include "include/config.h"

using namespace std;

string hexToBin(const string& s);
long trimBinaryToDecimal(string binary, int bits);

#include "include/task.hpp"

// TaskMap class implementation
TaskMap::TaskMap(int taskID, MemoryManager memoryManager)
{
    pageTableHits = 0;
    this->taskID = taskID;
    this->memoryManager = memoryManager;
}

int TaskMap::getPageTableHits()
{
    return pageTableHits;
}
int TaskMap::getPageTableMisses()
{
    return pageTableMisses;
}

void TaskMap::allocateMemory(string logicalAddress, long long size)
{
    vector<int> physicalPages = memoryManager.allocatePages(size);

    string binaryAddress = hexToBin(logicalAddress);
    long startingPageNumber = trimBinaryToDecimal(binaryAddress, BITS_PAGE_SIZE);

    for (int i = 0; i < physicalPages.size(); i++) {
        if (pageTable.count(startingPageNumber + i) != 0)
        {
            pageTableHits++;
            break;
        }
        pageTable[startingPageNumber + i] = physicalPages[i];
    }
}

int TaskMap::getTaskID() 
{
    return taskID;
}

TaskSingleLevel::TaskSingleLevel(int taskID, MemoryManager memoryManager)
{
    pageTableHits = 0;
    pageTable = new int[VIRTUAL_PAGES];  // Page table for the task

    this->taskID = taskID;
    this->memoryManager = memoryManager;

    for (int i = 0; i < VIRTUAL_PAGES; i++) {
        pageTable[i] = 0;
    }
}

int TaskSingleLevel::getPageTableHits()
{
    return pageTableHits;
}

int TaskSingleLevel::getPageTableMisses()
{
    return pageTableMisses;
}
void TaskSingleLevel::allocateMemory(string logicalAddress, long long size)
{
    vector<int> physicalPages = memoryManager.allocatePages(size);

    string binaryAddress = hexToBin(logicalAddress);
    long startingPageNumber = trimBinaryToDecimal(binaryAddress, BITS_PAGE_SIZE);

    // store the physical page number in the page table
    for (int i = 0; i < physicalPages.size(); i++)
    {
        // if the virtual page number requested is out of bounds
        if (startingPageNumber + i >= VIRTUAL_PAGES)
        {
            cout << "Page table miss" << endl;
            break;
        }
        if (pageTable[startingPageNumber + i] != 0)
        {
            pageTableHits++;
            break;
        }
        pageTable[startingPageNumber + i] = physicalPages[i];
    }
}

int TaskSingleLevel::getTaskID()
{
    return taskID;
}

// TaskTwoLevel class implementation

TaskTwoLevel::TaskTwoLevel(int taskID, MemoryManager memoryManager)
{
    pageTableHits = 0;
    this->taskID = taskID;
    this->memoryManager = memoryManager;

    for (int i = 0; i < PAGE_TABLE_SIZE_1; i++) {
        for (int j = 0; j < PAGE_TABLE_SIZE_2; j++) {
            pageTable[i][j] = 0;
        }
    }
}

int TaskTwoLevel::getPageTableHits()
{
    return pageTableHits;
}

int TaskTwoLevel::getPageTableMisses()
{
    return pageTableMisses;
}
void TaskTwoLevel::allocateMemory(string logicalAddress, long long size) {
    vector<int> physicalPages = memoryManager.allocatePages(size);

    string binaryAddress = hexToBin(logicalAddress);
    binaryAddress = binaryAddress.substr(0, binaryAddress.size() - BITS_PAGE_SIZE);
    // long startingPageNumber = trimBinaryToDecimal(binaryAddress, BITS_PAGE_SIZE);

    string s1 = binaryAddress.substr(0, PTS_1);
    string s2 = binaryAddress.substr(PTS_2);
    
    long startingPageNumber1 = trimBinaryToDecimal(s1, 0);
    long startingPageNumber2 = trimBinaryToDecimal(s2, 0);

    for (int i = 0; i < physicalPages.size(); i++)
    {
        if (startingPageNumber1 >= PAGE_TABLE_SIZE_1 || startingPageNumber2 + i >= PAGE_TABLE_SIZE_2)
        {
            cout << "Page table miss" << endl;
            break;
        }
        if (pageTable[startingPageNumber1][startingPageNumber2 + i] != 0)
        {
            pageTableHits++;
            break;
        }

        pageTable[startingPageNumber1][startingPageNumber2 + i] = physicalPages[i];
    }
}

int TaskTwoLevel::getTaskID()
{
    return taskID;
}

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

    bin >>= bits;

    return bin.to_ulong();
}