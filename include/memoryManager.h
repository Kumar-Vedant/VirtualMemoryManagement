#include <vector>

using namespace std;

class MemoryManager
{
    public:
        MemoryManager();
        vector<int> allocatePages(int size);
        int getFreePhysicalMemory();
};