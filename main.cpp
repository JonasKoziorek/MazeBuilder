#include <iostream>
#include "SVG.h"
#include "Grid.h"
#include "DFS.h"

using namespace std;

int main(){
    // height of a maze
    const int m = 4;
    // width of a maze
    const int n = 4;
    srand(time(0));
    SVG svg = {"maze.html", n, m};
    Grid grid = {n, m};
    AdList ad = grid.CreateGraph();
    DFS dfs = DFS(&ad);
    grid.CreateMaze(&svg, dfs.Run(0) );
    return 0;
}
