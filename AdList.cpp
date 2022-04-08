#include "AdList.h"

vector<int> AdList::GetAdjacent(int v){
            return this->data[v];
}

AdList::AdList(vector<vector<int>> data){
    this->data = data;
}

int AdList::GetSize(){
    return this->data.size();
}
