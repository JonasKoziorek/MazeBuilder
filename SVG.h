#pragma once
#include <vector>
#include <string>
#include <fstream>


class SVG{
    private:
        std::string path;
        std::ofstream file;        
    public:
        static std::vector<int> color;
        static int linewidth;
        static int multiplier;
        int width;
        int height;
        void CreateLine(int x1, int y1, int x2, int y2);
        void CreateLine(int row, int col, bool horizontal);
        SVG(std::string path, int width, int height);
        ~SVG();
};
