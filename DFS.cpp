#include "DFS.h"
#include <algorithm>

DFS::DFS(AdList* adlist) : ad{adlist}{
    vector<int> verts(adlist->GetSize());
    this->verts = verts;
    vector<int> path(this->verts.size());
    this->path = path;
};

AdList* DFS::GetAd(){
    return this->ad;
}

stack<int> DFS::Init(int s){
    int i = 0;
    for(auto& u : this->verts){
        this->path[i] = -1;
        u = State::unknown;
        i++;
    }
    this->verts.at(s) = State::discovered;
    stack<int> stack;
    stack.push(s);
    return stack;
}

void DFS::ProcessDiscoveredVertex(int u){
    auto stack = &this->to_be_processed;
    this->verts.at(u) = State::current;
    vector<int> adjacent = this->ad->GetAdjacent(u);
    random_shuffle(adjacent.begin(), adjacent.end());
    for(auto vert : adjacent){
        if(this->verts.at(vert) == State::unknown){
            this->verts.at(vert) = State::discovered;
            this->path[vert] = u;
            stack->push(vert);
        }
    }
}

void DFS::ProcessCurrentVertex(int u){
    auto stack = &this->to_be_processed;
    this->verts.at(u) = State::finished;
    stack->pop();
}

vector<int> DFS::Run(int starting_vertex){
    this->to_be_processed = this->Init(starting_vertex);
    while(!this->to_be_processed.empty()){
        int u = this->to_be_processed.top();
        int state = this->verts.at(u);
        switch(state){
            case State::discovered:
                this->ProcessDiscoveredVertex(u);
                break;
            case State::current:
                this->ProcessCurrentVertex(u);
                break;
        }
    }
    return this->path;
}
