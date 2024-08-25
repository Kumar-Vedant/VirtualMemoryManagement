class IOModule
{
    public:
        IOModule(int implementation);
        map<int, int> getTaskMemoryAllocated();
        int getFreePhysicalMemory();
};
