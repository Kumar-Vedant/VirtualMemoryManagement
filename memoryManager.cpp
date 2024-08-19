#include <bits/stdc++.h>

using namespace std;

class MemoryManager
{
    public:
        // create the required no. of pages initially
        MemoryManager(int totalPages)
        {
            for (int i = 0; i < totalPages; i++)
            {
                // create pages
                availablePages.push_back(i);
            }
            
        }
        
        // gives a physical page address 
        int allocatePage()
        {
            // if no page is available, return error

            // allocate the first available page

            // remove the page from the list of availablePages
        }

    private:
        vector<int> availablePages;
};