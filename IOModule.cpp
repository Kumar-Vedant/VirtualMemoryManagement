#include <bits/stdc++.h>

using namespace std;

class IOModule
{
    public:
        IOModule()
        {
            // initialize the total no. of pages, memory per page (maybe? idk)
        }
        void createTaskInstance(string trace)
        {
            // split the trace into task ID, Logical address and size
            // create an object of the Task class
        }
    private:
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
};
