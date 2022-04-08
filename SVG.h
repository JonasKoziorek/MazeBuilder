#pragma once
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/** SVG class for creating html SVG images.
 * Provides simple functions for drawing geometric shapes such as Lines.
 */
class SVG{
    private:
        /** Name of a file where SVG data will be saved.
         */
        string path;
        /** File where SVG date will be saved.
         */
        ofstream file;        
    public:
        /** Default color.
         */
        static vector<int> color;
        /** Default line width.
         */
        static int linewidth;
        /** Default constant which scales dimensions inputed in SVG methods. eg. making images smaller or bigger
         */
        static int multiplier;
        /** image width.
         */
        int width;
        /** image height
         */
        int height;
        void CreateLine(int x1, int y1, int x2, int y2);
        void CreateLine(int row, int col, bool horizontal);
        SVG(string path, int width, int height);
        /* Finilizes the document where data is saved.
         */
        ~SVG();
};
