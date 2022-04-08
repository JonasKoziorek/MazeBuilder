#pragma once
#include <vector>
#include <iostream>

using namespace std;

// adjacency list
class AdList{
    private:
        vector<vector<int>> data; /** i-th element corresponds to all vertices adjacent to i-th vertex */
    public:
        vector<int> GetAdjacent(int v);
        int GetSize();
        AdList(vector<vector<int>> data);
};
