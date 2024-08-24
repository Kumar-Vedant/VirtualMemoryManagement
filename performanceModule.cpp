#include <bits/stdc++.h>

using namespace std;

const int PAGETABLE_ENTRY_SIZE;
const int PAGETABLE_SIZE;

class PerformanceModule
{
    public:
        PerformanceModule()
        {
            // initialize the total no. of pages, memory per page (maybe? idk)
        }

        void allocateTaskMemory(int taskID)
        {
            // maps the task ID to the memory allocated to it
        }

        void deallocateTaskMemory(int taskID)
        {
            // remove the map entry of the given task ID
        }

        // return the total memory required for page tables
        int getTotalMemory()
        {
            return PAGETABLE_ENTRY_SIZE * PAGETABLE_SIZE;
        }

        // return the total memory - memory allocated to each task
        int getFreeMemory()
        {
            
            int memoryUsed = 0;
            for (int i = 0; i < taskMemory.size(); i++)
            {
                memoryUsed += taskMemory[i];
            }
            
            return getTotalMemory() - memoryUsed;
        }
    private:
        // maps task ID to allocated space
        map<int, int> taskMemory;
};
