#include <iostream>
#include <fstream>
#include <cstdlib>

#include "include/IOModule.h"
#include "include/performanceModule.h"
#include "include/config.h"

using namespace std;

int getNumberOfTasks();
void generateTraceFile(int numberOfTasks);
string intToBin(long long n);
string binToHex(string binary);

int main()
{
    int numberOfTasks = getNumberOfTasks();
    
    // generate trace file with the format taskID:logicalAddress:size
    generateTraceFile(numberOfTasks);

    // initialize the performance module
    PerformanceModule performanceModule();

    return 0;
}

int getNumberOfTasks() 
{
    int numberOfTasks;
    cout << "Enter the number of tasks: ";
    cin >> numberOfTasks;
    return numberOfTasks;
}

void generateTraceFile(int numberOfTasks)
{
    ofstream traceFile;
    traceFile.open("trace.txt");
    for (int i = 0; i < 1000000; i++)
    {
        // generate random taskID from 1 to numberOfTasks
        int taskID = rand() % numberOfTasks + 1;
        
        // generate random logical address from 0 to VIRTUAL_PAGES
        long long logicalAddress = rand() % VIRTUAL_PAGES;

        // convert to binary
        string logicalAddressBinary = intToBin(logicalAddress);

        // add random bits for offset
        for (int i = 0; i < BITS_PAGE_SIZE; i++)
        {
            // generate a random number from either 0 or 1
            int randomNumber = rand() % 2;
            logicalAddressBinary = logicalAddressBinary + to_string(randomNumber);
        }
        
        // convert to hexadecimal
        string logicalAddressHex = binToHex(logicalAddressBinary);
        logicalAddressHex = "0x" + logicalAddressHex;
        
        int minPageSize = PAGE_SIZE / (1LL<<10);
        int size = (rand() % 10 + 1) * minPageSize;
        
        traceFile << "T" << taskID << ":" << logicalAddressHex << ":" << size << endl;
    }
    traceFile.close();
}


// function to convert integer to binary
string intToBin(long long n)
{
    return bitset<32>(n).to_string();
}

// function to convert binary to hexadecimal
string binToHex(string binary)
{
    // Pad the binary string to ensure its length is a multiple of 4
    int padding = (4 - binary.length() % 4) % 4;
    binary = string(padding, '0') + binary;

    string hex = "";
    for (int i = 0; i < binary.length(); i += 4)
    {
        string nibble = binary.substr(i, 4);
        if (nibble == "0000")
        {
            hex += "0";
        }
        else if (nibble == "0001")
        {
            hex += "1";
        }
        else if (nibble == "0010")
        {
            hex += "2";
        }
        else if (nibble == "0011")
        {
            hex += "3";
        }
        else if (nibble == "0100")
        {
            hex += "4";
        }
        else if (nibble == "0101")
        {
            hex += "5";
        }
        else if (nibble == "0110")
        {
            hex += "6";
        }
        else if (nibble == "0111")
        {
            hex += "7";
        }
        else if (nibble == "1000")
        {
            hex += "8";
        }
        else if (nibble == "1001")
        {
            hex += "9";
        }
        else if (nibble == "1010")
        {
            hex += "A";
        }
        else if (nibble == "1011")
        {
            hex += "B";
        }
        else if (nibble == "1100")
        {
            hex += "C";
        }
        else if (nibble == "1101")
        {
            hex += "D";
        }
        else if (nibble == "1110")
        {
            hex += "E";
        }
        else if (nibble == "1111")
        {
            hex += "F";
        }
    }
    return hex;
}