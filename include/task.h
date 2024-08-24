#include "include/memoryManager.h"

class TaskSingleLevel
{
    public:
        TaskSingleLevel(int taskID, MemoryManager memoryManager);
        void allocateMemory(int logicalAddress, int size);
};
class TaskTwoLevel
{
    public:
        TaskTwoLevel(int taskID, MemoryManager memoryManager);
        void allocateMemory(int logicalAddress, int size);
};
class TaskMap
{
    public:
        TaskMap(int taskID, MemoryManager memoryManager);
        void allocateMemory(int logicalAddress, int size);
};