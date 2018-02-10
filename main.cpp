#include <iostream>

#include "polygon/polygon.cpp"

using namespace std;

int main() {
    Polygon polygon((char*)"objects/square.txt");
    
    polygon.print(0, 0, 0, 255, 0);
    polygon.scanLine(150, 0, 150);

    return 0;
}
