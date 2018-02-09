#ifndef POLYGON
#define POLYGON

#include "../line/line.cpp"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <utility>

using namespace std;

class Polygon {
    public:
        Polygon() {

        }

        /* Open a file with the fileName */
        Polygon(char * fileName) {
            FILE *file;
            file = fopen(fileName, "r");

            int x1, y1, x2, y2;
            int numberOfLines;
            fscanf(file, "%d", &numberOfLines);

            for(int i = 0; i < numberOfLines; i++){
                
                fscanf(file, "%d %d %d %d", &x1, &y1, &x2, &y2);
                
                Point p1(x1, y1);
                Point p2(x2, y2);
                Line temp(p1, p2);
                lines.push_back(temp);
            }
            
            // get the max point
            fscanf(file, "%d %d", &x1, &y1);
            topLeft.setAxis(x1);
            topLeft.setOrdinat(y1);
            fscanf(file, "%d %d", &x1, &y1);
            bottomRight.setAxis(x1);
            bottomRight.setOrdinat(y1);
        }

        void print(int divx, int divy, int red, int green, int blue) {
            for(int i = 0; i < lines.size(); i++){
                lines[i].print(divx, divy, red, green, blue);
            }
        }

        // TODO: implement methods
        void scanLine(Line g, int red, int green, int blue) {
            // Make the line from g
            pair<float, float> linearEQ = g.makeLine();
            
            // list of points
            vector<Point> listOfIntersectPoints;
            
            for(int i = 0; i < lines.size(); i++){
                // First, check if the point intersect
                // ....


                // find the intersect
                Line temp = lines[i];
                pair<float, float> tempEQ = temp.makeLine();

                float x = (tempEQ.second - linearEQ.second) / (linearEQ.first - tempEQ.first);
                float y = linearEQ.first * x + linearEQ.second;

                Point tempPoint(x, y);
                listOfIntersectPoints.push_back(tempPoint);
            }

            for(int i = 0; i < listOfIntersectPoints.size(); i++) {
                cout << listOfIntersectPoints[i].getAxis() << " " << listOfIntersectPoints[i].getOrdinat() << endl;
            }


        }

        void rotate(int degree) {
            for(int i = 0;i < lines.size();i++) {
                lines[i].rotate(degree, topLeft, bottomRight);
            }
        }

        void scale(int scale) {
            for(int i = 0;i < lines.size();i++) {
                lines[i].scale(scale, topLeft, bottomRight);
            }
        }

    private:
        vector<Line> lines;
        Point topLeft, bottomRight;
};

#endif