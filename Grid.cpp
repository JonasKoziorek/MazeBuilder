#include "Grid.h"
#include <iomanip>
#include <algorithm>

ostream& operator<<(ostream& os, const Grid grid){
    int m = grid.height;
    int n = grid.width;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            os << setw(5) << i*n+j;
        }
        os << endl;
    }
    return os;
}

Grid::Grid(int width, int height){
    this->width = width;
    this->height = height;
    vector<vector<Cell>> grid(height, vector<Cell>(width) );
    this->grid = grid; 
}

int Grid::FormatIndex(int i, int j){
    return this->width * i + j;
}

vector<int> Grid::FormatIndex(int i){
    vector<int> vect(2);
    vect[0] = i / this->width;
    vect[1] = i % this->width;
    return vect;
}

AdList Grid::CreateGraph(){
    // create adjacency list for grid of interconnected cells 
    int n = this->width;
    int m = this->height;
    vector<vector<int>> adlist(n*m, vector<int>());
    for(int i = 1; i < m-1; i++){
        // interior cells
        for(int j = 1; j < n-1; j++){
            vector<int> temp = {this->FormatIndex(i+1, j),this->FormatIndex(i-1, j),this->FormatIndex(i, j+1),this->FormatIndex(i, j-1)};
            adlist[i * n + j] = temp;
        }
        // vertical borders
        vector<int> temp1 = {this->FormatIndex(i+1, 0),this->FormatIndex(i-1, 0),this->FormatIndex(i, 1)};
        adlist[i * n] = temp1;
        vector<int> temp2 = {this->FormatIndex(i+1, n-1),this->FormatIndex(i-1, n-1),this->FormatIndex(i, n-2)};
        adlist[i * n +n-1] = temp2;
    }
    // horizontal borders
    for(int j = 1; j < n-1; j++){
        vector<int> temp1 = {this->FormatIndex(1, j),this->FormatIndex(0, j-1), this->FormatIndex(0, j+1)};
        adlist[j] = temp1;
        vector<int> temp2 = {this->FormatIndex(m-2, j),this->FormatIndex(m-1, j-1), this->FormatIndex(m-1, j+1)};
        adlist[(m-1)*n + n-1] = temp2;
    }
    // top left corner
    adlist[0] = {this->FormatIndex(1, 0),this->FormatIndex(0, 1)};
    // top right corner
    adlist[n-1] = {this->FormatIndex(0, n-2),this->FormatIndex(1, n-1)};
    // bottom leff corner
    adlist[(m-1)*n] = {this->FormatIndex(m-2, 0),this->FormatIndex(m-1, 1)};
    // bottom right corner
    adlist[(m-1)*n + n-1] = {this->FormatIndex(m-1, n-2),this->FormatIndex(m-2, n-1)};

    AdList adl = {adlist};
    return adl;
}

int CheckDirection(vector<int> idims, vector<int> pdims){
    if(idims[0]+1 == pdims[0]){
        return Direction::North;
    }
    else if(idims[0] == pdims[0]+1){
        return Direction::South;
    }
    else if(idims[1] == pdims[1]+1){
        return Direction::East;
    }
    else if(idims[1] +1 == pdims[1]){
        return Direction::West;
    }
   return 0; 
}

void Grid::BreachWalls(vector<int> path){
    for(int i = 0; i < path.size(); i++){
        if(path[i] != -1){
            auto idims = this->FormatIndex(i);
            auto pdims = this->FormatIndex(path[i]);
            switch(CheckDirection(idims, pdims)){
                case Direction::North:
                    this->grid[idims[0]][idims[1]].south = false;
                    this->grid[pdims[0]][pdims[1]].north = false;
                    break;
                case Direction::West:
                    this->grid[idims[0]][idims[1]].east = false;
                    this->grid[pdims[0]][pdims[1]].west = false;
                    break;
                case Direction::East:
                    this->grid[idims[0]][idims[1]].west = false;
                    this->grid[pdims[0]][pdims[1]].east = false;
                    break;
                case Direction::South:
                    this->grid[idims[0]][idims[1]].north = false;
                    this->grid[pdims[0]][pdims[1]].south = false;
                    break;
            }
        }
    }
}

void Grid::CreateMaze(SVG* image, vector<int> path){
    int height = this->height;
    int width = this->width;
    this->BreachWalls(path);
    int h = 0; int w = 0;
    for(auto i : this->grid){
        for(auto j : i){
            if(j.north){
                image->CreateLine(h-1, w, false);
            }
            if(j.west){
                image->CreateLine(h, w-1, true);
            }
            if(j.east){
                image->CreateLine(h, w, true);
            }
            if(j.south){
                image->CreateLine(h, w, false);
            }
            w++;
        }
        h++;
        w=0;
    }
    return;
}
