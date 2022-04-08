#include <fstream>
#include <iostream>
#include <vector>
#include "SVG.h"

using namespace std;

vector<int> SVG::color = {0, 0, 0};
int SVG::linewidth = 5;
int SVG::multiplier = 50;

SVG::SVG(string path, int width, int height){
    this->width = width;
    this->height = height;
    this->path = path;
    this->file.open(path);
    this->file << "<svg height=\"" << SVG::multiplier*height + 2*SVG::multiplier<< "\" width=\"" << SVG::multiplier*width + 2*SVG::multiplier<< "\">\n";
}

SVG::~SVG(){
    this->file << "</svg>";
    this->file.close();
}

void SVG::CreateLine(int x1, int y1, int x2, int y2){
    int m = SVG::multiplier;
    x1*=m;y1*=m;x2*=m;y2*=m;
    this->file << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\""<< y2 << "\" style=\"stroke:rgb(" << SVG::color[0] << "," << SVG::color[1] << ","<<SVG::color[2] << ");stroke-width:" << SVG::linewidth << "\"; fill=\"pink\" />\n";
}

void SVG::CreateLine(int row, int col, bool horizontal){
    row+=1;
    col+=1;
    horizontal ? this->CreateLine(col+1, row, col+1, row+1) : this->CreateLine(col, row+1, col+1, row+1);
}
