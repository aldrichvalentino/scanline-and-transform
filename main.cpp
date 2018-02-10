#include <iostream>

#include "polygon/polygon.cpp"

using namespace std;

int main() {
    Polygon polygon((char*)"objects/square.txt");
    
    polygon.scale(2);

    //for(int i = 0; i < 100; i++){
        polygon.scanLine(150, 0, 150);
        polygon.print(0, 0, 0, 255, 0);
        //polygon.scale(2);
        polygon.update(1, 1);
    //}
    
    return 0;
}
