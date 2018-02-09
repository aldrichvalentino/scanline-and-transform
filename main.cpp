#include <iostream>

#include "polygon/polygon.cpp"

using namespace std;

int main() {
    Polygon polygon((char*)"objects/square.txt");
    
    Point point1(0,1);
    Point point2(1,1);
    Line line(point1, point2);
    
    polygon.scanLine(line, 0, 0, 0);
    polygon.print(0, 0, 255, 255, 255);

    return 0;
}