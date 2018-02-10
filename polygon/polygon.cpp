#ifndef POLYGON
#define POLYGON

#include "../line/line.cpp"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <math.h>
#include <algorithm>

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

        // TODO: make line dependent scan line
        void scanLine(int red, int green, int blue) {
            // make the scan line
            Point scanLineLeft(topLeft.getAxis(), topLeft.getOrdinat());
            int x = bottomRight.getAxis();
            Point scanLineRight(x, topLeft.getOrdinat());
            Line scanLine(scanLineLeft, scanLineRight);
            // cout << "siap siap mau masuk" << endl;
            
            for(int scan = topLeft.getOrdinat(); scan < bottomRight.getOrdinat(); scan++){
                // cout << "masuk loop " << scan << endl;
                // Make the line from scan line
                pair<float, float> linearEQ = scanLine.makeLine();
                
                // list of points
                vector<Point> listOfIntersectPoints;
                
                for(int i = 0; i < lines.size(); i++){
                    // First, check if the point intersect
                    int firstOrdinatLine = scanLine.getFirstPoint().getOrdinat();
                    int secondOrdinatLine = scanLine.getSecondPoint().getOrdinat();
                    int firstOrdinatPolygon = lines[i].getFirstPoint().getOrdinat();
                    int secondOrdinatPolygon = lines[i].getSecondPoint().getOrdinat();
                    
                    if((firstOrdinatLine - firstOrdinatPolygon)*(secondOrdinatLine - secondOrdinatPolygon) <= 0){
                        // find the intersect
                        pair<float, float> tempEQ = lines[i].makeLine();

                        //cout << tempEQ.second << " " << tempEQ.first << endl;
                        if(tempEQ.first == 0){
                            Point tempPoint(lines[i].getFirstPoint().getAxis(), 
                                        scanLine.getFirstPoint().getOrdinat());
                            listOfIntersectPoints.push_back(tempPoint);
                        } else {
                            float x = (tempEQ.second - linearEQ.second) / (linearEQ.first - tempEQ.first);
                            float y = linearEQ.first * x + linearEQ.second;
                            Point tempPoint(x, y);
                            listOfIntersectPoints.push_back(tempPoint);
                        }
                    }
                }

                // sort the points
                if(listOfIntersectPoints.size() != 0){
                    for(int i = 0; i < listOfIntersectPoints.size() - 1; i++) {
                        int smallest = i;
                        for(int j = i+1; j < listOfIntersectPoints.size(); j++){
                            if(listOfIntersectPoints[j].getAxis() < listOfIntersectPoints[smallest].getAxis()){
                                smallest = j;
                            }
                        }
                        Point temp(listOfIntersectPoints[smallest].getAxis(), listOfIntersectPoints[smallest].getOrdinat());
                        listOfIntersectPoints[smallest] = listOfIntersectPoints[i];
                        listOfIntersectPoints[i] = temp;
                    }

                    // delete unusable points, if there are double points
                    for(int i = 0; i < listOfIntersectPoints.size(); i++) {
                        if(listOfIntersectPoints[i].getAxis() == listOfIntersectPoints[i+1].getAxis() &&
                            listOfIntersectPoints[i].getOrdinat() == listOfIntersectPoints[i+1].getOrdinat()){
                                listOfIntersectPoints.erase(listOfIntersectPoints.begin() + i + 1);
                            }
                        i++;
                    }

                    // only color if total point is even
                    if(listOfIntersectPoints.size() > 1){
                        for(int i = 0; i < listOfIntersectPoints.size(); i++) {
                            // don't color the border
                            listOfIntersectPoints[i].setAxis(listOfIntersectPoints[i].getAxis()+1);
                            listOfIntersectPoints[i+1].setAxis(listOfIntersectPoints[i+1].getAxis()-1);

                            Line line(listOfIntersectPoints[i], listOfIntersectPoints[i+1]);
                            line.print(0,0, 255, 255, 255);

                            i++;
                        }
                    }
                }
                
                scanLineLeft.setOrdinat(scanLineLeft.getOrdinat() + 1);
                scanLineRight.setOrdinat(scanLineRight.getOrdinat() + 1);
                // move the scan line down
                scanLine.setFirstPoint(scanLineLeft);
                scanLine.setSecondPoint(scanLineRight);
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

        void update(int x, int y) {
            topLeft.update(x, y);
            bottomRight.update(x, y);
            for(int i = 0; i < lines.size(); i++){
                lines[i].update(x, y);
            }
        }

    private:
        vector<Line> lines;
        Point topLeft, bottomRight;
};

#endif