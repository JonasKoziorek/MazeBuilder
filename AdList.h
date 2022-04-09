#pragma once
#include <vector>
#include <iostream>

using namespace std;

/** Simple Adjacency List (AdList) class.
 */
class AdList{
    private:
        /** i-th element corresponds to all vertices adjacent to i-th vertex 
         */
        vector<vector<int>> data;    
    public:
        vector<int> GetAdjacent(int v);
        /** size of this->data
         */
        int GetSize();
        AdList(vector<vector<int>> data);
};
