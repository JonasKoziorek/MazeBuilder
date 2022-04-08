#pragma once
#include "AdList.h"
#include <stack>

/** Enumeration of possible vertex states for DFS algorithm.
 * 
 */
enum State{
    unknown, discovered, current, finished
};

class DFS{
    private:
        AdList* ad;
        vector<int> path;
        vector<int> verts; /** State at which i-th vertex is. (Discovered, Current, Finished or Unknown) */
        stack<int> Init(int s);
        stack<int> to_be_processed;
        void ProcessDiscoveredVertex(int u);
        void ProcessCurrentVertex(int u);
        AdList* GetAd();
    public:
        DFS(AdList* adlist);
        vector<int> Run(int starting_vertex);
};
