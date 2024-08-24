#include <bits/stdc++.h>

using namespace std;

class IOModule
{
    public:
        IOModule()
        {
            // read the trace file
            ifstream traceFile("trace.txt");
            string trace;
            while (getline(traceFile, trace))
            {
                createTaskInstance(trace);
            }
        }
        void createTaskInstance(string trace)
        {
            // split the trace into task ID, Logical address and size
            vector<string> tokens = split(trace, ':');

            // convert taskID string(T1, T2, etc.) to int(1, 2, etc.)
            int taskID = stoi(tokens[0].substr(1));

            int logicalAddress = stoi(tokens[1]);
            int size = stoi(tokens[2]);

            // create an object of the Task class
            // Task task(int taskID, int logicalAddress, int size);
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
