#include <vector>

using namespace std;

class MemoryManager
{
    public:
        MemoryManager();
        vector<int> allocatePages(long long size);
        int getFreePhysicalMemory();
};