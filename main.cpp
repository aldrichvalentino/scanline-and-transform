#include <iostream>

#include "polygon/polygon.cpp"

using namespace std;

int main() {
    Polygon polygon((char*)"objects/square.txt");
    
    polygon.scanLine(150, 0, 150);
    polygon.print(0, 0, 0, 255, 0);
    
    return 0;
}
