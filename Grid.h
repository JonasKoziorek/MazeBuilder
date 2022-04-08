#pragma once
#include "SVG.h"
#include "AdList.h"

enum Direction{
    South,
    West, 
    North,
    East
};

class Grid{
    /**
     * @brief Grid class represents grid of rectangular cells.
     */
    public:
        Grid(int width, int height);
        /** 
         * Creates adjacency list (of AdList type) for grid with dims. m * n 
         */
        AdList CreateGraph();
        /** 
          Creates image of a maze
        */
        void CreateMaze(SVG* svg, vector<int> path); 
        /** 
         * operator overload to pretty print Grid class 
         */
        friend ostream& operator<<(ostream& is, const Grid grid);     private:
        /** 
         * Grid width 
         */
        unsigned int width;
        /** 
         * Grid height 
         */
        unsigned int height; 
        /**
         * Removes connected walls from this->grid.
         * @param path - i-th entry in path corresponds to Node from which DFS algorithms got to i-th Node
         */
        void BreachWalls(vector<int> path);
        /** 
         * Convert 2d array indices to 1d array index 
        */
        int FormatIndex(int i, int j); 
        /** 
         * Convert 1d array index to 2d array indices
        */
        vector<int> FormatIndex(int i);
        /**
         * @brief Cell class represent one grid cell in a grid.  
         */
        struct Cell{
            /** 
             * true if northern wall of a cell exists
             */
            bool north = true;
             /** 
              * true if southern wall of a cell exists
              */ 
            bool south = true;
            /** 
             * true if western wall of a cell exists
             */
            bool west = true;
            /** 
             * true if eastern wall of a cell exists
             */
            bool east = true; 
        }; 
        /** 
         * Each cell in grid of dims m*n.
         */
        vector<vector<Cell>> grid;
};
