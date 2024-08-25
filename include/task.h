#include "include/memoryManager.h"

class TaskMap
{
    public:
        TaskMap(int taskID, MemoryManager memoryManager);
        void allocateMemory(string logicalAddress, int size);
        int getTaskID();
};
class TaskSingleLevel
{
    public:
        TaskSingleLevel(int taskID, MemoryManager memoryManager);
        void allocateMemory(string logicalAddress, int size);
        int getTaskID();
};
class TaskTwoLevel
{
    public:
        TaskTwoLevel(int taskID, MemoryManager memoryManager);
        void allocateMemory(string logicalAddress, int size);
        int getTaskID();
};