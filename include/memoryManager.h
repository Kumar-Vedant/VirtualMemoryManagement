#include <vector>

using namespace std;

class MemoryManager
{
    public:
        vector<int> allocatePages(long long size);
        int getFreePhysicalMemory();
};