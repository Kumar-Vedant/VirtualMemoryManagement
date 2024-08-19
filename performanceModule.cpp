#include <bits/stdc++.h>

using namespace std;

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

        int getTotalMemory(){
            // return the total memory 
        }

        int getFreeMemory(){
            // return the total memory - memory allocated to each task
        }
    private:
        // maps task ID to allocated space
        unordered_map<int, vector<int>> taskMemory;
};
