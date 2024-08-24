#include <bits/stdc++.h>

#include "include/memoryManager.h"
#include "include/task.h"

using namespace std;

class IOModule
{
    public:
        IOModule(int implementation)
        {
            this->implementation = implementation;
            
            // read the trace file
            ifstream traceFile("trace.txt");
            string trace;
            while (getline(traceFile, trace))
            {
                AllocateMemoryToTask(trace, implementation);
            }

            // initialize the memory manager
            MemoryManager memoryManager();
        }

        map<int, int> getTaskMemoryAllocated()
        {
            return taskMemoryAllocated;
        }

        int getMemoryForPagetable()
        {
            // get information from the memory manager and return the total memory required for page tables for the current implementation
        }

        int getFreePhysicalMemory()
        {
            return memoryManager.getFreePhysicalMemory();
        }
    private:
        void AllocateMemoryToTask(string trace, int implementation)
        {
            // split the trace into task ID, Logical address and size
            vector<string> tokens = split(trace, ':');

            // convert taskID string(T1, T2, etc.) to int(1, 2, etc.)
            int taskID = stoi(tokens[0].substr(1));

            int logicalAddress = stoi(tokens[1]);
            int size = stoi(tokens[2]);

            // check if the task already exists
            // if it does, call the allocateMemory function

            taskMemoryAllocated[taskID] += size;
            
            // else, create a new task object

            // if implementation is 0, create a TaskSingleLevel object
            if(implementation == 0)
            {
                TaskSingleLevel task(taskID, memoryManager);
                tasksSingleLevel.push_back(task);
                
                // allocate memory to the task
                task.allocateMemory(logicalAddress, size);

                taskMemoryAllocated[taskID] = size;
            }
            // if implementation is 1, create a TaskTwoLevel object
            else if(implementation == 1)
            {
                TaskTwoLevel task(taskID, memoryManager);
                tasksTwoLevel.push_back(task);

                // allocate memory to the task
                task.allocateMemory(logicalAddress, size);

                taskMemoryAllocated[taskID] = size;
            }
            // if implementation is 2, create a TaskMap object
            else if(implementation == 2)
            {
                TaskMap task(taskID, memoryManager);
                tasksMap.push_back(task);

                // allocate memory to the task
                task.allocateMemory(logicalAddress, size);
            
                taskMemoryAllocated[taskID] = size;
            }
        }

        // function that separates a string based on a delimiter
        vector<string> split(string trace, char delimiter)
        {
            vector<string> tokens;
            string token;
            istringstream tokenStream(trace);
            while (getline(tokenStream, token, delimiter))
            {
                tokens.push_back(token);
            }
            return tokens;
        }
        MemoryManager memoryManager;
        
        vector<TaskSingleLevel> tasksSingleLevel;
        vector<TaskTwoLevel> tasksTwoLevel;
        vector<TaskMap> tasksMap;

        map<int, int> taskMemoryAllocated;

        int implementation;
};
