#ifndef POLYGON
#define POLYGON

#include "../line/line.cpp"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class Polygon {
    public:
        Polygon() {

        }

        /* Open a file with the fileName */
        Polygon(char * fileName) {
            FILE *file;
            file = fopen(fileName, "r");

            int numberOfLines;
            fscanf(file, "%d", &numberOfLines);

            for(int i = 0; i < numberOfLines; i++){
                int x1, y1, x2, y2;
                fscanf(file, "%d %d %d %d", &x1, &y1, &x2, &y2);
                
                Point p1(x1, y1);
                Point p2(x2, y2);
                Line temp(p1, p2);
                lines.push_back(temp);
            }
        }

        void print() {
            for(int i = 0; i < lines.size(); i++){
                cout << lines[i].getFirstPoint().getAxis() << " " << lines[i].getFirstPoint().getOrdinat() << " "
                    << lines[i].getSecondPoint().getAxis() << " " << lines[i].getSecondPoint().getOrdinat() << endl;
            }
        }

        // TODO: implement methods
        void scanLine(Line g, int red, int green, int blue) {

        }

        void rotate(Point center, int degree) {

        }

        void scale(int scale) {

        }

    private:
        vector<Line> lines;
};

#endif