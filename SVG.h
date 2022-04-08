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
        /** Create a line specified by two points.
         * @param x1 - x coordinate for the first point
         * @param y1 - y coordinate for the first point
         * @param x2 - x coordinate for the second point
         * @param y2 - y coordinate for the second point
         */
        void CreateLine(int x1, int y1, int x2, int y2);
        /** Create a line specified by one point and orientation.
         * @param x1 - x coordinate for the point
         * @param y1 - y coordinate for the point
         */
        void CreateLine(int row, int col, bool horizontal);
        SVG(string path, int width, int height);
        /* Finilizes the document where data is saved.
         */
        ~SVG();
};
