#include <iostream>

#include "polygon/polygon.cpp"

using namespace std;

int main() {
    Polygon polygon((char*)"objects/square.txt");
    
    Point point1(100,150);
    Point point2(400,150);
    Line line(point1, point2);
    //line.print(0,0,255,255,255);
    
    polygon.scanLine(line, 0, 0, 0);
    polygon.print(0, 0, 255, 255, 255);

    return 0;
}