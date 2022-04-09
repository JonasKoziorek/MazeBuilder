#pragma once
#include "AdList.h"
#include <stack>

/** Enumeration of possible vertex states for DFS algorithm.
 * 
 */
enum State{
    unknown, discovered, current, finished
};

/** Class for Depth First Search (DFS) algorithm.
 */
class DFS{
    private:
        /** adjacency list
         */
        AdList* ad;
        /** i-th element in path corresponds to a vertex from which dfs algorithm gets to i-th vertex.
         */
        vector<int> path;
        /** State at which i-th vertex is. (Discovered, Current, Finished or Unknown) 
         */
        vector<int> verts; 
        /** Initializes the dfs algorithm.
         * @param s - index of vertex where the algorithm should begin.
         */
        stack<int> Init(int s);
        /** stack of vertex indices which are to be processed by dfs
         */
        stack<int> to_be_processed;
        /** Searches for neigboring unknown vertices and adds them to to_be_processed stack
         * @param u - index of vertex to be processed
         */
        void ProcessDiscoveredVertex(int u);
        /** Finishes current vertex and removes it from the to_be_processed stack
         * @param u - index of vertex to be processed
         */
        void ProcessCurrentVertex(int u);
        AdList* GetAd();
    public:
        DFS(AdList* adlist);
        /** Run the DFS algorithm.
         * @param starting_vertex - index of vertex to start with
         * @return this->path
         */
        vector<int> Run(int starting_vertex);
};
